#ifndef __poli_h__
#define __poli_h__

#include <stdbool.h>

#define VARSIZE 10

typedef struct _Monomio Monomio;
typedef struct _LinkedList LinkedList;

struct _Monomio {
    enum { CONS, MONO } kind;
    union {
        int cons;
        struct {
            float coe;
            char var[VARSIZE];
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

#endif