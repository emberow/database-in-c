#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void strains(char s[], char t[], int i){
	if (i < 0 and i > strlen(s)){
		printf("位置超過邊界");
		exit(EXIT_FAILURE);
	}
	if(!strlen(s)){
		strcpy(s, t);
	}
	s[strlen(s)+strlen(t)] = '\0';
	s[strlen(s)] = 'j';
	s[strlen(s)+1] = '\0';
	printf("%c",s[strlen(s)]);
	for(int j = strlen(s); j > i; j--){
		s[j+2] = s[j];
		//printf("%s\n",s);
	}
	//printf("%s\n",s);
	for(int j = 0; j < strlen(t); j++){
		s[i+j] = t[j];
	}
	//printf("%s",s);
}


int main(){
	char y[100] = "abcdehi";
	strains(y, "fg", 5);
	
}
 
