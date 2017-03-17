#ifndef __operations_h__
#define __operations_h__

#include "poli.h"

int printPolinomio(LinkedList *l);
LinkedList *delete(LinkedList *head, LinkedList *del);
LinkedList *normalizar(LinkedList *l);
LinkedList *somar(LinkedList *n1, LinkedList *n2);
LinkedList *derivar(LinkedList *l);
LinkedList *integrar(LinkedList *l);

#endif