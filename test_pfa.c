/******************************************************/
/* Program to run and test the integration functions. */
/* Creation date: 31 July, 2025                       */
/******************************************************/
#include "pfa.h"
#include <stdio.h>
#include <math.h>
#include "integration.h"

/* Code here anything you want to test your pfa functions and to show your numerical results */
int main()
{
  if (!init_integration("simpson", 1.0)) {
        printf("Erreur d'initialisation de l'integration.\n");
        return 1;
    }

    printf("=== PARTIE 1 : FINANCE (Options) ===\n");
    
    Option call_opt;
    call_opt.type = CALL;
    call_opt.S0 = 100.0;
    call_opt.K = 105.0;
    call_opt.T = 1.0;
    call_opt.mu = 0.05;
    call_opt.sig = 0.2;

    Option put_opt = call_opt;
    put_opt.type = PUT;

    double prix_call = optionPrice(&call_opt);
    double prix_put = optionPrice(&put_opt);

    printf("Parametres de l'option : S0=%.2f, K=%.2f, T=%.2f, mu=%.2f, sig=%.2f\n", 
           call_opt.S0, call_opt.K, call_opt.T, call_opt.mu, call_opt.sig);
    printf("Prix du CALL : %f euros\n", prix_call);
    printf("Prix du PUT  : %f euros\n\n", prix_put);


    printf("=== PARTIE 2 : ASSURANCE (Sinistres) ===\n");

    double probas[3] = {0.80, 0.15, 0.05};
    InsuredClient client;
    client.m = 6.0;
    client.s = 0.8;
    client.p = probas;

    printf("Parametres client : m=%.2f, s=%.2f, p0=%.2f, p1=%.2f, p2=%.2f\n", 
           client.m, client.s, client.p[0], client.p[1], client.p[2]);

    double montants_test[] = {500.0, 1000.0, 3000.0, 5000.0, 10000.0};
    int nb_tests = 5;

    for (int i = 0; i < nb_tests; i++) {
        double x = montants_test[i];
        double proba_S = clientCDF_S(&client, x);
        printf("Probabilite que le remboursement total soit <= %.2f euros : %f (soit %.2f%%)\n", 
               x, proba_S, proba_S * 100.0);
    }

    return 0;
 
}
