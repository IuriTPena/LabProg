#ifndef __poli_h__
#define __poli_h__

typedef struct _Polinomio Polinomio;
typedef struct _LinkedList LinkedList;

struct _Polinomio {
    enum { CONS, POLI } kind;
    union {
        struct {
            char *op;
            int cons;
        } con;
        struct {
            char *op;
            int coe;
            int exp;
            char *var;
        } pol;
    } pols;
};

struct _LinkedList {
    Polinomio *pol;
    LinkedList *next;
};


#endif