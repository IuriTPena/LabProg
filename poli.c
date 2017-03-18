#include <stdlib.h>
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
    node->monos.mono.var = var;   
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

void setVisited(LinkedList *l) {
    l->mon->monos.mono.visited = true;
}

void setVar(LinkedList *l, char *var) {
    l->mon->monos.mono.var = var;
}

void setCoe(LinkedList *l, float coe) {
    l->mon->monos.mono.coe = coe;
}

void setExp(LinkedList *l, int exp) {
    l->mon->monos.mono.exp = exp;
}

void setCons(LinkedList *l, int cons) {
    l->mon->monos.cons = cons;
}

char getKind(LinkedList *l) {
    return l->mon->kind;
}

bool isVisited(LinkedList *l) {
    if(l->mon->monos.mono.visited) return true;
    else return false;
}

char *getVar(LinkedList *l) {
    return l->mon->monos.mono.var;
}

float getCoe(LinkedList *l) {
    return l->mon->monos.mono.coe;
}

int getExp(LinkedList *l) {
    return l->mon->monos.mono.exp;
}

int getCons(LinkedList *l) {
    return l->mon->monos.cons;
}