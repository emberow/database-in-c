#include<stdio.h>
#include<string.h>
typedef struct {
	char marry_date[10];
}maried;

typedef struct {
	char marry_date[10];
	char date_of_spouse_death[10];
}Death_of_spouse;

typedef struct {
	char divorce_date[10];
	int divorce_times;
}divorce;

typedef struct{
	enum married_status
	{singal, marry, spouse_death, divorse};

	union{
		maried maried_detail;
		Death_of_spouse Death_of_spouse_detail;
		divorce divorce_detail;
	}detail;
	
} person;

int main(){

}
