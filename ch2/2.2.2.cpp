#include<stdlib.h>
#include<stdio.h>
int ** make2dArray(int rows)
{//�ϥ�malloc�إ�rows * cols�j�p���G���}�C 
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
		
		//x[i]�̭��s���O��}�A�M���X�R cols * sizeof(int)���j�p 
	}
	
		
	return x;
}
int main(){
	int **y;
	y = make2dArray(10);
}
