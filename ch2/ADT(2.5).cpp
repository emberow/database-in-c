#define MAX_DEGREE 101
#include<stdio.h>
#include <typeinfo>
typedef struct polynomial{
	int degree;
	int coef;
};
void show_poly(polynomial *a);
void Zero(polynomial *pol){
	//polynomial pol[MAZ_DEGREE];//如果不加static，則return pol會有問題，因為這個副程式return時，編譯器會釋放記憶體，而卻return一個位址 
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
			return poly[i].degree;
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

void Attach( polynomial *poly, int coef, int expon){
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

void show_poly(polynomial *a){

	for (int i = 0; i < MAX_DEGREE; i++){
		if (a[i].coef != 0){
			if(i != 0){
				printf(" + ");
			}
			printf("%d^%d",a[i].coef, a[i].degree);
		}
	}
	printf("\n");	
}

int main(){
	polynomial a[MAX_DEGREE], b[MAX_DEGREE], *answer;
	Zero(a);
	Zero(b);
	Attach(a,1,1);// a = 1x^1 + 2x^2 + 3x^3
	Attach(a,2,2);
	Attach(a,3,3);
	Attach(b,2,2);// b =2x^2 + 3x^3 + 4x^4
	Attach(b,3,3);
	Attach(b,4,4);
	printf("a = ");
	show_poly(a);
	printf("b = ");
	show_poly(b);
	answer = padd(a,b);// answer = 1x^1 + 4x^2 + 6x^3 + 4x^4
	printf("a + b = ");
	show_poly(answer);

}
