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

	l=normalizar(l);

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

	l=normalizar(l);

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

LinkedList *somar(LinkedList *n1, LinkedList *n2){

	int len1=0,len2=0;

	n1=normalizar(n1);
	n1=normalizar(n2);

	for(;n1!=NULL;n1=n1->next){
		len1++;
	}

	for(;n2!=NULL;n2=n2->next){
		len2++;
	}

	if(len1>=len2){
		for(;n1!=NULL;n1=n1->next){
			for(;n2!=NULL;n2=n2->next){

				if(n1->mon->monos.mono.var == n2->mon->monos.mono.var && n1->mon->monos.mono.exp == n2->mon->monos.mono.exp){
					n1->mon->monos.mono.coe = n1->mon->monos.mono.coe + n2->mon->monos.mono.coe;
				}
			}
		}
		return n1;
	}

	else if(len1<len2){
		for(;n2!=NULL;n2=n2->next){
			for(;n1!=NULL;n1=n1->next){
				if(n1->mon->monos.mono.var == n2->mon->monos.mono.var && n1->mon->monos.mono.exp == n2->mon->monos.mono.exp){
					n2->mon->monos.mono.coe = n1->mon->monos.mono.coe + n2->mon->monos.mono.coe;
				}	
			}
		}
		return n2;
	}
}