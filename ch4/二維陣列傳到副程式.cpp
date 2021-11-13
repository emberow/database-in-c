#include<stdio.h>
#include<stdlib.h>

int test(int **a){
	printf("%d",a[0][0]);
}


int main(){
	int row = 3;
	int col = 3;
	int input_1[row][col] = {
		{1,2,3},
		{1,2,3},
		{1,2,3},
	};
	int *input_2[row];
	for(int i = 0; i < row; i++){
		input_2[i] = input_1[i];
	}
	test(input_2);
}
