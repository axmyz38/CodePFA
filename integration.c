



#define INTEGRATION_C

#include "integration.h"

bool setQuadFormula(QuadFormula* qf, char* name)
{
  	if (name == NULL)
		return false;
	if(strcmp(name,"right") == 0)
	{
		strcpy(qf -> name , "right");
		qf -> n = 1;
		qf -> w[0] = 1.0;
		qf -> x[0] = 0.0;
		return true;
	}
	if(strcmp(name,"left")==0)
	{
		strcpy(qf -> name , "left");
		qf -> n = 1;
		qf -> w[0] = 1.0;
		qf -> x[0] = 0.0;
		return true;
	}
	if(strcmp(name,"middle")==0)
	{
		strcpy(qf -> name , "middle");
		qf -> n = 1;
		qf -> w[0] = 1.0;
		qf -> x[0] = 0.5;
		return true;
	}
	if(strcmp(name,"trapezes")== 0)
	{
		strcpy(qf -> name, "trapezes");
		qf -> n = 2;
		qf -> w[0] = 0.5;
		qf -> w[1] = 0.5;
		qf -> x[0] = 0.0;
		qf -> x[1] = 1.0;
		return true;
	}
  if (strcmp(name,"simpson")==0)
  {
    strcpy(qf->name,"simpson");
    qf->n = 3;
    qf->x[0] = 0.0;
    qf->w[0] = 1.0/6.0;
    qf->x[1] = 0.5;
    qf->w[1] = 2.0/3.0;
    qf->x[2] = 1.0;
    qf->w[2] = 1.0/6.0;
    return true;

  }

  if (strcmp(name,"gauss2")==0)
  {
    strcpy(qf->name, "gauss2");
    qf->n = 2;
    qf->x[0] = 0.5 - 0.5/sqrt(3);
    qf->w[0] = 0.5;
    qf->x[1] = 0.5 + 0.5/sqrt(3);
    qf->w[1] = 0.5;
    return true;
  }
  if (strcmp(name,"gauss3")==0)
  {
    strcpy(qf->name, "gauss3");
    qf->n = 3;
    qf->x[0] = 0.5*(1.0-sqrt(3.0/5.0));
    qf->w[0] = 5.0/18.0;
    qf->x[1] = 0.5;
    qf->w[1] = 4.0/9.0;
    qf->x[2] = 0.5*(1.0+sqrt(3.0/5.0));
    qf->w[2] = 5.0/18.0;
    return true;

  }
	return false;
}

/* This function is not required ,but it may useful to debug */
void printQuadFormula(QuadFormula* qf)
{
  printf("Quadratic formula: %s\n", qf->name);
  /* Print everything else that may be useful */
}


/* Approximate the integral of function f from a to b.
   - f is a pointer to a function pointer
   - a and b are the integration bounds
   - Interval [a,b] is split in N subdivisions [ai,bi]
   - Integral of f on each subdivision [ai,bi] is approximated by the quadrature formula qf.
*/
double integrate(double (*f)(double), double a, double b, int N, QuadFormula* qf)
{
  if (f == NULL)
		return 0.0;
  if (N == 0)
  {
    return 0.0;
  }
  double sum = 0.0;
  double ai = 0.0;
  double bi = 0.0;
  double result = 0.0;
  for (int i = 0; i <= N-1; i++)
  {
    ai = a+i*(b-a)/N;
    bi = a+(i+1)*(b-a)/N;
    for (int y = 0; y <= (qf-> n) - 1; y++)
    {
      sum += qf->w[y] * f(ai + (qf->x[y])*(bi-ai));
     
    }
    result += (bi-ai) * sum;
    sum = 0.0;
  }
  return result;
}




double integrate_dx(double (*f)(double), double a, double b, double dx, QuadFormula* qf)
{
  if (f == NULL)
    return 0.0;
  int N = round(fabs(b-a)/dx);
  if (N==0)
    N=1;
  return integrate(f, a, b, N, qf); 
}


