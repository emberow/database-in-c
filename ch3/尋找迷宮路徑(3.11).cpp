#include<stdio.h>
#include<stdlib.h>
#define MAX_ROW 12
#define MAX_COL 15
typedef struct element{
	int dir;
	int row;
	int col;
};

int direction[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

int map[MAX_ROW][MAX_COL] = \
	{{0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1},\
	{1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1},\
	{0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1},\
	{1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0},\
	{1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},\
	{0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1},\
	{0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1},\
	{0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},\
	{0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1},\
	{1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0},\
	{0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0},\
	{0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0}};\

bool is_next_step_valid(element next_step, element stack[], int top){
	if (next_step.row >= 12 or next_step.row < 0 or next_step.col >= 15 or next_step.col < 0){
		return false;
	}
	
	for(int i = 0; i <= top ; i++){
		if (next_step.row == stack[i].row and next_step.col == stack[i].col){
			return false;
		}	
	}
		
	if (map[next_step.row][next_step.col] == 1){
		return false;
	}
	
	return true;
}

void push(element stack[], int *top, element item){
	*top += 1; 
	stack[*top] = item;
}

element pop(element stack[], int *top){
	element result;
	result = stack[*top];
	*top -= 1; 
	return result;
}

void show(element stack[], int top){
	element temp;
	if(top != -1){
		temp = pop(stack, &top);
		printf("stack[%d] = %d %d %d\n", top+1, temp.row, temp.col, temp.dir);
		show(stack , top);
	}
}

void move(element stack[], int *top){
	element next_step;
	element this_step;
	this_step.row = 0;
	this_step.col = 0;
	this_step.dir = 0;
	push(stack, top, this_step);
	//show(stack, *top);
	while(next_step.row != MAX_ROW or next_step.col != MAX_COL){
		next_step.row = stack[*top].row + direction[stack[*top].dir][0];
		next_step.col = stack[*top].col + direction[stack[*top].dir][1];
		next_step.dir = 0;
		this_step.dir += 1;
		if(is_next_step_valid(next_step, stack, *top)){
			push(stack, top, next_step);
		}
		else{
			stack[*top].dir += 1;
			if(stack[*top].dir >= 8){
				pop(stack, top);
				stack[*top].dir += 1;
			}
		}
	}
}

int main(){
	element stack[MAX_ROW*MAX_COL];
	int top = -1;
	move(stack, &top);
	show(stack, top);
}
