#include <stdio.h>
#include "operations.h"

int printPolinomio(LinkedList *l);
LinkedList *scanMonomio(LinkedList *l);
LinkedList *scanConstante(LinkedList *l);

int main (int argc, char **argv) {

    LinkedList *all = NULL;
    LinkedList *head = all;
    
    int flag = 0;
    printf("Inserir mononómio?\n0. Não\n1. Sim\n");
    scanf("%d", &flag);
    if(flag) all = scanMonomio(all);

    printf("Inserir constante?\n0. Não\n1. Sim\n");
    scanf("%d", &flag);
    if(flag) all = scanConstante(all);

    int oper;
    printf("Escolha as operações\n0. Imprimir\n1. Normalizar\n2. Somar\n3. Derivar\n4. Integrar\n");
    scanf("%d", &oper);
    switch (oper) {
        case 0: printPolinomio(head); break;
      /*  case 1: normalizar(head); break;
        case 2: somar(head); break;
        case 3: derivar(head); break;
        case 4: integrar(head); break;*/
        default: printf("A sério? Entre 0 e 4, inclusivé. Não é rocket science!");
    }

    return 0;
}

int printPolinomio(LinkedList *l) {
    while(l) {
        if(l->mon->kind == MONO) {
            printf("works");
        }
        else {
            printf("%d", l->mon->monos.cons); 
        }
        l=l->next;
    }

    return 0;
}

LinkedList *scanMonomio() {
	LinkedList *l = NULL;
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
        
        l = makeList(makeMono(coe, var, exp), l);
        //l = l->next;

        printf("Há mais?\n0. Não\n1. Sim\n");
        scanf("%d", &more);
    } while(more);    
    return l;
}

LinkedList *scanConstante() {
    LinkedList *l = NULL;
    int more = 0;
    do {
        int i = 0;
        printf("Constante: ");
        scanf("%d", &i);

        l = makeList(makeCons(i), l);
        //l = l->next;

        printf("Há mais?\n0. Não\n1. Sim\n");
        scanf("%d", &more);        
    } while(more);
    return l;   
}