#include <stdio.h>
#define PI 3.14


double cosine(int degree,int n);
double sine(int degree,int n);
void getInputs(int* degree, int* n, int* exit);

int main(void)
{
	int degree,n,exit;

	getInputs(&degree, &n, &exit);

	return 0;
}


void getInputs(int* degree, int* n, int* exit)
{
	*exit=0;
	
	char control;
	while (*exit==0)
	{
		scanf("%d %d",degree,n);
		
		sine(*degree,*n);
		cosine(*degree,*n);
		control = (char) *degree;
		if ( control=='e' || control=='E' || *n=='e' || *n=='E')
		{
			*exit=1;
		}
	}
}

double cosine(int degree,int n)
{
	int artieksi,i,ikiN,j,temp2;
	double cosine,toplam=0,radSayi,temp,fact;
	radSayi=(PI*(double) degree)/180;
	temp=radSayi;
	temp2=n;
	for (j = 0; j<=n; n--)
	{
		ikiN=2*n;
	if (n%2==1)
		artieksi=-1;
	if (n%2==0)
		artieksi=1;
	for (i = 1; i <=(ikiN-1); ++i)
	{
		radSayi*=temp;
	}
	if (ikiN==0)
    {
    	fact=1;
    	radSayi=1;
    }
    fact=1;
	 while (ikiN>1)
    { 
        fact*=ikiN*(ikiN-1);
        ikiN-=2; 
    }
    cosine =((double) artieksi* radSayi)/ fact;
    toplam+=cosine;
    radSayi=temp;
    }
    printf("cos(%d) where n is %d = %.4f\n",degree,temp2,toplam);
    return toplam;
}

double sine(int degree,int n)
{
	int artieksi,i,ikiN,j,temp2;
	double cosine,toplam=0,radSayi,temp,fact;
	radSayi=(PI*(double) degree)/180;
	temp=radSayi;
	temp2=n;
	for (j = 0; j<=n; n--)
	{
		ikiN=2*n;
	if (n%2==1)
		artieksi=-1;
	if (n%2==0)
		artieksi=1;
	for (i = 1; i <=(ikiN); ++i)
	{
		radSayi*=temp;
	}
	if (ikiN+1==1)
    {
    	fact=1;
    	radSayi=temp;
    }
    fact=1;
	 while (ikiN+1>1)
    { 
        fact*=(ikiN+1)*(ikiN);
        ikiN-=2; 
    }
    cosine =((double) artieksi* radSayi)/ fact;
    toplam+=cosine;
    radSayi=temp;
    }
    printf("sin(%d) where n is %d = %.4f\n",degree,temp2,toplam);
    return toplam;
}
