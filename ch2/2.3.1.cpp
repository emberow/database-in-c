#include<stdio.h>
#include<string.h>
typedef struct{
	char name[10];
	int distance_to_sun;
	int satelite;
} planet;

int main(){
	planet earth,venus;
	strcpy(earth.name,"earth");
	strcpy(venus.name,"venus");
	
	earth.distance_to_sun = 15000000;
	venus.distance_to_sun = 108000000;
	
	earth.satelite = 1;
	venus.satelite = 0;
	
	printf("%s distance_to_sun = %d satelite = %d\n",earth.name,earth.distance_to_sun,earth.satelite);
	printf("%s distance_to_sun = %d satelite = %d\n",venus.name,venus.distance_to_sun,venus.satelite);

}
