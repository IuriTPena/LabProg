#include <stdlib.h>
#include <string.h>
#include "operations.h"

LinkedList *normalizar(LinkedList *l){

	LinkedList *p = l;
	LinkedList *aux = NULL;

	for(; l!=NULL ; l=l->next){
		for(p=l->next ; p!=NULL ; p=p->next){
			if(l->mon->monos.mono.var == p->mon->monos.mono.var && l->mon->monos.mono.exp == p->mon->monos.mono.exp && p->mon->monos.mono.visited == false){
				aux->mon->monos.mono.exp = l->mon->monos.mono.exp;
				memcpy(aux->mon->monos.mono.var, l->mon->monos.mono.var,VARSIZE);
				aux->mon->monos.mono.coe = l->mon->monos.mono.coe + p->mon->monos.mono.coe;
				p->mon->monos.mono.visited = true;
			}
		}
	}
	return aux;
}

LinkedList *derivar(LinkedList *l){
	LinkedList *aux = NULL;

	for(; l!= NULL; l=l->next){
		if(l->mon->kind == CONS) {
			aux->mon->monos.mono.coe = 0;
		}
		else{
			aux->mon->monos.mono.coe = l->mon->monos.mono.coe * l->mon->monos.mono.exp;
			aux->mon->monos.mono.exp = l->mon->monos.mono.exp - 1;
		}
	}
	return aux;
}

LinkedList *integrar(LinkedList *l){
	LinkedList *aux = NULL;

	for(; l!=NULL; l=l->next){
		if(l->mon->kind == CONS){
			aux->mon->monos.mono.coe = l->mon->monos.cons;
			memcpy(aux->mon->monos.mono.var, "x", VARSIZE);
			aux->mon->monos.mono.exp = 1;
		}
		else{
			aux->mon->monos.mono.coe = l->mon->monos.mono.coe / (l->mon->monos.mono.exp +1);
			aux->mon->monos.mono.exp = l->mon->monos.mono.exp;
		}
	}
	return aux;
}