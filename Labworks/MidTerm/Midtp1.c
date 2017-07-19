#include <stdio.h>

int dotProduct(int A[],int B[],int* AB,int sizeA,int sizeB);

int main (void)
{
	int A[]={1,2,3};
	int B[]={11,12,13,14,27};
	int AB;
	
	printf("return : %d \n",dotProduct(A,B,&AB,3,3));

	return 0;
}

int dotProduct(int A[],int B[],int* AB,int sizeA,int sizeB)
{
	int i;

	if (A==NULL || B==NULL || sizeA==0 || sizeB==0 || sizeA != sizeB)
	{
		return (-1);
	}
	else 
	{
	for (i=0;i<sizeA;i++)
	{
		*AB += A[i]*B[i];
	}
	printf("Dot product result (AB) : %d\n",*AB);
	return 0;
	}
}
