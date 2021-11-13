#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h> 
#include <string>
#include <vector>
using namespace std;
#define MAX_DEGREE 101


char ** make2dArray(int rows,int cols)
{//使用malloc建立rows * cols大小的二維陣列 
	char **x;
	x = (char **)malloc(rows * sizeof(char*));
	for(int i = 0; i < rows; i++)
	{
		x[i] = (char *)malloc(cols * sizeof(char));
		//x[i]裡面存的是位址，然後擴充 cols * sizeof(int)的大小 
	}		
	return x;
}
char **split_str(string str,const char sep[]){ 
	char **answer;
	int x = 0,y = 0;
	int spt_count = 0, str_count = 0;

	answer = make2dArray(MAX_DEGREE, MAX_DEGREE);
	for (int i = 0; i < MAX_DEGREE; i++){
		if(sep[i] == '\0'){
			break;
		}
		spt_count ++;
	}
	str_count = str.length();	
	int available;
	for(int i = 0; i < str_count; i++){
		available = 0;
		for(int j = 0; j < spt_count; j++){
			if(str[i+j] != sep[j]){
				available = 1;
			}
		}
		
		if (available == 1){
			answer[x][y++] = str[i];
			
		}
		else if (available == 0){
			answer[x][y] = '\0';	
			/*字元陣列最後必須為\0*/
			y = 0;
			x += 1;
			i += (spt_count-1);
		}
	}

	return answer;		
}

/*int main(){
	char **ans;
	ans = split_str("abcdefg","cde");

	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++)
			printf("%d %d %c\n",i,j,ans[i][j]);
}*/


