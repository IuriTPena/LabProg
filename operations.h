#ifndef __operations_h__
#define __operations_h__

#include "poli.h"

int printPolinomio(LinkedList *l);
int printIntegrar(LinkedList *l, char *var);
LinkedList *delete(LinkedList *head, LinkedList *del);
LinkedList *append(LinkedList *l1, LinkedList *l2);
LinkedList *normalizar(LinkedList *l);
int somar(LinkedList *n1, LinkedList *n2);
int derivar(LinkedList *l);
int integrar(LinkedList *l);

#endif