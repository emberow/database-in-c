#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int nfind(char string[], char pat[]){//string 被比對的字串 pat:比對的樣式 
	for (int i = 0; i < strlen(string); i++){
		for(int j = 0; j < strlen(pat); j++){
			if(string[i+j] != pat[j]){
				break;
			}
			else if(j == strlen(pat) - 1 and string[i+j] == pat[j]){
				return i;
			}
		}
	}
	return -1;
}

int main(){
	int n = 0;
	char a[] = "abcdefg";
	char b[] = "cd";
	n = nfind(a, b);
	printf("%d", n);
}
