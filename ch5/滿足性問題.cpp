#include<stdio.h>
#include<stdlib.h>

typedef enum{
	VAR, NOT, AND, OR, TRUE, FALSE
}logical;
//���VlistNode������ 
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

//�إ�5-27�����R�D�� 
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
//�Hpost_order���覡��p���ܼƼƶq 
void count_var(treePointer node, int *count){
	if(node){
		count_var(node->lchild, count);
		count_var(node->rchild, count);
		//�p��h���ܼ� 
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
	printf("�`�@��%d���ܼ�\n",count);
	
	int variable[count];
	//�w�]�Ҧ��ܼƬ�false 
	for(int i = 0; i < count; i++){
		variable[i] = false;
	}
	
	bool is_end;
	int result;
	while(true){
		printf("\n");
		
		int temp_count = count;
		//�N�ܼƶ���̭��A�b�P�_�ڸ`�I�O�_��true 
		result = test_tree(root, variable, &temp_count); 
		if(result == 1){
			printf("true  ");
		}
		else{
			printf("false ");
		}
		
		//�P�_�O�_�������ƦC�զX���Q�չL�F 
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
		
		//�ƦC�զX�Ҧ��ܼ� 
		change_variable(variable, count);
		
		
	}
}

int main(){
	treePointer *node;
	node = make_tree();
	find_solution(node);
	
	
	
	
}
