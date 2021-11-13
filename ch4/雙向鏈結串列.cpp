#include<stdio.h>
#include<stdlib.h>

typedef struct node *nodePointer;//指向listNode的指標 
typedef struct node{
	nodePointer llink;
	nodePointer rlink;
	int value;
};

nodePointer newNode(){
	nodePointer result;
	result = (nodePointer)malloc(sizeof(*result));
	return result;
} 

void dinsert(nodePointer node, nodePointer new_node){//將newnode插到node的右邊 
	new_node->llink = node;
	new_node->rlink = node->rlink;
	node->rlink->llink = new_node;
	node->rlink = new_node;
}

void ddelete(nodePointer node){//刪除此node 
	node->rlink->llink = node->llink;
	node->llink->rlink = node->rlink;
}

void print_link_list(nodePointer head){
	for(nodePointer node = head->rlink; node != head; node = node->rlink){
		printf("%d\n",node->value);
	}
}


int main(){
	nodePointer head = newNode();
	head->llink = head;
	head->rlink = head;
	head->value = 0;
	
	nodePointer temp1 = newNode();//head->1 
	temp1->value = 1;
	dinsert(head, temp1);
	
	nodePointer temp2 = newNode();//head->1->2 
	temp2->value = 2;
	dinsert(temp1, temp2);
	
	nodePointer temp3 = newNode();//head->1->2->3 
	temp3->value = 3;
	dinsert(temp2, temp3);
	
	nodePointer temp4 = newNode();//head->1->2->2->3 
	temp4->value = 2;
	dinsert(temp2, temp4);
	
	print_link_list(head);
	
	ddelete(temp4);//head->1->2->3 
	ddelete(temp3);//head->1->2
	ddelete(temp2);//head->1
	ddelete(temp1);//head
	
	print_link_list(head);
}
