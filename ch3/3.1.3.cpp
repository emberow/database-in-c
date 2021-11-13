#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 100
typedef struct element{
	int key;
};

element *stack_creat(){
	static element temp[MAX_STACK_SIZE];
	return temp;
}

void stack_full(){
	printf("堆疊已滿");
	exit(EXIT_FAILURE);
}

void push(element stack[], int top, element item){
	if (top >= MAX_STACK_SIZE-1){
		stack_full();
		return;
	}
	stack[++top] = item;
}

int pop(element stack[], int top){
	if(top == -1){
		printf("堆疊為空"); 
	}
	else{
		return stack[top--].key;
	}
	
}

void stack_empty(int top){
	top = -1;
}

void meke_fibon(element stack[], int *top, int limit){
	element temp;
	temp.key = stack[*top].key + stack[*top-1].key;
	push(stack, *top, temp); 
	if(*top != MAX_STACK_SIZE-2 and *top != limit){
		*top += 1;
		meke_fibon(stack, top, limit);
	}
	return;
}
void show(element stack[], int top){
	int temp;
	if(top != -1){
		temp = pop(stack, top);
		printf("stack[%d] = %d \n", top, temp);
		show(stack , --top);
	}
}

int main(){
	element *x = stack_creat();
	x[0].key = 0;
	x[1].key = 1;
	int top = 1;
	meke_fibon(x, &top, 4);
	show(x, top);
}
