



#define INTEGRATION_C

#include "integration.h"

bool setQuadFormula(QuadFormula* qf, char* name)
{
  	if (name == NULL)
		return False;
	if(name == "right")
	{
		qf -> name = "right";
		qf -> n = 0;
		qf -> w0 = 1;
		qf -> x0 = 1;
		return true;
	}
	if(name == "left")
	{
		qf -> name = "left";
		qf -> n = 0;
		qf -> w0 = 1;
		qf -> x0 = 0;
		return true;
	}
	if(name == "middle")
	{
		qf -> name = "middle";
		qf -> n = 0;
		qf -> w0 = 1;
		qf -> x0 = 1/2;
		return true;
	}
	if( name == "trapezes")
	{
		qf -> name = "trapezes";
		qf -> n = 1;
		qf -> w0 = 1/2;
		qf -> w1 = 1/2;
		qf -> x0 = 0;
		qf -> x1 = 1;
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
	int i = 0;
  size_t sum = 0;
  while (i != N)
  {
    doucle ai = a + i*(b-a)/N;
    double bi = a + (i+1)*(b-a)/N;
    for (int j = 0; j <= n; j++)
    {
      sum += wk[k]*f(ai+x[k]*(bi-ai));
    }
    result += (bi-ai)*sum;

  }
  return result;
}

	

	return 0.0;
}

double integrate_dx(double (*f)(double), double a, double b, double dx, QuadFormula* qf)
{
  return 0.0;
}


