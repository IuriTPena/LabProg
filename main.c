#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

int printPolinomio(LinkedList *l);
LinkedList *scanPolinomio();
LinkedList *scanConstante();
LinkedList *scanMonomio();

int main (int argc, char **argv) {

    LinkedList *p = NULL;
    p = scanPolinomio();

    int oper;
    printf("Escolha as operações\n0. Imprimir\n1. Normalizar\n2. Somar\n3. Derivar\n4. Integrar\n");
    scanf("%d", &oper);
    switch (oper) {
        case 0: printPolinomio(p); break;
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
        if(getKind(l) == MONO) {
            printf("%d%s^%d ", getCoe(l), getVar(l), getExp(l));
        }
        else {
            printf("%d ", getCons(l)); 
        }
        l=l->next;
    }

    return 0;
}

LinkedList *scanPolinomio() {
	LinkedList *l = NULL;
    
    int nMono = 0;
    printf("Nº de monómios a inserir: ");  
    scanf("%d", &nMono);

    while(nMono-- > 0)
        l = scanMonomio();


    int nCons = 0;
    printf("Nº de constantes a inserir: ");    
    scanf("%d", &nCons);

    while(nCons-- > 0)
        l = scanConstante();

    return l;
}

LinkedList *scanMonomio() {
    LinkedList *l = NULL;

    float coe = 0.0;
    char *var = malloc(sizeof(char));
    int exp = 0;
    printf("Coeficiente: ");
    scanf("%f", &coe);
    printf("Variável: ");
    scanf("%s", var);
    printf("Expoente: ");
    scanf("%d", &exp);
        
    l = makeList(makeMono(coe, var, exp), l);

    return l;
}

LinkedList *scanConstante() {
    LinkedList *l = NULL;

    int i = 0;
    printf("Constante: ");
    scanf("%d", &i);

    l = makeList(makeCons(i), l);

    return l;   
}