#include<stdio.h>
#include<stdlib.h> 
#define MAX_ROW 15
#define MAX_COL 15

bool check_finish(int x[MAX_ROW][MAX_COL]){
	for(int i = 0; i < MAX_ROW; i++){
		for(int j = 0; j < MAX_COL; j++){
			if(x[i][j] == 0){
				return false;
			}
		} 
	}
	return true;
}

bool check_move(int step[], int ver, int hor){
	if(step[0] + ver > MAX_ROW - 1 or step[0] + ver < 0 or step[1] + hor > MAX_COL - 1 or step[1] + hor < 0){
		return false;
	}
	return true;
}

void move(int x[MAX_ROW][MAX_COL], int step[],int *count){
	int a = rand() % 8;
	int direction[8][2] = {{-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}};
	if (check_move(step, direction[a][0], direction[a][1])){
		step[0] += direction[a][0];
		step[1] += direction[a][1];
		x[step[0]][step[1]] += 1;
		*count += 1;
	}
}

void show_step(int x[MAX_ROW][MAX_COL]){
	for(int i = 0; i < MAX_ROW; i++){
		for(int j = 0; j < MAX_COL; j++){
			printf("%d\n",x[i][j]);
		} 
	}
	printf("\n");
}
int main(){
	int step[2] = {10, 10};//°_©lÂI 
	int count = 0;
	int x[MAX_ROW][MAX_COL];
	for(int i = 0; i < MAX_ROW; i++){
		for(int j = 0; j < MAX_COL; j++){
			x[i][j] = 0;
		} 
	}
	while (true){
		printf("%d %d %d\n", count,step[0],step[1])	;
		move(x, step, &count);
		if (check_finish(x)){
			break;
		}
	}	
}
