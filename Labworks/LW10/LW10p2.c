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

int lwSort(Country arr[],int size,char choice);

int main(void)
{
	Country arr[10];
	strcpy(arr[0].name,"turkiye");
	strcpy(arr[4].name,"azerbaycan");
	printf("ilk %s\nson %s\n",arr[0].name,arr[4].name);
	lwSort(arr,10,'n');
	printf("ilk %s\nson %s",arr[0].name,arr[4].name);

	return 0;
}

int lwSort(Country arr[],int size,char choice)
{
	int i,j,temp,k;
	char tempc[25];
	if (size <=0 || (choice != 'p' && choice != 'n'))
		return -1;
		
	for (i=0;i<size;i++)
		for (j=i;j<size;j++)
		{
			if (choice == 'n' && strcmp(arr[j].name,arr[i].name)<0)
			{
				strcpy(tempc,arr[i].name);
				strcpy(arr[i].name,arr[j].name);
				strcpy(arr[j].name,tempc);
				temp=arr[i].population;
				arr[i].population=arr[j].population;
				arr[j].population=temp;
				for (k=0;k<MAX_NEIGHBOR;k++)
				{
					strcpy(tempc,arr[i].neighbors[k]);
					strcpy(arr[i].neighbors[k],arr[j].neighbors[k]);
					strcpy(arr[j].neighbors[k],tempc);
				}
				temp=arr[i].flag;
				arr[i].flag=arr[j].flag;
				arr[j].flag=temp;
			}
			if (choice == 'p' && arr[j].population<arr[i].population)
			{
				strcpy(tempc,arr[i].name);
				strcpy(arr[i].name,arr[j].name);
				strcpy(arr[j].name,tempc);
				temp=arr[i].population;
				arr[i].population=arr[j].population;
				arr[j].population=temp;
				for (k=0;k<MAX_NEIGHBOR;k++)
				{
					strcpy(tempc,arr[i].neighbors[k]);
					strcpy(arr[i].neighbors[k],arr[j].neighbors[k]);
					strcpy(arr[j].neighbors[k],tempc);
				}
				temp=arr[i].flag;
				arr[i].flag=arr[j].flag;
				arr[j].flag=temp;
			}
		}
	return 0;
}
