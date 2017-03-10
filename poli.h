#ifndef __poli_h__
#define __poli_h__

typedef struct _Polinomio Polinomio;
typedef struct _LinkedList LinkedList;

struct _Polinomio {
    enum { CONS, POLI } kind;
    union {
        int cons;
        struct {
            float coe;
            int exp;
            char *var;
            bool visited;
        } pol;
    } pols;
};

struct _LinkedList {
    Polinomio *pol;
    LinkedList *next;
};

Polinomio *makeCons(int cons);
Polinomio *makePoly(float coe, int exp, char *var);
LinkedList *makeList(Polinomio *pol, LinkedList *next);

#endif