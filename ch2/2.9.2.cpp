#include<stdio.h>
#include<stdlib.h> 
#define MAX_ROW 10
#define MAX_COL 10
bool check_row_min(int a[MAX_ROW][MAX_COL],int row,int col){
	int min;
	min = a[row][0];
	for(int j = 0; j < MAX_COL; j++){
		if(a[row][j] < min){
			min = a[row][j];
		}
	}
	if (a[row][col] == min){
		return true;
	}
	else{
		return false;
	}
}

bool check_col_max(int a[MAX_ROW][MAX_COL],int row,int col){
	int max;
	max = a[0][col];
	for(int i = 0; i < MAX_ROW; i++){
		if(a[i][col] > max){
			max = a[i][col];
		}
	}
	if (a[row][col] == max){
		return true;
	}
	else{
		return false;
	}
}

void find_saddle_point(int a[MAX_ROW][MAX_COL]){
	bool is_min_row,is_max_col;
	for(int i = 0; i < MAX_ROW; i++){
		for(int j = 0; j < MAX_COL; j++){
			is_min_row = check_row_min(a, i, j);
			is_max_col = check_col_max(a, i, j);
			if(is_min_row and is_max_col){
				printf("%d %d\n",i,j);
			}
		}
	}
}

int main(){
	int a[MAX_ROW][MAX_COL];
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 10; j++)
			a[i][j] = i * 10 + j;
	for(int i = 5; i < 10; i++)
		for(int j = 0; j < 10; j++)
			a[i][j] = (i-5) * 10 + j;
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	find_saddle_point(a);
	
}
