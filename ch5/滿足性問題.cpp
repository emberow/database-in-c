#include<stdio.h>
#include<stdlib.h>

typedef enum{
	VAR, NOT, AND, OR, TRUE, FALSE
}logical;
//指向listNode的指標 
typedef struct tree_node *treePointer;
typedef struct tree_node{
	treePointer lchild;
	treePointer rchild;
	int value;
	logical data;
};

treePointer create(){
	treePointer root;
	root = (treePointer)malloc(sizeof(*root));
	root->value = NULL;
	root->lchild = NULL;
	root->rchild = NULL;
	return root;
}

//建立5-27頁的命題樹 
treePointer *make_tree(){
	treePointer node[12];
	for(int i = 0; i < 12; i++){
		node[i] = create();
	}
	node[0]->data = OR;
	node[0]->lchild = node[1];
	node[0]->rchild = node[2];
	
	node[1]->data = OR;
	node[1]->lchild = node[3];
	node[1]->rchild = node[4];
	
	node[2]->data = NOT;
	node[2]->rchild = node[5];
	
	node[3]->data = AND;
	node[3]->lchild = node[6];
	node[3]->rchild = node[7];
	
	node[4]->data = AND;
	node[4]->lchild = node[8];
	node[4]->rchild = node[9];
	
	node[5]->data = VAR;
	
	node[6]->data = VAR;
	
	node[7]->data = NOT;
	node[7]->rchild = node[10];
	
	node[8]->data = NOT;
	node[8]->rchild = node[11];
	
	node[9]->data = VAR;
	
	node[10]->data = VAR;
	
	node[11]->data = VAR;
	
	return node;
}
//以post_order的方式找計算變數數量 
void count_var(treePointer node, int *count){
	if(node){
		count_var(node->lchild, count);
		count_var(node->rchild, count);
		//計算多少變數 
		if(node->data == 0){
			*count += 1;
		}
	}
}

int *change_variable(int variable[], int QTY){
	for(int i = 0; i < QTY; i++){
		variable[i] += 1;
		if (variable[i] == 2){
			variable[i] = 0;
		}
		else if(variable[i] == 1){
			break;
		}
	}
}

int test_tree(treePointer node, int variable[], int *top){
	if(node){
		test_tree(node->lchild, variable, top);
		test_tree(node->rchild, variable, top);
		switch(node->data){
			case VAR:
				*top -= 1;
				node->value = variable[*top];
				break;
			case NOT:
				if (node->rchild->value == 0){
					node->value = 1;
				}
				else{
					node->value = 0;
				}
				break;
			case AND:
				if (node->rchild->value == 1 and node->lchild->value == 1){
					node->value = 1;
				}
				else{
					node->value = 0;
				}
				break;
			case OR:
				if (node->rchild->value == 1 or node->lchild->value == 1){
					node->value = 1;
				}
				else{
					node->value = 0;
				}
				break;
		}
		return node->value;
	}
}

void find_solution(treePointer node[]){
	int count = 0;
	treePointer root = node[0];
	count_var(root, &count);
	printf("總共有%d個變數\n",count);
	
	int variable[count];
	//預設所有變數為false 
	for(int i = 0; i < count; i++){
		variable[i] = false;
	}
	
	bool is_end;
	int result;
	while(true){
		printf("\n");
		
		int temp_count = count;
		//將變數填到樹裡面，在判斷根節點是否為true 
		result = test_tree(root, variable, &temp_count); 
		if(result == 1){
			printf("true  ");
		}
		else{
			printf("false ");
		}
		
		//判斷是否全部的排列組合都被試過了 
		is_end = true;
		for(int i = 0; i < count; i++){
			printf("%d",variable[i]);
			if(variable[i] == false){
				is_end = false;
			}
		}
		if(is_end == true){
			break;
		}
		
		//排列組合所有變數 
		change_variable(variable, count);
		
		
	}
}

int main(){
	treePointer *node;
	node = make_tree();
	find_solution(node);
	
	
	
	
}
