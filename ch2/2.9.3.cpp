#include<stdio.h>
#include<stdlib.h> 
#define MAX_ROW 10


void store_value(int a[], int row, int col,int value){
	int n = row*(row+1)/2 + col;
	a[n] = value;
}

int main(){
	int x[MAX_ROW*(MAX_ROW+1)/2];
	store_value(x, 3, 3, 10);
	printf("%d",x[9]);
	
}
