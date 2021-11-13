#include<stdio.h>
#define MAX_SIZE 100
//列出陣列裡面所有的 位址+值 
void print_address( int *ptr, int rows)
{
	printf("address content\n");
	for( int i = 0; i < rows; i++)
	{
		printf("%d %d",ptr,i);
		printf("%8u %5d \n",ptr + i, *(ptr + i)) ;
	}
}


int main(void)
{	
	int array[MAX_SIZE];
	for( int i = 0; i < MAX_SIZE; i ++){
		array[i] = i;
	}
	print_address(array, MAX_SIZE);
	printf("%d",array) ;
} 
