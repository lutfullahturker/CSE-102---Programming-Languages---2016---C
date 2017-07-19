#include <stdio.h>

int lwSort(int* arr[],int size);

int main(void)
{
	int i1=19,i2=26,i3=9;
	int* arr[3];
	arr[0]=&i1;
	arr[1]=&i2;
	arr[2]=&i3;
	lwSort(arr,3);

	return 0;
}

int lwSort(int* arr[],int size)
{
	int i,j,*temp;
	if (arr == NULL || size<=0)
	return -1;
	else
	{
	for (i=0;i<size;i++)
	{
		for (j=0;j<size;j++)
		{
			if (*arr[j]>*arr[i])
			{
				temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
			}
		}
	}
	return 0;
	}
}

