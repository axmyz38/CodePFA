//

// #define GRAPHIC

#define PFA_C

#include "pfa.h"

static double global_x;
static InsuredClient* global_client;

/* Initialize the integration variables.
   Arguments :
   - quadrature : name of the quadrature formula that will be used. It can be "left", "right", 
     "middle", "trapezes", "simpson", "gauss2" or "gauss3".
   - dt : a positive value, which will be used to decide the number of subdivisions of an 
          interval [a,b], when computing the integration.
          The number of subdivisions will be N such that (b-a)/N ~ dt
*/
bool init_integration(char* quadrature, double dt)
{ 
	if (!setQuadFormula (&pfaQF, quadrature))
		return false;
	pfa_dt = dt;
	return true;
}



/* Density of the normal distribution */
double phi(double x)
{
  return 0.398942280401433 * exp( -x*x/2 );
}

/* Cumulative distribution function of the normal distribution */
double PHI(double x)
{
  return 1.0/2.0 + integrate_dx(phi, 0, x, pfa_dt, &pfaQF);
}

/* =====================================
   Finance function: price of an option 
*/
double optionPrice(Option* option)
{
  double z0 = (log(option->K / option->S0) - (option->mu - option->sig * option->sig / 2) * option->T) / (option->sig * sqrt(option->T));
  double C = option->S0 * exp(option->mu * option->T) * PHI(option->sig * sqrt(option->T) - z0) - option->K * PHI(-z0);
  double P = option->K * PHI(z0) - option->S0 * exp(option->mu * option->T) * PHI(z0 - option->sig * sqrt(option->T));

  if (option->type == CALL)
    return C;
  else
    return P;

}



/* ===============================================*/
/* Insurance functions */

/* Probability density function (PDF) of variable X.
   X is the reimbursement in case of a claim from the client.
*/
double clientPDF_X(InsuredClient* client, double x)
{
  if(x <= 0)
    return 0.0;
  
  double taclar = phi((log(x)-client->m)/client->s);
  return (1.0/(x*client->s))*taclar;
}


/* Cumulative distribution function (CDF) of variable X.
   X is the reimbursement in case of a claim from the client.
*/

double clientCDF_X(InsuredClient* client, double x)
{
    if (x <= 0){
    return 0.0;
  }
  else{
    double tacklar = PHI((log(x)-client->m)/client->s);
    return tacklar;
  }
}


/* Probability density function (PDF) of variable X1+X2.
   X1 and X2 are the reimbursements of the two claims from the client (assuming there are 
   two claims).
*/

double integrand_X1X2(double t)
{
  if (t == global_x || t == 0)
    return 0.0;
  return clientPDF_X(global_client, t) * clientPDF_X(global_client, global_x - t);

}

double clientPDF_X1X2(InsuredClient* client, double x)
{
  global_x = x;
  global_client = client;
  if (global_x<=0)
      return 0;
  return integrate_dx(integrand_X1X2, 0, x, pfa_dt, &pfaQF);
    

}


/* Cumulative distribution function (CDF) of variable X1+X2.
   X1 and X2 are the reimbursements of the two claims from the client (assuming there are 
   two claims).
*/
double integrand_CDF_X1X2(double t)
{
   return clientPDF_X1X2(global_client, t);
}


double clientCDF_X1X2(InsuredClient* client, double x)
{
  
  global_client = client;
  if (x<=0)
      return 0;
  return integrate_dx(integrand_CDF_X1X2, 0, x, pfa_dt, &pfaQF );
}



/* Cumulative distribution function (CDF) of variable S.
   Variable S is the sum of the reimbursements that the insurance company will pay to client.
*/
double clientCDF_S(InsuredClient* client, double x)
{
  if (x < 0)
      return 0.0;
  if (x == 0)
      return client->p[0];
  return client->p[0] + client->p[1]*clientCDF_X(client, x) + client->p[2]*clientCDF_X1X2(client, x);

}




