#include<stdio.h>
#include<stdlib.h>
#include <string.h>
using namespace std;

	
typedef struct card{
	int num;
	char color[6];
	int status;
};

int top[12];
int boundary[13];
card all_card[360];

typedef struct stack{
	card element;
};

void push(int i, card temp_card){
	if(top[i] != boundary[i+1])
		all_card[++top[i]] = temp_card;
}

card pop(int i){
	card result;
	if (top[i] != boundary[i])
		result = all_card[top[i]--];
	return result;
}

card random_generate_card(){
	card a;
	a.num = rand() % 13 + 1;
	int color_num = rand() % 4;
	switch(color_num){
		case 0:
			strcpy(a.color, "梅花");
			break;
		case 1:
			strcpy(a.color, "菱形");
			break;
		case 2:
			strcpy(a.color, "愛心");
			break;
		case 3:
			strcpy(a.color, "黑桃");
			break;
	}
	return a;
}

void swap_card(card card_stack[], int i, int j){
	card temp_card;
	strcpy(temp_card.color, card_stack[i].color);
	temp_card.num = card_stack[i].num;
	strcpy(card_stack[i].color, card_stack[j].color);
	card_stack[i].num = card_stack[j].num;
	strcpy(card_stack[j].color, temp_card.color);
	card_stack[j].num = temp_card.num;
}

void Shuffle(card standard_card[]){
	card temp_card;
	int shuffle_times = 10000;
	int j;
	int temp_i;
	for(int i = 0; i < shuffle_times; i++){
		temp_i = i % 52;
		j = rand() % 52;
		swap_card(standard_card, temp_i, j);
		
	}
}

void init_card(card all_card[], int top[]){
	for(int i = 0; i < 13; i++)
		boundary[i] = i * 30; 
		
	for(int i = 0; i < 12; i++)
		top[i] = i * 30 - 1;
	card temp_card;
	int available = 1;
	
	card standard_card[52];
	for(int i = 0; i < 52; i++){
		switch(i/13){
			case 0:
				strcpy(standard_card[i].color, "梅花");
				break;
			case 1:
				strcpy(standard_card[i].color, "菱形");
				break;
			case 2:
				strcpy(standard_card[i].color, "愛心");
				break;
			case 3:
				strcpy(standard_card[i].color, "黑桃");
				break;
		}
		standard_card[i].num = i % 13 + 1;
		standard_card[i].status = 0;
	}
	
	Shuffle(standard_card);
	
	int standard_card_top = -1;
	
	for(int i = 1; i <= 7; i++){
		for(int j = 1; j <= i; j++){
			push(i, standard_card[++standard_card_top]);
		}
	}
	
	for(int i = 0; i < 24; i++){ 
		standard_card_top++;
		standard_card[standard_card_top].status = 1;
		push(0, standard_card[standard_card_top]);
	}
}

bool examine_color(char a[]){
	if(strcmp(a,"梅花") == 0 or strcmp(a,"菱形") == 0  or strcmp(a,"黑桃") == 0  or strcmp(a,"愛心") == 0 )
		return true;
	return false;
}

void show_card(){
	system("cls");
	printf("----------------------------------------------------------------------------------------------------\n");
	printf("|         0         |         A         |         B         |         C         |         D         |\n");
	printf("|                   |                   |                   |                   |                   |\n");
	printf("|                   |                   |                   |                   |                   |\n");
	printf("|                   |                   |                   |                   |                   |\n");
	printf("|       黑桃8       |       黑桃8       |       黑桃8       |       黑桃8       |       黑桃8       |\n");
	printf("|                   |                   |                   |                   |                   |\n");
	printf("|                   |                   |                   |                   |                   |\n");
	printf("|                   |                   |                   |                   |                   |\n");
	printf("----------------------------------------------------------------------------------------------------\n");
	printf("|      1      |      2      |      3      |      4      |      5      |      6      |      7      |\n");
	for(int i = 0; i < 20; i++){
		for(int j = 1; j <= 7; j++){
			if(examine_color(all_card[boundary[j]+i].color)){
				if(all_card[boundary[j]+i].status == 1){
					switch(all_card[boundary[j]+i].num){
					case 11:
						printf("|    %s%-2s   ", all_card[boundary[j]+i].color, "J");
						break;
					case 12:
						printf("|    %s%-2s   ", all_card[boundary[j]+i].color, "Q");
						break;
					case 13:
						printf("|    %s%-2s   ", all_card[boundary[j]+i].color, "K");
						break;
					default:
						printf("|    %s%-2d   ", all_card[boundary[j]+i].color, all_card[boundary[j]+i].num);
						break;
					}
				}
				else{
					printf("|     ???     ");
				}
				
			}
			else{
				printf("|             ");
			}
		}
		printf("|\n----------------------------------------------------------------------------------------------------\n");
	}
}

bool is_num(char a){
	if(a <= '7' and a >= '0')
		return true;
	return false;
} 

bool is_letter(char a){
	if(a <= 'D' and a >= 'A')
		return true;
	return false;
}

bool is_two_card_same_color(card temp_card1, card temp_card2){
	int card1_color;
	int card2_color;
	if(strcmp(temp_card1.color, "黑桃") == 0 or strcmp(temp_card1.color, "梅花")){
		card1_color = 0;
	} 
	else{
		card1_color = 1;
	}
	if(strcmp(temp_card2.color, "黑桃") == 0 or strcmp(temp_card2.color, "梅花")){
		card2_color = 0;
	} 
	else{
		card2_color = 1;
	}
	if(card1_color == card2_color){
		return true;
	}
	else{
		return false;
	}
}

void start_game(){
	while(true){
		for(int i = 1; i <= 7; i++){//翻開堆疊第一張排
			if(all_card[top[i]].status == 0){
				all_card[top[i]].status = 1;
			}
		}
		show_card();
		printf("指令: \n數字x 數字y: 將堆疊x上的牌堆疊到數字y上\n數字x 字母y: 將堆疊x的第一張牌堆疊到y堆疊上\n數字0:顯示其他堆疊0的牌\n");
		char instruction[4];
		printf("請輸入指令\n");
		gets(instruction);
		if (is_num(instruction[0]) and is_num(instruction[2])){
			
		}
		else if (is_num(instruction[0])and is_letter(instruction[2])){
			if(is_two_card_same_color(all_card[top[instruction[0] - 0]], all_card[top[instruction[2]-'A'+ 8]])){
				if(instruction[0] != '0'){//1-7的第一張牌存到A-D 
					push(instruction[2]-'A'+ 8, pop(instruction[0] - '0'));
					strcpy(all_card[top[instruction[0] - '0'] + 1].color, "");
				}
				else{//0的牌存到A-D 
					//push(instruction[2]-'a'+8, pop(0));
				}
			}
			
		}
		else if(instruction[0] == '0'){
			 
		}
		else {
			printf("指令錯誤");
		} 
	}
	
}

int main(){
	init_card(all_card, top);
	start_game();
}
