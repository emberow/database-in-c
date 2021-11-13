#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 100
typedef struct element{
	int key;
};

element stack[MAX_STACK_SIZE];
int top = -1;

element *stack_creat(){
	static element temp[MAX_STACK_SIZE];
	return temp;
}

void stack_full(){
	printf("堆疊已滿");
	exit(EXIT_FAILURE);
}

void push(element item){
	if (top >= MAX_STACK_SIZE-1){
		stack_full();
		return;
	}
	stack[++top] = item;
}

element pop(){
	if(top == -1){
		printf("堆疊為空"); 
	}
	return stack[top--];
}

void stack_empty(){
	top = -1;
}

int main(){
	stack_empty();
}
