#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void reverse(char a[]){
	char temp;                                                                                                  vvvvvvvv
	for(int i = 0; i < strlen(a) / 2; i++){
		temp = a[i];
		a[i] = a[strlen(a)-i-1];
		a[strlen(a)-i-1] = temp;
	}
}

int main(){
	char x[] = "abcdefgh";
	reverse(x);
	printf("%s",x);
}
