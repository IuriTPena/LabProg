#include <stdlib.h>
#include "poli.h"

Polinomio *makeCons(char *op, int coe);
Polinomio *makePoly(char *op, int coe, int exp, char *var);
LinkedList *makeList(Polinomio *pol, LinkedList *next);


Polinomio *makeCons(char *op, int coe) {
    Polinomio *node = (Polinomio*) malloc(sizeof(Polinomio));
    node->kind = CONS;
    node->pols.pol.op = op;
    node->pols.pol.coe = coe;
    return node;
}

Polinomio *makePoly(char *op, int coe, int exp, char *var) {
    Polinomio *node = (Polinomio*) malloc(sizeof(Polinomio));
    node->kind = POLI;
    node->pols.pol.op = op;
    node->pols.pol.coe = coe;
    node->pols.pol.exp = exp;
    node->pols.pol.var = var;
    return node;
}

LinkedList *makeList(Polinomio *pol, LinkedList *next) {
    LinkedList *node = (LinkedList*) malloc(sizeof(LinkedList));
    node->pol = pol;
    node->next = next;
    return node;
}
