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
	int **a, **b, **c;
	a = make2dArray(2,2);
	b = make2dArray(2,2);
	c = make2dArray(2,2);
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			a[i][j] = 1;
			b[i][j] = 2;
			printf("a[%d][%d]=%d\n",i,j,a[i][j]);
			printf("b[%d][%d]=%d\n",i,j,b[i][j]);
		}
	} 
}
