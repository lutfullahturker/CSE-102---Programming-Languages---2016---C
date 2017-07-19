#include <stdio.h>
#include <string.h>

#define MAX_NAME 25
#define MAX_NEIGHBOR 10

typedef struct Country_s {
	char name[MAX_NAME];
	int population;
	char neighbors[MAX_NEIGHBOR][MAX_NAME];
	int flag;
} Country;

int lwFind(Country arr[],int size,char* query);

int main(void)
{
	Country arr[10];
	int result=lwFind(arr,10,"Turkiye");

	return 0;
}

int lwFind(Country arr[],int size,char* query)
{
	int i;
	if (size <=0 || query == NULL)
		return -1;
		
	for (i=0;i<size;i++)
		if (strcmp(arr[i].name,query)==0)
			return i;
	return -1;
}

