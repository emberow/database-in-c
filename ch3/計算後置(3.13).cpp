#include<stdio.h>
#include<stdlib.h>



void push(int stack[], int *top, int item){
	*top += 1; 
	stack[*top] = item;
}

int pop(int stack[], int *top){
	int result;
	result = stack[*top];
	*top -= 1; 
	return result;
}

bool is_num(char c){
	if(c >= '0' and c <= '9'){
		return true;
	}
	return false;
}

bool is_symbol(char c){
	if(c == '+' or c == '-' or c == '*' or c == '/'){
		return true;
	}
	return false;
}

int calculate(int op1, char sym, int op2){
	switch (sym){
		case '+':
			return op1 + op2;
			break;
		case '-':
			return op1 - op2;
			break;
		case '*':
			return op1 * op2;
			break;
		case '/':
			return op1 / op2;
			break;
	}
}

int eval(char string[]){
	int op1, op2;
	int stack[100];
	int top = -1;
	for(int i = 0; string[i] != '\0'; i++){
		if(is_num(string[i])){
			push(stack, &top, string[i]-'0');
		}
		else if(is_symbol(string[i])){
			op2 = pop(stack, &top);
			op1 = pop(stack, &top);
			push(stack, &top, calculate(op1, string[i], op2));
		}
	}
	return pop(stack, &top);
}

int main(){
	printf("%d\n", eval("234*+"));
	printf("%d", eval("12+7*"));
}
