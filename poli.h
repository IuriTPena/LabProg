#ifndef __poli_h__
#define __poli_h__
#include <stdbool.h>


typedef struct _Polinomio Polinomio;
typedef struct _LinkedList LinkedList;

struct _Polinomio {
    enum { CONS, POLI } kind;
    union {
        int cons;
        struct {
            float coe;
            char *var;
            int exp;
            bool visited;
        } pol;
    } pols;
};

struct _LinkedList {
    Polinomio *pol;
    LinkedList *next;
};

Polinomio *makeCons(int cons);
Polinomio *makePoly(float coe, char *var, int exp);
LinkedList *makeList(Polinomio *pol, LinkedList *next);

#endif