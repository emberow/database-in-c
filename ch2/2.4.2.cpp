#define MAX_DEGREE 101
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h> 
#include <string>
#include <vector>
using namespace std;
#include "split.cpp"

typedef struct polynomial{
	int degree;
	int coef;
};
void show_poly(polynomial *a);

void Zero(polynomial pol[]){	
	for (int i = 0; i < MAX_DEGREE; i++){
		pol[i].coef = 0;
		pol[i].degree = 0;	
	}
	return;
}

bool isZero(polynomial *poly){
	for (int i = 0; i < MAX_DEGREE; i++){
		if(poly[i].coef != 0)
			return false;
	}
	return true;
}

int Coef(polynomial *poly, int expon){
	for (int i = 0; i < MAX_DEGREE; i++){
		if (poly[i].degree == expon)
			return poly[i].coef;
	}
	return 0;
}

int LeadExp(polynomial *poly){
	int highest_exp = 0;
	for (int i = 0; i < MAX_DEGREE; i++){
		if (poly[i].degree > highest_exp)
			highest_exp = poly[i].degree;
	}
	return highest_exp;
}

void Attach( polynomial poly[], int coef, int expon){
	for (int i = 0; i < MAX_DEGREE; i++){
		if (poly[i].degree == 0 and poly[i].coef == 0){
			poly[i].degree = expon;
			poly[i].coef = coef;
			return;
		}
	}
}

void Remove(polynomial *poly, int expon){
	for (int i = 0; i < MAX_DEGREE; i++){
		if (poly[i].degree == expon){
			poly[i].degree = 0;
			poly[i].coef = 0;
			return;
		}
	}
}

polynomial *padd(polynomial *a, polynomial *b){
	//polynomial pol[MAZ_DEGREE];//如果不加static，則return pol會有問題，因為這個副程式return時，編譯器會釋放記憶體，而卻return一個位址 
	polynomial static answer[MAX_DEGREE];
	Zero(answer);
	while(!isZero(a) or !isZero(b)){
		if(LeadExp(a) > LeadExp(b)){
			Attach(answer, Coef(a,LeadExp(a)), LeadExp(a));
			Remove(a,LeadExp(a));
		}
		else if(LeadExp(a) < LeadExp(b)){
			Attach(answer, Coef(b,LeadExp(b)), LeadExp(b));
			Remove(b,LeadExp(b));
		}
		else if(LeadExp(a) == LeadExp(b)){
			Attach(answer, Coef(b,LeadExp(b)) + Coef(a,LeadExp(a)), LeadExp(a));
			Remove(a,LeadExp(a));
			Remove(b,LeadExp(b));
		}	
	}
	
	return answer;
}

void show_poly(polynomial a[]){
	for (int i = 0; i < MAX_DEGREE; i++){
		if (a[i].coef != 0){
			if(i != 0){
				printf(" + ");
			}
			printf("%dx^%d",a[i].coef, a[i].degree);
		}
	}
	printf("\n");	
}



void readPoly(polynomial *poly){
	
	string input;
	char **split_input,**split_split_input;
	
	using namespace std;
	int coef,expon;
	getline(cin,input);
	
	split_input = split_str(input, " + ");
	
	for(int i = 0; i < 10; i++){
		split_split_input = split_str(split_input[i], "x^");
		coef = atoi(split_split_input[0]);
		expon = atoi(split_split_input[1]);
		if (coef != 0 ){
			Attach(poly,coef,expon);
		}
		
	}	
}

int main(){
	polynomial a[MAX_DEGREE], b[MAX_DEGREE], *answer;
	
	Zero(a);
	Zero(b);
	printf("請輸入多項式a 例如: (5x^3 + 8x^4)\n");
	readPoly(a);
	printf("請輸入多項式b 例如: (5x^3 + 8x^4)\n");
	readPoly(b);
	
	
	
	printf("\n\na = ");
	show_poly(a);
	printf("b = ");
	show_poly(b);
	answer = padd(a,b);// answer = 1x^1 + 4x^2 + 6x^3 + 4x^4
	printf("a + b = ");
	show_poly(answer);

}
