#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 100
typedef struct element{
	int key;
};

void stack_full(){
	printf("堆疊已滿");
	exit(EXIT_FAILURE);
}

void push(element stack[], int *top, element item){
	if (*top >= MAX_STACK_SIZE-1){
		stack_full();
		return;
	}
	*top += 1; 
	stack[*top] = item;
}

int pop(element stack[], int *top){
	if(*top == -1){
		printf("堆疊為空"); 
	}
	else{
		int result = stack[*top].key;
		*top -= 1; 
		return result;
	}
}

void stack_empty(int top){
	top = -1;
}

void show(element stack[], int top){
	int temp;
	if(top != -1){
		temp = pop(stack, &top);
		printf("stack[%d] = %d \n", top+1, temp);
		show(stack , top);
	}
}

void init_track(element a[], int n, int *top){
	element temp;
	for(int i = n; i > 0; i--){
		temp.key = i;
		push(a, top, temp);
	}
}

void copy_array(element array[], element array2[], int top){
	element result[MAX_STACK_SIZE];
	for(int i = 0; i <= top; i++){
		array2[i].key = array[i].key;
	}
	return;
}

void move_train(element a[], element b[], element c[], int top_a, int top_b, int top_c){
	if(top_a > -1){
		element temp_b[MAX_STACK_SIZE];
		element temp_a[MAX_STACK_SIZE];
		copy_array(b, temp_b, top_b);
		copy_array(a, temp_a, top_a);
		int temp_top_b = top_b;
		int temp_top_a = top_a;		
		element temp_item;
		temp_item.key = pop(temp_a, &temp_top_a);
		push(temp_b, &temp_top_b, temp_item);
		move_train(temp_a, temp_b, c, temp_top_a, temp_top_b, top_c);
	}
	if(top_b > -1){
		element temp_b[MAX_STACK_SIZE];
		element temp_c[MAX_STACK_SIZE];
		copy_array(b, temp_b, top_b);
		copy_array(c, temp_c, top_c);
		int temp_top_b = top_b;
		int temp_top_c = top_c;
		element temp_item;
		temp_item.key = pop(temp_b, &temp_top_b);
		push(temp_c, &temp_top_c, temp_item);
		move_train(a, temp_b, temp_c, top_a, temp_top_b, temp_top_c);
		if(temp_top_b == -1 and top_a == -1){
			printf("result\n");
			show(temp_c, temp_top_c);
		}  
	}
}

int main(){
	element a[MAX_STACK_SIZE];
	element b[MAX_STACK_SIZE];
	element c[MAX_STACK_SIZE];

	int top_a = -1;
	int top_b = -1;
	int top_c = -1;
	init_track(a, 3, &top_a);
	move_train(a, b, c, top_a, top_b, top_c);
}
