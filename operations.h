#ifndef __operations_h__
#define __operations_h__

#include "poli.h"

int printPolinomio(LinkedList *l);
int printIntegrar(LinkedList *l, char *var);
LinkedList *delete(LinkedList *head, LinkedList *del);
LinkedList *append(LinkedList *l1, LinkedList *l2);
LinkedList *normalizar(LinkedList *l);
LinkedList *somar(LinkedList *n1, LinkedList *n2);
LinkedList *derivar(LinkedList *l);
int integrar(LinkedList *l);

#endif