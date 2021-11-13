#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 50

typedef struct matrixNode *matrixPointer;//���VlistNode������ 
typedef struct entryNode{
	int row;
	int col;
	int value;
};

typedef enum {head_node, entry} tagfield;//head = 0, entry = 1
typedef struct matrixNode{
	matrixPointer down;
	matrixPointer right;
	tagfield tag;
	union{
		matrixPointer next;
		entryNode entry;
	} u;
};

matrixPointer newNode(){
	matrixPointer result;
	result = (matrixPointer)malloc(sizeof(*result));
	return result;
} 

void mwrite(matrixPointer head_node){
	matrixPointer node = head_node->right;
	matrixPointer temp_node;
	printf("row col value\n");
	for(;node != head_node; node = node->u.next){
		for(temp_node = node->right; temp_node != node; temp_node = temp_node->right){
			printf("%-3d %-3d %-4d\n",temp_node->u.entry.row, temp_node->u.entry.col, temp_node->u.entry.value);
		}
	}
	
}

matrixPointer mread(int **matrix, int max_row, int max_col){
	int nums_head = (max_row > max_col) ? max_row : max_col;//�s��H->H0->H1...->H 
	nums_head++;
	matrixPointer head[nums_head],node;
	head[0] = newNode();
	for(int i = 1; i < nums_head; i++){
		head[i] = newNode();
		head[i-1]->u.next = head[i];
		head[i]->tag = head_node;
		head[i]->right = head[i];//�ۤv�s��ۤv 
		head[i]->down = head[i];
	}
	head[0]->right = head[1];
	head[nums_head-1]->u.next = head[0];

	head[0]->tag = entry;//�}�l��x�}����쵲��C 
	head[0]->u.entry.row = max_row;
	head[0]->u.entry.col = max_col;
	for(int i = 0; i < max_row; i++){
		for(int j = 0; j < max_col; j++){
			if(matrix[i][j] != 0){
				matrixPointer temp_node;
				temp_node = newNode();
				temp_node->tag = entry;
				temp_node->u.entry.row = i;
				temp_node->u.entry.col = j;
				temp_node->u.entry.value = matrix[i][j];
				
				node = head[i+1];//�}�l���k�s�� 
				while (node->right != head[i+1]){//�M��̥k�䪺�`�I 
					node = node->right;
				}
				node->right = temp_node;
				temp_node->right = head[i+1];
				
				node = head[j+1];//�}�l���U�s�� 
				while (node->down != head[j+1]){//�M��̤U�����`�I 
					node = node->down;
				}
				node->down = temp_node;
				temp_node->down = head[j+1];
			}
		}
	}
	return head[0];
}

int main(){
	int max_row = 5;
	int max_col = 4;
	int matrix[max_row][max_col] = {
		{2, 0, 0, 0},
		{4, 0, 0, 3},
		{0, 0, 0, 0},
		{8, 0, 0, 1},
		{0, 0, 6, 0}
	};
	int *matrix_pointer[max_row];
	for(int i = 0; i < max_row; i++){
		matrix_pointer[i] = matrix[i];//�N2���}�C�ন���Ъ����A(�S�����wcol�j�p)
	}
	matrixPointer head;
	head = mread(matrix_pointer, max_row, max_col);
	mwrite(head);
}
