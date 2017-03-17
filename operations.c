#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operations.h"

LinkedList *find(LinkedList *aux, int coe, char* var, int exp){
	if(aux==NULL){
		aux=makeList(makeMono(coe,var,exp),aux);
	}
	else{
		for(;aux!=NULL;aux=aux->next){
			if(getVar(aux)==var && getExp(aux)==exp){
				setCoe(aux,coe+getCoe(aux));
				break;
			}
		}
	}
	//aux=aux->next;
	return aux;
}


LinkedList *normalizar(LinkedList *l){


	LinkedList * aux = NULL;

	for(; l!=NULL ; l=l->next){
		aux=find(aux,getCoe(l),getVar(l),getExp(l));
		//aux=aux->next;
	}

	printPolinomio(aux);

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
	printPolinomio(aux);
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
	printPolinomio(aux);
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
		printPolinomio(n1);
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
		printPolinomio(n2);
		return n2;
	}

}

int printPolinomio(LinkedList *l) {
	while(l) {
		if(getKind(l) == MONO) {
			if(!l->next)
				printf("%d%s^%d\n", getCoe(l), getVar(l), getExp(l));
			else
				printf("%d%s^%d + ", getCoe(l), getVar(l), getExp(l));
		}
		else {
			if(!l->next)
				printf("%d\n", getCons(l)); 
			else
				printf("%d + ", getCons(l));
		}
		l=l->next;
	}

	return 0;
}