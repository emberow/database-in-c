#include<stdio.h>
#include<stdlib.h>
#define maxrow 10
#define maxcol 10

typedef struct term{
	int col;
	int row;
	int value;
};
void show(term x[]);
term *Creat(int row, int col){
	int max_degree;
	term *a;
	max_degree = row * col + 1;
	a = (term*)malloc(max_degree * sizeof(term));
	return a;
}

term *transpose(term a[]){
	int max_degree;
	term *b;
	b = Creat(maxrow,maxcol);
	int  a_count = 0, b_count = 0, count = 0;
	for(int i = 0; i < maxcol; i++){
		for(int j = 0; j < maxrow; j++){
			if(a[j*maxcol+i].col == i){
				//printf("%d %d %d %d\n",j,i,a[j*maxcol+i].row,a[j*maxcol+i].col);
				b[b_count].row = a[j*maxcol+i].col;
				b[b_count].col = a[j*maxcol+i].row;
				b[b_count].value = a[j*maxcol+i].value;
				b_count++;
			}
		}
	}
	return b;
}

void show(term x[]){
	for(int i = 0; i < x[0].value; i++)
		printf("%d %d %d\n",x[i].row,x[i].col,x[i].value);
}

int main(){
	term *x,*y;
	x = Creat(maxrow,maxcol);
	x[0].row = maxrow;
	x[0].col = maxcol;
	x[0].value = maxrow * maxcol + 1;
	int j;
	int a = 0,b = 0;
	for(int i = 1; i < x[0].value; i++){
		b = (i-1) % 10;
		a = (i-1) / 10;
		x[i].row = a;
		x[i].col = b;
		x[i].value = a*b;
	}

		

	show(x);
	x = transpose(x);
	
	/*for(int i = 0; i < 10; i++){
		printf("%d %d %d\n",i,x[i].row,x[i].col);
	}*/
	
}
