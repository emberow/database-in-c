#include<stdlib.h>
#include<stdio.h>
int ** make2dArray(int rows)
{//使用malloc建立rows * cols大小的二維陣列 
	int **x;
	
	//printf("%d\n",*x);
	x = (int **)malloc(rows * sizeof(*x));
	
	for(int i = 0; i < rows; i++)
	{	
		printf("%d\n",i * sizeof(**x));
		x[i] = (int *)malloc(i * sizeof(**x));
		for(int j = 0; j < i; j++)
		{
			printf("array[%d][%d]%d\n",i,j,&x[i][j]);
		} 
		
		//x[i]裡面存的是位址，然後擴充 cols * sizeof(int)的大小 
	}
	
		
	return x;
}
int main(){
	int **y;
	y = make2dArray(10);
}
