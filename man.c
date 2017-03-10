#include <stdio.h>
#include "poli.h"

int main (int argc, char **argv) {

    LinkedList *all = NULL;

    printf("Inserir polinómio\n");
    int more = 0;
    do {
        float coe = 0.0;
        char *var;
        int exp = 0;
        printf("Coeficiente: ");
        scanf("%f", &coe);
        printf("Variável: ");
        scanf("%s", var);
        printf("Expoente: ");
        scanf("%d", &exp);
        
        all = makeList(makePoly(coe, var, exp), NULL);
        all = all->next;

        printf("Há mais?\n0. Não\n1. Sim\n");
        scanf("%d", &more);
    } while(more);

    return 0;
}