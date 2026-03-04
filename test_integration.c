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

void error(int *arr, char **arr2, double (*f)(double), double a , double b,int size)
{
  QuadFormula qf;
  printf("a = %f, b = %f\n", a, b);
	for (int i = 0; i < 7; i++)
  {
	  setQuadFormula(&qf, arr2[i]);
	  printf("------------------------------------------------------------\n%s :\n ", arr2[i]);
	  for (int y = 0; y < size; y++)
	  {
printf("--------\nN = %d :\n",arr[y]);
    printf("approx = %f | exact = %f\n", integrate(f, a, b, arr[y], &qf), sin(b)-sin(a));
  printf("difference entre le modele et la solution connue a 10 puissance -10: \n %.10f\n", fabs(integrate(f, a, b, arr[y], &qf)-(sin(b)-sin(a))));
    printf("ln(N)=%f | ln(erreur)=%f\n", log(arr[y]), log(fabs(integrate(f, a, b, arr[y], &qf)-(sin(b)-sin(a)))));
}
}
}
int main(int argc, char *argv[])
{
  /*QuadFormula qf;
  double I1, I2, I3;
  printf("---------------------------------------------------------------\n");
  printf("integration : \nN = 10, a = trapezes, b = middle, c = left, d = right\n");
  setQuadFormula(&qf, "trapezes");
  printf("a : %f\n",integrate(f, -1, 4, 10, &qf));
    setQuadFormula(&qf, "middle");
   printf("b : %f\n",integrate(f, -1, 4, 10, &qf));
    setQuadFormula(&qf, "left");
  printf("c : %f\n",integrate(f, -1, 4, 10, &qf));
  setQuadFormula(&qf, "right");
   printf("d : %f\n",integrate(f, -1, 4, 10, &qf));
   printf("\n");
  printf("N = 100, a = trapezes, b = middle, c = left, d = right\n");
setQuadFormula(&qf, "trapezes");
  printf("a : %f\n",integrate(f, -1, 4, 100, &qf));
    setQuadFormula(&qf, "middle");
  printf("b : %f\n",integrate(f, -1, 4, 100, &qf));
  setQuadFormula(&qf, "left");
 printf("c : %f\n",integrate(f, -1, 4, 100, &qf));
  setQuadFormula(&qf, "right");
  printf("d : %f\n",integrate(f, -1, 4, 100, &qf));
  printf("\nleft et right moin performant, remplace par simpson, gauss2 et gauss3\n");
  printf("N = 1000, a = trapezes, b = middle, c = simpson, d = gauss2 , e = gauus3\n");
setQuadFormula(&qf, "trapezes");
  printf("a : %f\n",integrate(f, -1, 4, 1000, &qf));
   setQuadFormula(&qf, "middle");
  printf("b : %f\n",integrate(f, -1, 4, 1000, &qf));
  setQuadFormula(&qf, "simpson");
  printf("c : %f\n",integrate(f, -1, 4, 1000, &qf));
    setQuadFormula(&qf, "gauss2");
  printf("d : %f\n",integrate(f, -1, 4, 1000, &qf));
  setQuadFormula(&qf, "gauss3");
  printf("e : %f\n",integrate(f, -1, 4, 1000, &qf));
printf("---------------------------------------------------------------\n");
  printf("integradtion dx :\n a = trapezes, b = simpson, c = gauss2, d = gauss3\n");
    setQuadFormula(&qf, "trapezes");
  printf("a : %f\n",integrate_dx(f, -1, 4, 0.1, &qf));
  setQuadFormula(&qf, "simpson");
  printf("b : %f\n",integrate_dx(f, -1, 4, 0.1, &qf));
setQuadFormula(&qf, "gauss2");
  printf("c : %f\n",integrate_dx(f, -1, 4, 0.1, &qf));
setQuadFormula(&qf, "gauss3");
  printf("d : %f\n",integrate_dx(f, -1, 4, 0.1, &qf));
  printf("----------------------------------------------------------------\nfct error avec la fonction cos (x) avec gauss3 :\n ");
*/ int arr[] = {10, 100, 1000};
char *arr2[] = {"right", "left", "trapezes", "middle", "simpson", "gauss2", "gauss3"};
 size_t size = 3;
  error(arr, arr2,f, -1, 4, size);
  return EXIT_SUCCESS;
}

// Code here everything you need to test the integration methods and show your numericzal results */
//void error(int *arr, double (*f)(double), double a , double b,QuadFormula* qf,int size)
//{
//  for (int i = 0; i < size; i++)
//{
//  printf("%f\n", fabs(integrate(f, a, b, arr[i], qf)-(sin(1.0/3.0*(b*b*b)-sin(1.0/3.0*(a*a*a))));
//}
//}

