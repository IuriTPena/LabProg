#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

LinkedList *scanPolinomio();
Monomio *scanConstante();
Monomio *scanMonomio();

int main (int argc, char **argv) {

    //int nPol = 1;
    LinkedList *p = NULL;
    p = scanPolinomio();

    int oper;
 /*   if(nPol > 1)
        printf("Escolha as operações\n0. Imprimir\n1. Somar\n");
    else
*/        printf("Escolha as operações\n0. Imprimir\n1. Normalizar\n2. Derivar\n3. Integrar\n");

    scanf("%d", &oper);
 
    switch (oper) {
        case 0: printPolinomio(p); break;
        case 1: normalizar(p); break;
      //  case 2: somar(something); break;
        case 3: derivar(p); break;
        case 4: integrar(p); break;
        default: printf("A sério? Entre 0 e 4, inclusivé. Não é rocket science!");
    }

    return 0;
}

LinkedList *scanPolinomio() {
	LinkedList *l = NULL;
    
    int nMono = 0;
    printf("Nº de monómios a inserir: ");  
    scanf("%d", &nMono);

    while(nMono-- > 0)
        l = makeList(scanMonomio(), l);


    int nCons = 0;
    printf("Nº de constantes a inserir: ");    
    scanf("%d", &nCons);

    while(nCons-- > 0)
        l = makeList(scanConstante(), l);

    return l;
}

Monomio *scanMonomio() {
    Monomio *l = NULL;

    float coe = 0.0;
    char *var = malloc(sizeof(char));
    int exp = 0;
    printf("Coeficiente: ");
    scanf("%f", &coe);
    printf("Variável: ");
    scanf("%s", var);
    printf("Expoente: ");
    scanf("%d", &exp);
        
    l = makeMono(coe, var, exp);

    return l;
}

Monomio *scanConstante() {
    Monomio *l = NULL;

    int i = 0;
    printf("Constante: ");
    scanf("%d", &i);

    l = makeCons(i);

    return l;   
}