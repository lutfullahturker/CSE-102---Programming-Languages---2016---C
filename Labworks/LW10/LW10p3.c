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

int lwIsAcc(Country arr[],int size,char* source,char* target);

int main(void)
{
	Country arr[10];
	strcpy(arr[0].name,"turkiye");
	strcpy(arr[4].name,"azerbaycan");
	printf("ilk %s\nson %s\n",arr[0].name,arr[4].name);
	lwIsAcc(arr,10,"tur","target");
	printf("ilk %s\nson %s",arr[0].name,arr[4].name);

	return 0;
}

int lwIsAcc(Country arr[],int size,char* source,char* target)
{
	int i,sIndex=-1;
	if (size <=0 || source==NULL || target ==NULL)
		return -1;
	for (i=0;i<size;i++)
	{
		if (strcmp(arr[i].name,source)==0)
			sIndex=i;
	}
	if (sIndex==-1)
		return -1;
	for (i=0;i<MAX_NEIGHBOR;i++)
	{
		if (strcmp(arr[sIndex].neighbors[i],target)==0)
			return 0;
		if (arr[sIndex].flag != 1)
			arr[sIndex].flag=1;
			return lwIsAcc(arr,size,arr[sIndex].neighbors[i],target);
	}
	return -1;
}
