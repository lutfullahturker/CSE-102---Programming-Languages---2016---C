#include <stdio.h>

void triangle( int width);

int main(void)
{	int sayi;
	while (1)
	{
	printf("sayi gir  :");
	scanf("%d",&sayi);
	triangle(sayi);
	}
	return 0;
}


void triangle( int width)
{
	int j,i,k,l;
	j=width/2;
	l=width-2;
	for (i=1;i<=width/2;i++)
	{
		for (k=0;k<j;k++)
		{
			printf(" ");
		}	
		printf("*");
	if (i!=1)
	{
		for (k=width-2;k<=l;k++)
		{
			printf(" ");
		}
		printf("*");
		l=l+2;
	}
	j--;
	printf("\n");
	}
	for (i=0;i<width;i++)
	{
	printf("*");
	}
	printf("\n");
}
