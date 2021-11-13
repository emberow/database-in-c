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

void insert(listPointer x, int num){
	listPointer temp;
	temp = (listPointer)malloc(sizeof(*temp));
	temp->data = num;
	temp->link = x->link;
	x->link = temp;	
}

void delete_link(listPointer first, listPointer x){
	listPointer x_previous_node;
	for(;first != x;first = first->link){
		x_previous_node = first;
	}
	x_previous_node->link = x->link;
}

void print_list(listPointer first){
	for(; first != NULL; first = first->link){
		printf("%d\n",first->data);
	}
}

int main(){
	listPointer first;
	first = creat(0);
	insert(first, 3);
	insert(first, 2);
	insert(first, 1);
	//delete_link(first, first->link->link);
	print_list(first);
}
