#include<stdio.h>
#include<stdlib.h>

typedef struct tree_node *treePointer;//指向listNode的指標 
typedef struct tree_node{
	treePointer lchild;
	treePointer rchild;
	char value;
};

treePointer create(){
	treePointer root;
	root = (treePointer)malloc(sizeof(*root));
	root->value = NULL;
	root->lchild = NULL;
	root->rchild = NULL;
	return root;
}

void push(treePointer stack[], int *top, treePointer node){
	*top += 1;
	stack[*top] = node;
}

treePointer pop(treePointer stack[], int *top){
	if(*top == -1){
		return NULL;
	}
	treePointer result = stack[*top];
	*top -= 1;
	
	return result;
}

typedef struct queue_element{
	treePointer cur_node;
	treePointer cur_node_parent;
};

void add_element_q(queue_element queue[], int *front, treePointer node, treePointer parent){
	queue[*front].cur_node = node;
	queue[*front].cur_node_parent = parent;
	*front += 1;
}

queue_element delete_element_q(queue_element queue[], int *rear, int front){
	queue_element result;
	
	if (*rear >= front){
		result.cur_node = NULL;
		result.cur_node_parent = NULL;
		return result;
	}
	result = queue[*rear];
	*rear += 1;
	return result;
}

void add_q(treePointer queue[], int *front, treePointer node){
	queue[*front] = node;
	*front += 1;
}

treePointer delete_q(treePointer queue[], int *rear, int front){
	treePointer result;
	
	if (*rear >= front){
		return NULL;
	}
	result = queue[*rear];
	*rear += 1;
	return result;
}

treePointer make_complete_tree(int num){
	treePointer root = create();
	root->value = 0;
	int front = 0, rear = 0;
	queue_element queue[100];
	add_element_q(queue, &front, root, NULL);
	queue_element cur_ptr;
	for(int i = 0; i < num; i++){
		cur_ptr = delete_element_q(queue, &rear, front);
		add_element_q(queue, &front, create(), cur_ptr.cur_node);
		add_element_q(queue, &front, create(), cur_ptr.cur_node);
		cur_ptr.cur_node->value = i;
		if(cur_ptr.cur_node_parent != NULL){
			if(cur_ptr.cur_node_parent->lchild ==NULL){
				cur_ptr.cur_node_parent->lchild = cur_ptr.cur_node;
			}
			else{
				cur_ptr.cur_node_parent->rchild = cur_ptr.cur_node;
			}
		}
	}
	return root;
}

void inorder(treePointer node){
	if(node){
		inorder(node->lchild);
		printf("%d",node->value);
		inorder(node->rchild);
	}
}

void preorder(treePointer node){
	if(node){
		printf("%d",node->value);
		preorder(node->lchild);
		preorder(node->rchild);
	}
}

void postorder(treePointer node){
	if(node){
		postorder(node->lchild);
		postorder(node->rchild);
		printf("%d",node->value);
	}
}


void iteration_inorder(treePointer node){
	int top = -1;
	treePointer stack[100];
	while(true){
		for(; node != NULL; node = node->lchild){
			push(stack, &top, node);
			//printf("%d", node->value);
		}
		node = pop(stack, &top);
		if(node == NULL){//堆疊為空 
			break;
		}
		printf("%d", node->value);
		node = node->rchild;
	}
}

void level_order(treePointer root){ 
	int front = 0, rear = 0;
	treePointer queue[100];
	add_q(queue, &front, root);
	treePointer cur_ptr;
	while(true){
		cur_ptr = delete_q(queue, &rear, front);
		if(cur_ptr != NULL){
			printf("%d",cur_ptr->value);
		}
		else{
			break;
		}
		if(cur_ptr->lchild != NULL){
			add_q(queue, &front, cur_ptr->lchild);
		}
		if(cur_ptr->rchild != NULL){
			add_q(queue, &front, cur_ptr->rchild);
		}
	}
	
}

treePointer copy(treePointer node){//以遞迴的方式複製一棵樹 
	if (node){
		treePointer temp_node = create();
		temp_node->lchild = copy(node->lchild);
		temp_node->rchild = copy(node->rchild);
		temp_node->value = node->value;
		return temp_node; 
	}
	return NULL;
	
}

bool equal(treePointer first, treePointer second){//判斷兩顆二元樹是否相等 
	if(first != NULL and second != NULL){
		return (first->value == second->value) and
	  	equal(first->lchild, second->lchild) and
	  	equal(first->rchild, second->rchild);
	}
	else if(first == NULL and second == NULL){
		return true;
	}
	
}


//將節點中的左子樹與右子樹互換 
void swap_tree(treePointer node){
	if(node){
		swap_tree(node->lchild);
		swap_tree(node->rchild);
		
		treePointer temp_node;
		temp_node = node->lchild;
		node->lchild = node->rchild;
		node->rchild = temp_node;
	}
}
 
int main(){
	treePointer root;
	root = make_complete_tree(7);
	
	/*
		0
	   1 2
	 3 4 5 6
	*/
	level_order(root);
	
	/*
		0
	   2 1
	 6 5 4 3
	*/
	printf("\n");
	swap_tree(root);
	level_order(root);
} 
 
