#include <stdlib.h>
#include <string.h>
#include "poli.h"


Polinomio *makeCons(int cons);                          //cria constante
Polinomio *makePoly(float coe, char *var, int exp);     //cria polinomio
LinkedList *makeList(Polinomio *pol, LinkedList *next); //cria lista com os polinómios


Polinomio *makeCons(int cons) {
    Polinomio *node = (Polinomio*) malloc(sizeof(Polinomio));
    node->kind = CONS;
    node->pols.cons = cons;
    return node;
}

Polinomio *makePoly(float coe, char *var, int exp) {
    Polinomio *node = (Polinomio*) malloc(sizeof(Polinomio));
    node->kind = POLI;
    node->pols.pol.coe = coe;
    memcpy(node->pols.pol.var, var, VARSIZE);
    node->pols.pol.exp = exp;
    node->pols.pol.visited = false;
    return node;
}

LinkedList *makeList(Polinomio *pol, LinkedList *next) {
    LinkedList *node = (LinkedList*) malloc(sizeof(LinkedList));
    node->pol = pol;
    node->next = next;
    return node;
}