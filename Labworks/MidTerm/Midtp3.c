#include <stdio.h>

double lwAvgW(int arr[],int size);
void sort(int arr[],int size);

int main (void)
{
	int arr[]={10,20,30,40,50};
	
	printf (" return : %f \n",lwAvgW(arr,5));
	return 0;
	
}

double lwAvgW(int arr[],int size)
{
	int i,toplam=0,j,toplam2=0,tempsize=size;
	
	if (size <=0)
	{
		return -1;
	}
	sort (arr,size);
	for (i=0;i<tempsize;i++)
	{
		for (j=0;j<tempsize-1;j++)
		{
			toplam2 += arr[j];
		}
		toplam += toplam2;
		tempsize--;
		toplam2=0;
	}

	return (double)toplam/(double)size;
}

void sort(int arr[],int size)
{
	int i,j,temp;
	for (i=0;i<size;i++)
	{
		for (j=i+1;j<size;j++)
		{
			if (arr[j]<arr[i])
			{
				temp = arr[i];
				arr[i] = arr [j];
				arr[j] = temp;	
			}
		}
	}
}
