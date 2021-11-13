#include<stdio.h>
#include<stdlib.h>

typedef struct listNode *listPointer;//指向listNode的指標 
typedef struct listNode{
	int coef;
	int expon;
	listPointer link;
};

listPointer creat(){
	listPointer first;
	first = (listPointer)malloc(sizeof(*first));
	first -> link = NULL;
	return first;
}

void attach(int coefficient ,int exponent, listPointer *poly_last_item){
	listPointer temp, temp_last_item;
	temp = creat();
	temp_last_item = *poly_last_item;
	temp_last_item->link = temp;
	temp->coef = coefficient;
	temp->expon = exponent;
	*poly_last_item = temp;
}

void print_poly(listPointer poly){
	if(poly->link != NULL){
		poly = poly->link;
	}
	
	for(;poly != NULL; poly = poly->link){
		printf("%dX^%d", poly->coef, poly->expon);
		if(poly->link != NULL){
			printf(" + ");
		}
		else{
			printf("\n");
		}
	}
}

listPointer poly_add(listPointer a, listPointer b){
	listPointer c, top_c;
	c = creat();
	top_c = c;
	a = a->link;
	b = b->link;
	while(a or b){
		if(a == NULL){
			attach(b->coef, b->expon, &top_c);
			b = b->link;
		}
		else if(b == NULL){
			attach(a->coef, a->expon, &top_c);
			a = a->link;
		}
		else{
			if(a->expon > b->expon){
				attach(a->coef, a->expon, &top_c);
				a = a->link;
			}
			else if(b->expon > a->expon){
				attach(b->coef, b->expon, &top_c);
				b = b->link;
			}
			else if(b->expon == a->expon){
				attach(a->coef+b->coef, a->expon, &top_c);
				a = a->link;
				b = b->link;
			}
		}
	}
	return c;
}

int main(){
	listPointer poly_a, poly_b, poly_c;
	listPointer top_a, top_b, top_c;
	poly_a = creat();
	poly_b = creat();
	poly_c = creat();
	top_a = poly_a;
	top_b = poly_b;
	top_c = poly_c;
	attach(3,3,&top_a);
	attach(2,2,&top_a);
	attach(1,1,&top_a);
	printf("A = ");
	print_poly(poly_a);
	attach(4,4,&top_b);
	attach(3,3,&top_b);
	printf("B = ");
	print_poly(poly_b);
	poly_c = poly_add(poly_a, poly_b);
	printf("A+B = ");
	print_poly(poly_c);
}
