#include <stdio.h>

int lwRev( int arr[],int size);


int main (void)
{
	int array[5]={1,4,2,3,5};

	lwRev(array,5);

	return 0;
}

int lwRev( int arr[],int size)
{
	int i,temp;
	
	if (arr != NULL && size >0)
	{
	for (i=0;i<size-2;i++)
	{
		temp=arr[i];
		arr[i]=arr[size-i-1];
		arr[size-i-1]=temp;
	}
	
	
	
	
	return 0;
	}
	else
		return -1;



}
