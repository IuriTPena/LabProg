#ifndef __poli_h__
#define __poli_h__

#include <stdbool.h>

typedef struct _Monomio Monomio;
typedef struct _LinkedList LinkedList;

struct _Monomio {
    enum { CONS, MONO } kind;
    union {
        int cons;
        struct {
            float coe;
            char *var;
            int exp;
            bool visited;
        } mono;
    } monos;
};

struct _LinkedList {
    Monomio *mon;
    LinkedList *next;
};

Monomio *makeCons(int cons);
Monomio *makeMono(float coe, char *var, int exp);
LinkedList *makeList(Monomio *mono, LinkedList *next);


void setVisited(LinkedList *l);
void setVar(LinkedList *l, char *c);
void setCoe(LinkedList *l, int coe);
void setExp(LinkedList *l, int exp);
void setCons(LinkedList *l, int cons);
char getKind(LinkedList *l);
bool isVisited(LinkedList *l);
char *getVar(LinkedList *l);
int getCoe(LinkedList *l);
int getExp(LinkedList *l);
int getCons(LinkedList *l);

#endif