/******************************************************/
/* Program to run and test the integration functions. */
/* Creation date: 31 July, 2025                       */
/******************************************************/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "integration.h"


double f(double t)
{
  return cos(t);
}

void error(int *arr, double (*f)(double), double a , double b,QuadFormula* qf,int size)
{
  for (int i = 0; i < size; i++)
{
    printf("------------------------------------------------------------\n");
    printf("approx = %f | exact = %f\n", integrate(f, a, b, arr[i], qf), sin(b)-sin(a));
  printf("difference entre le modele et la solution connue a 10 puissance -10: \n %.10f\n", fabs(integrate(f, a, b, arr[i], qf)-(sin(b)-sin(a))));
    printf("ln(N)=%f | ln(erreur)=%f\n", log(arr[i]), log(fabs(integrate(f, a, b, arr[i], qf)-(sin(b)-sin(a)))));
}
}

int main(int argc, char *argv[])
{
  QuadFormula qf;
  double I1, I2, I3;
  printf("integration : \nN = 5, trapezes, middle, left, right\n");
  setQuadFormula(&qf, "trapezes");
  printf("%f\n",integrate(f, -1, 4, 5, &qf));
    setQuadFormula(&qf, "middle");
   printf("%f\n",integrate(f, -1, 4, 5, &qf));
    setQuadFormula(&qf, "left");
  printf("%f\n",integrate(f, -1, 4, 5, &qf));
  setQuadFormula(&qf, "right");
   printf("%f\n",integrate(f, -1, 4, 5, &qf));
  printf("N = 10, trapezes, middle, left, right\n");
setQuadFormula(&qf, "trapezes");
  printf("%f\n",integrate(f, -1, 4, 10, &qf));
    setQuadFormula(&qf, "middle");
  printf("%f\n",integrate(f, -1, 4, 10, &qf));
  setQuadFormula(&qf, "left");
 printf("%f\n",integrate(f, -1, 4, 10, &qf));
  setQuadFormula(&qf, "right");
  printf("%f\n",integrate(f, -1, 4, 10, &qf));
  printf("N = 20, trapezes, middle\n");
setQuadFormula(&qf, "trapezes");
  printf("%f\n",integrate(f, -1, 4, 20, &qf));
   setQuadFormula(&qf, "middle");
  printf("%f\n",integrate(f, -1, 4, 20, &qf));
  setQuadFormula(&qf, "simpson");
  printf("%f\n",integrate(f, -1, 4, 20, &qf));
    setQuadFormula(&qf, "gauss2");
  printf("%f\n",integrate(f, -1, 4, 20, &qf));
  setQuadFormula(&qf, "gauss3");
  printf("%f\n",integrate(f, -1, 4, 20, &qf));

  printf("integradtion dx :\n trapezes, simpson, gauss2, gauss3\n");
    setQuadFormula(&qf, "trapezes");
  printf("%f\n",integrate_dx(f, -1, 4, 0.1, &qf));
  setQuadFormula(&qf, "simpson");
  printf("%f\n",integrate_dx(f, -1, 4, 0.1, &qf));
setQuadFormula(&qf, "gauss2");
  printf("%f\n",integrate_dx(f, -1, 4, 0.1, &qf));
setQuadFormula(&qf, "gauss3");
  printf("%f\n",integrate_dx(f, -1, 4, 0.1, &qf));
  printf("fct error:\n ");
int arr[] = {5, 10, 20};
 size_t size = 3;
  error(arr,f, -1, 4, &qf, size);
  return EXIT_SUCCESS;
}

/* Code here everything you need to test the integration methods and show your numericzal results */
//void error(int *arr, double (*f)(double), double a , double b,QuadFormula* qf,int size)
//{
//  for (int i = 0; i < size; i++)
//{
//  printf("%f\n", fabs(integrate(f, a, b, arr[i], qf)-(sin(1.0/3.0*(b*b*b)-sin(1.0/3.0*(a*a*a))));
//}
//}

