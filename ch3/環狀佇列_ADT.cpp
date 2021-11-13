#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 5 

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

void add_q(element queue[], int *rear, int front, int item){
	if((*rear + 1)%MAX_QUEUE_SIZE != front){
		*rear += 1;
		*rear = *rear % MAX_QUEUE_SIZE;
		queue[*rear].key = item;
		return;
	}
	else{
		printf("\nthis queue is full\n");
	}
}

int delete_q(element queue[], int *front, int rear){
	if(*front == rear){
		printf("\nthis queue is empty\n");
	}
	else{
		*front += 1;
		*front = *front % MAX_QUEUE_SIZE;
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
	add_q(queue, &rear, front, 5);
	add_q(queue, &rear, front, 4);
	add_q(queue, &rear, front, 3);
	add_q(queue, &rear, front, 2);
	add_q(queue, &rear, front, 1);
	add_q(queue, &rear, front, 1);
	add_q(queue, &rear, front, 1);
	show_queue(queue, front, rear);
}
