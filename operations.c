#define __poli_h__
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "poli.h"

Polinomio *Norm(LinkedList *l); //Normalização de polinómios
Polinomio *Deriv(LinkedList *l); //Derivaçao de polinomios
Polinomio *Integra(LinkedList *l); //Integraçao de polinomios

Polinomio *Norm(LinkedList *l){

	LinkedList *aux = NULL;

	LinkedList *p = l;

	for(; l!=NULL ; l=l-> next){
		for(p=l->next ; p!=NULL ; p=p->next){
			if(l->pols.pol.var == p->pols.pol.var && l->pols.pol.exp == p->pols.pol.exp && p->pols.pol.visited == false){
				aux->pols.pol.exp = l->pols.pol.exp;
				aux->pols.pol.var = l->pols.pol.var;
				aux->pols.pol.coef = l->pols.pol.coef + p->pols.pol.coef;
				p->pols.pol.visited = true;
			}
		}
	}
	return aux;
}


Polinomio *Deriv(LinkedList *l){
	LinkedList *aux = NULL;

	for(; l!= NULL; l=l->next){
		if(l->kind = CONS)
			aux->pols.pol.coef = 0;

		else{
			aux->pols.pol.coef = l->pols.pol.coef * l->pols.pol.exp;
			aux->pols.pol.exp = l->pols.pol.exp - 1;
		}
	}
	return aux;
}

Polinomio *Integra(LinkedList *l){
	LinkedList *aux = NULL;

	for(;l!=NULL;l=l->next){
		if(l->kind = CONS){
			aux->pols.pol.coef = l->pols.cons;
			aux->pols.pol.var = 'x';
			aux->pols.pol.exp = 1;
		}
		else{
			aux->pols.pol.coef = l->pols.pol.coef / (l->pols.pol.exp +1);
			aux->pols.pol.exp = l->pols.pol.exp;
		}
	}

	return aux;
}