#include <stdio.h>
#include "poli.h"

LinkedList *scanPolinomio(LinkedList *l);
LinkedList *scanConstante(LinkedList *l);

int main (int argc, char **argv) {

    LinkedList *all = NULL;
    
    int flag = 0;

    printf("Inserir polinómio?\n0. Não\n1. Sim\n");
    scanf("%d", &flag);
    if(flag) all = scanPolinomio(all);

    printf("Inserir constante?\n0. Não\n1. Sim\n");
    scanf("%d", &flag);
    if(flag) all = scanConstante(all);


    return 0;
}

LinkedList *scanPolinomio(LinkedList *l) {
    int more = 0;
    do {
        float coe = 0.0;
        char var[VARSIZE];
        int exp = 0;
        printf("Coeficiente: ");
        scanf("%f", &coe);
        printf("Variável: ");
        scanf("%s", var);
        printf("Expoente: ");
        scanf("%d", &exp);
        
        l = makeList(makePoly(coe, var, exp), NULL);
        l = l->next;

        printf("Há mais?\n0. Não\n1. Sim\n");
        scanf("%d", &more);
    } while(more);    
    return l;
}

LinkedList *scanConstante(LinkedList *l) {
    int more = 0;
    do {
        int i = 0;
        printf("Constante: ");
        scanf("%d", &i);

        l = makeList(makeCons(i), NULL);
        l = l->next;

        printf("Há mais?\n0. Não\n1. Sim\n");
        scanf("%d", &more);        
    } while(more);
    return l;   
}