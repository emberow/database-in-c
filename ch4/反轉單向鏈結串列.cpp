#include<stdio.h>
#include<stdlib.h>

typedef struct listNode *listPointer;//指向listNode的指標 
typedef struct listNode{
	int value;
	listPointer link;
};

listPointer invert(listPointer first){
	listPointer temp, trail, temp_first;
	temp_first = first;
	first = first->link;
	temp = NULL;
	while(first != NULL){
		trail = temp;
		temp = first;
		first = first->link;
		temp->link = trail;
	}
	temp_first->link = temp;
	return temp_first;
}

listPointer creat(){
	listPointer first;
	first = (listPointer)malloc(sizeof(*first));
	first -> link = NULL;
	return first;
}

void attach(listPointer *top_a, int value){
	listPointer temp_top_a = *top_a;
	listPointer temp = creat();
	temp_top_a->link = temp;
	temp->value = value;
	*top_a = temp;
}

void print_list(listPointer first){
	first = first->link;
	for(; first != NULL; first = first->link){
		printf("%d ",first->value);
	}
}

int main(){
	listPointer a;
	a = creat();
	listPointer top_a = a;
	attach(&top_a, 1);
	attach(&top_a, 2);
	attach(&top_a, 3);
	print_list(a);
	a = invert(a);
	printf("\n");
	print_list(a);
}
