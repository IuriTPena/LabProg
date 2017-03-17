#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operations.h"

LinkedList *delete(LinkedList *head, LinkedList *del) {
    if(!head) return NULL;
    LinkedList *curr = head;
    if(curr == del) {
        return curr->next;
    }
    else {
        LinkedList *prev = head;
        LinkedList *curr = head->next;
        while(curr && prev) {
            if(curr == del) {
                LinkedList *temp = curr;
				prev->next = curr->next;
				free(temp);
				return head;
			}
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

LinkedList *normalizar(LinkedList *l){

	if(!l->next)
		return l;

	LinkedList *curr = l;
	LinkedList *norm = NULL;

	while(curr) {
		LinkedList *copy = curr->next;
		while (copy) {
			if(getKind(curr) == getKind(copy)) {
				if(getKind(curr) == MONO) {
					if(!strcmp(getVar(curr),getVar(copy)) && getExp(curr) == getExp(copy)) {
						int sum = getCoe(curr) + getCoe(copy);
						setCoe(curr,sum);
						curr = delete(curr, copy);				
					}
				}
				else {
					int sum = getCons(curr) + getCons(copy);
					setCons(curr,sum);
					curr = delete(curr, copy);
				}
			}
			copy = copy->next;
		}
		norm = makeList(curr->mon, norm);
		curr = curr->next;
	}
	printPolinomio(norm);
	return norm;	 
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