#include<stdio.h>
#include<stdlib.h>

typedef struct listNode *listPointer;//指向listNode的指標 
typedef struct listNode{
	int data;
	listPointer link;
};

listPointer creat(int data){
	listPointer first;
	first = (listPointer)malloc(sizeof(*first));
	first -> link = NULL;
	first -> data = data;
	return first;
}

void push(listPointer *top, int item){
	listPointer temp;
	temp = creat(item);
	temp->link = *top;
	*top = temp;
}

int pop(listPointer *top){
	int result;
	listPointer temp;
	temp = *top;
	result = temp->data;
	temp = temp->link;
	*top = temp;
	return result;	
}

void print_list(listPointer first){
	for(; first != NULL; first = first->link){
		printf("%d ",first->data);
	}
	printf("\n");
}

int main(){
	listPointer first;
	first = creat(0);
	listPointer top;
	top = first;
	print_list(first);
	push(&top, 1);
	push(&top, 2);
	print_list(top);
	pop(&top);
	print_list(top);
}




