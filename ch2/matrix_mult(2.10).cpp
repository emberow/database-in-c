#include<stdio.h>
#include<stdlib.h>
#define maxa 10
#define maxb 9
#define maxc 8

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

int get_value(term a[], int row, int col){
	for(int i = 1; i < a[0].value + 1; i++){
		if(a[i].row == row and a[i].col == col){
			return a[i].value;
		}
	}
	return 0;
	
}

term *transpose(term a[]){
	int max_degree;
	term *b;
	b = Creat(a[0].col, a[0].row);
	int  a_count = 0, b_count = 0, count = 0;
	for(int i = 0; i < a[0].col; i++){
		for(int j = 0; j < a[0].row; j++){
			if(a[j*(a[0].col)+i].col == i){
				//printf("%d %d %d %d\n",j,i,a[j*maxcol+i].row,a[j*maxcol+i].col);
				b[b_count].row = a[j*(a[0].col)+i].col;
				b[b_count].col = a[j*(a[0].col)+i].row;
				b[b_count].value = a[j*(a[0].col)+i].value;
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
int store_sum(term a[], term b[], int x, int y){
	int sum = 0;
	int temp_x_value, temp_y_value;
	for(int i = 0; i < a[0].col; i++){
		sum += get_value(a, x, i) * get_value(b, i, y);
	}
	return sum;
}
void multiplication(term a[], term b[], term d[]){
	int count = 1;
	int sum = 0;
	for(int i = 0; i < d[0].row; i++){
		for(int j = 0; j < d[0].col; j++){
			sum = 0;
			sum = store_sum(a, b, i, j);//盢d[i][j]恶a[0][i] 	
			printf("%d %d %d\n",i,j,sum);
			if(sum != 0){
				d[0].value += 1;
				d[count].value = sum;
				d[count].row = i;
				d[count].col = j;
				count++;
			}
			//show(d);
			//printf("%d %d\n",i,j);
		}
	}
}

int main(){
	term *x,*y,*answer;
	x = Creat(maxa,maxb);//10*9
	y = Creat(maxb,maxc);//9*8
	answer = Creat(maxa,maxc);
	x[0].row = maxa;//程计 
	x[0].col = maxb;//程︽计 
	x[0].value = 10;//程计 
	y[0].row = maxb;
	y[0].col = maxc;
	y[0].value = 9;
	
	for(int i = 1; i < maxa + 1; i++){
		x[i].row = i-1;
		x[i].col = 0;
		x[i].value = 1;
	}
	for(int i = 1; i < maxb + 1; i++){
		y[i].row = 0;
		y[i].col = i-1;
		y[i].value = 1;
	}
	answer[0].row = maxa;
	answer[0].col = maxc;
	answer[0].value = 0;
	int n;
	multiplication(x, y, answer);
	//x = transpose(x);
	/*for(int i = 0; i < 10; i++){
		printf("%d %d %d\n",i,x[i].row,x[i].col);
	}*/
	
}
