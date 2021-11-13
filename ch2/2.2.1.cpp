#include<stdlib.h>
#include<stdio.h>
int ** make2dArray(int rows, int cols)
{//使用malloc建立rows * cols大小的二維陣列 
	int **x;
	//printf("%d\n",*x);
	x = (int **)malloc(rows * sizeof(int*));
	for(int i = 0; i < rows; i++)
	{
		x[i] = (int *)malloc(cols * sizeof(int));
		//x[i]裡面存的是位址，然後擴充 cols * sizeof(int)的大小 

	}
		
	return x;
}
int main(){
	int **y;
	y = make2dArray(3,5);
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			y[i][j] = 0;
			printf("%d\n",y[i][j]);
		}
	} 
}
