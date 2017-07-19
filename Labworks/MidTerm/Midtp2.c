#include <stdio.h>

int fac(int num);
int absolute(int num);
int power (int base,int exponent);
int f(int x);

int main (void)
{
	int num= -6;
	printf("fact == %d \n abs = %d\n pow : %d \n\n\n",fac(num),absolute(num),power(2,5));
	printf("fonksiyon sonucu :::: %d\n",f(num));

	return 0;
}

int fac(int num)
{
	int i,fact=1;
	for (i=1;i<=num;i++)
	{
		fact *= i;
	}
	return fact;
}

int absolute(int num)
{
	int abs;
	if (num < 0)
	{
		abs = num/(-1);
	}
	else 
	abs = num;
	
	return abs;
}
int power (int base,int exponent)
{
	int pow=1,i;
	for (i=1;i<=exponent;i++)
	{
		pow *= base;
	}
	return pow;
}

int f(int x)
{
	int i,otherwise=0;
	
	if (x>=0 && x<=8 && x%2==1)
	{
		return fac(x);
	}
	else if (x>=0 && x<=8 && x%2==0)
	{
		return power(x,((x/2)+1));
	}
	else
	{
		for (i=0; i<=absolute(x);i++)
		{
			otherwise += (i+1);
		}
		return otherwise;
	}

}


