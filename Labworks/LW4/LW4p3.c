#include <stdio.h>

void rect(int width,int height,int spacing_left);


int main(void)
{
	rect(6,5,2);


return 0;
}

void rect(int width,int height,int spacing_left)
{	int i,j=0,k=0,f,a,b,l;
	if (width>=3 && height >=3)
	{
	while (j!=spacing_left)
		{
			printf(" ");
			j++;
		}
	while (k<width)
	{
		printf("*");
		k++;
	}
	printf("\n");
	for(i=0;i<height-2;i++)
	{
		for (a=0;a!=spacing_left;a++)
		{
			printf(" ");
			
		}
		printf("*");
		for (f=0;f<width-2;f++)
		{
			printf(" ");
		}
		printf("*\n");
	}
	for (b=0;b!=spacing_left;b++)
		{
			printf(" ");
			
		}
	for (l=0;l<width;l++)
	{
		printf("*");
	
	}
	printf("\n");
	}

}
