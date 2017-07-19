#include <stdio.h>
#define PI 3.14

double cosine(int degree,int n); /*   fonksiyon prototiplerini tanımlıyoruz . */
double sine(int degree,int n);
void getInputs(int* degree, int* n, int* exit);


int main(void)
{
	int degree,n,exit;
	exit=0;
	while (exit==0)
	{
	getInputs(&degree, &n, &exit);
	sine(degree,n);
	cosine(degree,n);
	}
	return 0;
}

void getInputs(int* degree, int* n, int* exit)
{
	*exit= scanf("%d %d",degree,n);  /*  cikis degerini kontrol etmek icin */
	                    /* exit degiskenimizi inputlarimiza atiyoruz. */
		if ( *exit==0)
		{   /* scanf fonksiyonunun degeri 0 a esit olursa exit'i donguden */
		    /* cikmasi icin 1 yapiyoruz ve programi sonlandiriyor. */
			*exit=1;
		}
	*exit=0; /*program dogru calistigi surece exit degerimizin 0 olmasini istiyoruz*/
}

double cosine(int degree,int n)
{
	int artieksi,i,ikiN,j,temp2,degree2; /* gerekli degiskenlerimizi tanimliyoruz . */
	double cosine,toplam=0,radSayi,temp,fact;
	degree2=degree%360;/* 360 dan buyuk sayi girildiginde 360a bolup 
	                    kalani aliyoruz*/
	radSayi=(PI*(double) degree2)/180; /* girilen aciyi radyan cinsine ceviriyoruz.*/
	temp=radSayi;/*dongulerde sayimiz degisecegi icin temp degiskenine atiyoruz*/
	temp2=n; /* n degeri de degisecegi icin n yi temp2 ye atiyoruz. */
	for (j = 0; j<=n; n--)  /* tum dongumuz n sayisi kadar tekrar edecegi*/
	        /* icin herseyi bu dongu icine aliyoruz. */
	{
		ikiN=2*n;
	if (n%2==1)
	/* -1^n sayisinin +1 mi yoksa -1 mi oldugunu belirledigimiz sartlar.*/
		artieksi=-1;
	if (n%2==0)
		artieksi=1;
	for (i = 1; i <=(ikiN-1); ++i)
	{   /* x^2n sayisini elde ettigimiz for dongumuz 2n ye gelene kadar */
	    /* kendi kuvvetini alarak devam ediyor. */
		radSayi*=temp;
	}
	if (ikiN==0)
    {   /* n 0 girildiginde istisna sonuclar olustugu icin bunları */
        /* onlemek icin  0  a ayri sonuclar atiyoruz. */
    	fact=1;
    	radSayi=1;
    }
    fact=1;
	 while (ikiN>1)
    {   /* 2n  faktoriyeli aldigimiz dongu. Her seferinde 2n yi 1 eksilterek*/
        /* carpiyor ve 2n yi 2 azaltip 1 e gelene kadar devam ettirip */
        /*  faktoriyelini almis oluyoruz*/
        fact*=ikiN*(ikiN-1);
        ikiN-=2; 
    }
    cosine =((double) artieksi* radSayi)/ fact;/* en sonunda kosinus degerini*/
        /* hesapladigimiz formulu yaziyoruz. */
    toplam+=cosine; /* ve her seferinde toplam sembolu isleminin yapilmasi  */
        /* her bir n degerinde bulunan sonucu topluyoruz ve toplam sembolu*/
        /* ile olan islemlerimizi bitirmis oluyoruz. */
    radSayi=temp;  /* dongu basa donerken sayimiz degistigi icin ilk haline*/
    /* geri getirip oyle dongunun basina gonderiyoruz. */
    }
    printf("cos(%d) where n is %d = %.4f\n",degree,temp2,toplam);
    return toplam;
}

double sine(int degree,int n)
{
	int artieksi,i,ikiN,j,temp2,degree2; /* gerekli degiskenlerimizi tanimliyoruz . */
	double sine,toplam=0,radSayi,temp,fact;
	degree2=degree%360;/* 360 dan buyuk sayi girildiginde 360a bolup 
	                    kalani aliyoruz*/
	radSayi=(PI*(double) degree2)/180;/* girilen aciyi radyan cinsine ceviriyoruz.*/
	temp=radSayi;/*dongulerde sayimiz degisecegi icin temp degiskenine atiyoruz*/
	temp2=n;/* n degeri de degisecegi icin n yi temp2 ye atiyoruz. */
	for (j = 0; j<=n; n--)/* tum dongumuz n sayisi kadar tekrar edecegi*/
	        /* icin herseyi bu dongu icine aliyoruz. */
	{
		ikiN=2*n;
	if (n%2==1)
	/* -1^n sayisinin +1 mi yoksa -1 mi oldugunu belirledigimiz sartlar.*/
		artieksi=-1;
	if (n%2==0)
		artieksi=1;
	for (i = 1; i <=(ikiN); ++i)
	{/* x^2n sayisini elde ettigimiz for dongumuz 2n ye gelene kadar */
	    /* kendi kuvvetini alarak devam ediyor. */
		radSayi*=temp;
	}
	if (ikiN+1==1)
    {/* n 0 girildiginde istisna sonuclar olustugu icin bunları */
        /* onlemek icin  0  a ayri sonuclar atiyoruz. */
    	fact=1;
    	radSayi=temp;
    }
    fact=1;
	 while (ikiN+1>1)
    { /* 2n  faktoriyeli aldigimiz dongu. Her seferinde 2n yi 1 eksilterek*/
        /* carpiyor ve 2n yi 2 azaltip 1 e gelene kadar devam ettirip */
        /*  faktoriyelini almis oluyoruz*/
        fact*=(ikiN+1)*(ikiN);
        ikiN-=2; 
    }
    sine =((double) artieksi* radSayi)/ fact;/* en sonunda sinus degerini*/
        /* hesapladigimiz formulu yaziyoruz. */
    toplam+=sine;/* ve her seferinde toplam sembolu isleminin yapilmasi  */
        /* her bir n degerinde bulunan sonucu topluyoruz ve toplam sembolu*/
        /* ile olan islemlerimizi bitirmis oluyoruz. */
    radSayi=temp;/* dongu basa donerken sayimiz degistigi icin ilk haline*/
    /* geri getirip oyle dongunun basina gonderiyoruz. */
    }
    printf("sin(%d) where n is %d = %.4f\n",degree,temp2,toplam);
    return toplam;
}
