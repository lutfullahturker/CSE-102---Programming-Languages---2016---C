#include <stdio.h>

int calc_hist(int sentinel,int* hist0,int*hist1,int* hist2,int* hist3
,int* hist4,int* hist5,int* hist6,int* hist7,int* hist8,int* hist9);

int main(void)
{
	int *hist0=0,*hist1=0,*hist2=0,*hist3=0,*hist4=0,*hist5=0,*hist6=0,*hist7=0,*hist8=0;
	int *hist9=0;
	
	printf("%d",calc_hist(-1,hist0,hist1,hist2,hist3,hist4,hist5,hist6,hist7,hist8,hist9));
	

	return 0;
}



int calc_hist(int sentinel,int* hist0,int*hist1,int* hist2,int* hist3
,int* hist4,int* hist5,int* hist6,int* hist7,int* hist8,int* hist9)
{
	int sayi,i=0;
	
	 *hist0=0;*hist1=0;*hist2=0;*hist3=0;*hist4=0;*hist5=0;*hist6=0;*hist7=0;*hist8=0;
	 *hist9=0;
	if (sentinel>=0 && sentinel<10)
	{
		return -2;
	}
	
	printf("sayi girin");
	scanf("%d",&sayi);
	
	if (sayi==sentinel)
	{
		return -1;
	}
	
	while (sayi!=sentinel)
	{
		if (sayi==0)
		{
			(*hist0)++;
		}
		if (sayi==1)
		{
			(*hist1)++;
		}
		if (sayi==2)
		{
			(*hist2)++;
		}
		if (sayi==3)
		{
			(*hist3)++;
		}
		if (sayi==4)
		{
			(*hist4)++;
		}
		if (sayi==5)
		{
			(*hist5)++;
		}
		if (sayi==6)
		{
			(*hist6)++;
		}
		if (sayi==7)
		{
			(*hist7)++;
		}
		if (sayi==8)
		{
			(*hist8)++;
		}
		if (sayi==9)
		{
			(*hist9)++;
		}
		printf("sayi girin");
		scanf("%d",&sayi);
		i++;
	}
	return i;
}
