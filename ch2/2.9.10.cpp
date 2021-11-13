#include<stdio.h>
#include<stdlib.h> 
#define MAX_SIZE 8

void init_board(int board[MAX_SIZE][MAX_SIZE]){
	for(int i = 0; i < MAX_SIZE; i++){
		for(int j = 0; j < MAX_SIZE; j++){
			board[i][j] = 0;
		}
	}
	board[0][0] = 1;
}

void show_board(int board[MAX_SIZE][MAX_SIZE]){
	for(int i = 0; i < MAX_SIZE; i++){
		for(int j = 0; j < MAX_SIZE; j++){
			printf("%2d ",board[i][j]);
		}
		printf("\n");
	}
}

bool is_step_legal(int board[MAX_SIZE][MAX_SIZE], int now_step[2]){
	if(now_step[0] >= MAX_SIZE or now_step[0] < 0 or now_step[1] >= MAX_SIZE or now_step[1] < 0){
		return false;
	}
	else if(board[now_step[0]][now_step[1]] != 0){
		return false;
	}
	return true;
}

bool move(int board[MAX_SIZE][MAX_SIZE], int now_step[2], int count){
	int direction[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
	int next_step[2] = {0, 0};
	bool finish = false;
	for(int i = 0; i < MAX_SIZE; i++){
		//printf("%d %d\n",next_step[0], next_step[1]);
		next_step[0] = now_step[0]+direction[i][0];
		next_step[1] = now_step[1]+direction[i][1];
		if(is_step_legal(board, next_step)){
			//printf("%d %d\n", next_step[0], next_step[1]);
			//printf("%d\n",count);
			board[next_step[0]][next_step[1]] = count;
			//show_board(board);
			finish = move(board, next_step, count+1);
			if(finish == true or count == 64){
				return true;
			}
			board[next_step[0]][next_step[1]] = 0;
		} 
	}
	return false;
}

int main(){
	int board[MAX_SIZE][MAX_SIZE];
	int step[2] = {0, 0};
	int count = 1;
	init_board(board);
	//show_board(board);
	move(board, step, count+1);
	show_board(board);
	
}
