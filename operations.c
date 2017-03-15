#include <stdlib.h>
#include <string.h>
#include "operations.h"

LinkedList *normalizar(LinkedList *l){

	LinkedList *p = l;
	LinkedList *aux = NULL;

	for(; l!=NULL ; l=l->next){
		for(p=l->next ; p!=NULL ; p=p->next){
			if(getVar(l) == getVar(p) 
			&& getExp(l) == getExp(p) 
			&& !isVisited(p)){
				setExp(aux, getExp(l));
				setVar(aux, getVar(l));
				setCoe(aux, getCoe(l));
				setVisited(p);
			}
		}
	}
	return aux;
}

LinkedList *derivar(LinkedList *l){
	LinkedList *aux = NULL;

	l=normalizar(l);

	for(; l!= NULL; l=l->next){
		if(getKind(l) == CONS) {
			setCoe(aux, 0);
		}
		else{
			setCoe(aux, getCoe(l)*getExp(l));
			setExp(aux, getExp(l)-1);
		}
	}
	return aux;
}

LinkedList *integrar(LinkedList *l){
	LinkedList *aux = NULL;

	l=normalizar(l);

	for(; l!=NULL; l=l->next){
		if(getKind(l) == CONS){
			setCoe(aux, getCoe(l));
			setVar(aux, "x");
			setExp(aux, 1);
		}
		else{
			setCoe(aux, getCoe(l)/(getExp(l)+1));
			setExp(aux, getExp(l));
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

				if(getVar(n1) == getVar(n2) && getExp(n1) == getExp(n2)){
					setCoe(n1, getCoe(n1) + getCoe(n2));
				}
			}
		}
		return n1;
	}

	else {
		for(;n2!=NULL;n2=n2->next){
			for(;n1!=NULL;n1=n1->next){
				if(getVar(n1) == getVar(n2) && getExp(n1) == getExp(n2)){
					setCoe(n2, getCoe(n1)+getCoe(n2));
				}	
			}
		}
		return n2;
	}

}