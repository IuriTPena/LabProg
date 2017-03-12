#include <stdlib.h>
#include <string.h>
#include "poli.h"

Monomio *makeCons(int cons) {
    Monomio *node = (Monomio*) malloc(sizeof(Monomio));
    node->kind = CONS;
    node->monos.cons = cons;
    return node;
}

Monomio *makeMono(float coe, char *var, int exp) {
    Monomio *node = (Monomio*) malloc(sizeof(Monomio));
    node->kind = MONO;
    node->monos.mono.coe = coe;
    memcpy(node->monos.mono.var, var, VARSIZE);
    node->monos.mono.exp = exp;
    node->monos.mono.visited = false;
    return node;
}

LinkedList *makeList(Monomio *mon, LinkedList *next) {
    LinkedList *node = (LinkedList*) malloc(sizeof(LinkedList));
    node->mon = mon;
    node->next = next;
    return node;
}