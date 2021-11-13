#include<stdio.h>
#include<stdlib.h>

void push_char(char stack[], int *top, char item){
	*top += 1; 
	stack[*top] = item;
}

char pop_char(char stack[], int *top){
	char result;
	result = stack[*top];
	*top -= 1; 
	return result;
}

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

void show(char stack[], int top){
	char temp;
	if(top != -1){
		temp = pop_char(stack, &top);
		printf("stack[%d] = %c\n", top+1, temp);
		show(stack , top);
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

int symbol_priority(char c){
	switch(c){
		case '+':
			return 0;
		case '-':
			return 0;
		case '*':
			return 1;
		case '/':
			return 1;
	}
}

void postfix(char original_string[], char result[], int *top){
	char sym_stack[100];
	int sym_top = -1;
	for(int i = 0; original_string[i] != '\0'; i++){
		if(is_num(original_string[i])){
			push_char(result, top, original_string[i]);
		}
		if(is_symbol(original_string[i])){
			if(*top != -1){
				if(symbol_priority(original_string[i]) > symbol_priority(sym_stack[*top])){ 
					push_char(sym_stack, &sym_top, original_string[i]);
				}
				else{
					while(sym_top != -1){
						push_char(result, top, pop_char(sym_stack, &sym_top)); 
					}
					push_char(sym_stack, &sym_top, original_string[i]);
				}
			}
			else{
				push_char(sym_stack, &sym_top, original_string[i]);
			}
			
		}
	}
	while(sym_top != -1){
		push_char(result, top, pop_char(sym_stack, &sym_top));
	}
	
} 

int main(){
	char *input = "+(2*3;
	char result[100];
	int top = 0;
	
	postfix(input, result, &top);
	printf("%d", eval(result));
	
}
