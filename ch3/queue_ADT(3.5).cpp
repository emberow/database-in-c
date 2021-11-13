#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 100 

typedef struct element{
	int key;
};

element *queue_creat(int max_size,element queue[]){
	queue = (element*)malloc(sizeof(element)*max_size);
	for(int i = 0; i < MAX_QUEUE_SIZE; i++){
		queue[i].key = NULL;
	}
	return queue;
}

void add_q(element queue[], int *rear, int item){
	if(*rear != MAX_QUEUE_SIZE - 1){
		*rear += 1;
		queue[*rear].key = item;
		return;
	}
	else{
		printf("this queue is full");
	}
}

int delete_q(element queue[], int *front, int rear){
	if(*front == rear){
		printf("this queue is empty");
	}
	else{
		*front += 1;
		return queue[*front].key;
	}
}

void show_queue(element queue[], int front, int rear){
	for(int i = 0; i < MAX_QUEUE_SIZE; i++){
		printf("[%d]", i);
		printf("%d", queue[i].key);
		if(i == rear){
			printf(" rear");
		}
		if(i == front){
			printf(" front");
		}
		printf("\n");
	}
}

int main(){
	int rear = -1;
	int front = -1;
	element *queue;
	queue = queue_creat(MAX_QUEUE_SIZE, queue);
	add_q(queue, &rear, 5);
	show_queue(queue, front, rear);
}
