#include<stdio.h>
#include<string.h>
typedef struct{
	char name[10];
	int age;
	float salary;
} person;

bool human_equal(person p1, person p2)
{
	if (strcmp(p1.name, p2.name)){
		printf("%d",strcmp(p1.name, p2.name));
		return false;
	}
	if(p1.age != p2.age){
		return false;
	}
	if(p1.salary != p2.salary){
		return false;
	}
	return true;
}

int main(){
	person person1, person2;
	strcpy(person1.name,"andy");
	person1.age = 21;
	person1.salary = 3000;
	
	strcpy(person2.name,"andy");
	person2.age = 21;
	person2.salary = 3000;
	if (human_equal(person1, person2)){
		printf("2人一樣");
	}
		
	else{
		printf("2人不一樣");
	}
		
	
}
