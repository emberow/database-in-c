#define MAX_SIZE 100
#include<stdio.h>
//°}¦C0~99¬Û¥[
 
float sum(float [], int);
float input[MAX_SIZE], answer;
void main(void)
{	int i;
    for (i = 0; i < MAX_SIZE; i++) 
        input[i] = i;
    answer = sum(input, MAX_SIZE);
    printf("this sum is: %f\n",answer);
}

float sum(float list[], int n)
{

    float tempsum = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        tempsum += list[i];
    }
    return tempsum;
}
