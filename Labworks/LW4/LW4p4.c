#include <stdio.h>

void rect(int width);
void triangle( int width);
void pine (int width,int triangle_n);

int main(void)
{
	pine (15,4);


return 0;
}

void pine (int width,int triangle_n)
{
	int i;
	for (i=0;i<triangle_n;i++)
	{
		triangle(width);
	}
	rect(width);



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

void rect(int width)
{	int i,j=0,k=0,f,a,b,l;
	{
	while (j!=width/4+1)
		{
			printf(" ");
			j++;
		}
	while (k<width/2)
	{
		printf("*");
		k++;
	}
	printf("\n");
	for(i=0;i<width/2-2;i++)
	{
		for (a=0;a!=width/4+1;a++)
		{
			printf(" ");
			
		}
		printf("*");
		for (f=0;f<width/2-2;f++)
		{
			printf(" ");
		}
		printf("*\n");
	}
	for (b=0;b!=width/4+1;b++)
		{
			printf(" ");
			
		}
	for (l=0;l<width/2;l++)
	{
		printf("*");
	
	}
	printf("\n");
	}
}
