#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operations.h"

LinkedList *normalizar(LinkedList *l) {

	if(!l->next)
		return l;

	LinkedList *curr = l;
	LinkedList *new = NULL;

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
		new = makeList(curr->mon, new);
		curr = curr->next;
	}
	return new;	 
}

LinkedList *derivar(LinkedList *l) {
	
	l=normalizar(l);
	LinkedList *new = NULL;

	while(l) {
		if(getKind(l) == MONO) {
			if(getExp(l) == 1) {
				new = makeList(makeCons(getCoe(new)), new);
			}
			else {
				float mul = getCoe(l) * getExp(l);
				new = makeList(makeMono(mul, getVar(l), getExp(l)-1), new);
			}
		}
		else {
			new = makeList(makeCons(0), new);
		}
		l = l->next;
	}
	return new;
}

LinkedList *integrar(LinkedList *l) {
	
	l=normalizar(l);
	LinkedList *new = NULL;

	while(l){
		if(getKind(l) == MONO){
			new = makeList(makeMono(getCoe(l)/(getExp(l)+1),getVar(l),getExp(l)+1),new);
		}
		else{
			new = makeList(makeMono(getCons(l), "x", 1), new);
		}
		l = l->next;
	}
	return new;
}

LinkedList *somar(LinkedList *l1, LinkedList *l2) {
	LinkedList *new = append(l1, l2);
	new = normalizar(new);
	return new;
}

LinkedList *append(LinkedList *l1, LinkedList *l2) {
	if(!l1) return l2;
	if(!l2) return l1;

	LinkedList *l = NULL;

	for(l=l1; l1->next != NULL; l1 = l1->next)
		;
	l1->next = l2;
	return l;
}

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

int printPolinomio(LinkedList *l) {
	while(l) {
		if(getKind(l) == MONO) {
			if(!l->next)
				printf("%f%s^%d\n", getCoe(l), getVar(l), getExp(l));
			else
				printf("%f%s^%d + ", getCoe(l), getVar(l), getExp(l));
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