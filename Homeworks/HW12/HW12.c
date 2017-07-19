/* -----------------------------------------------------------------------  */
/*                                                                          */
/*                   HW12_141044050_Lutfullah_Turker                        */
/*                                                                          */
/*                                                                          */
/* -----------------------------------------------------------------------  */
/*                Created on 20/05/2016 by Lutfullah_Turker                 */
/*                                                                          */
/* Aciklama                                                                 */
/* -----------------------------------------------------------------------  */
/* Bu odevde bir dosyadan oyuncu bilgileri okuyarak bilgileri bir linked    */
/*  list structure a atiyoruz.Ve binary bir dosyaya buyukten kucuge dogru   */
/*                          siralayarak yaziyoruz.                          */
/*                                                                          */
/*                                                                          */
/*------------------------------------------------------------------------  */

/*--------------------------------------------------------------------------*/
/*                               Includes                                   */
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct player_scores{
	char  name[30];
	double  *scores;
	int size;
	double average;
	struct player_scores * next;
} PlayerScores;

PlayerScores* useMalloc();
void fillStruct (FILE * filep,PlayerScores * a);
void findAverage(PlayerScores * a);
void SortingAndWriteBinary(FILE * filep2,PlayerScores * a);

int main()
{
    FILE *filep,*filep2;
    PlayerScores *a,*b;
    /* okuyacagimiz dosyayi fopen ile okuma modunda aciyoruz. */
    filep=fopen("input.txt","r");
    if (filep == NULL)
	{
		printf("input file open error !!\n");
		return 0;
	}
	/* linked list icin structure imizi pointer tanimlayip dinamik olarak 
	bunlara yer ayiriyoruz. */
    a=useMalloc();
    b=a;
    /* linked listimizin ilk elemanini kaybetmememiz icin b nin adresini a nin
    adresine atiyoruz ve ilk elemanimiz a degisse de b de kaliyor. */
    fillStruct(filep,a);
    /* linked list struct pointer imizi ve bilgileri alacagimiz dosyamizi 
    gonderiyoruz ve linked listimizi dolduruyoruz. */
	fclose(filep);
	a=b;
	/*yukariraki fonksiyonda a nin adresi degistigi icin geri dondugunde tekrar
	a ya  ilk elemanin adresi olan b yi atiyoruz. */
	findAverage(a);
	/* her elemanin averagesini de yukaridaki fonksiyonla buluyoruz. */
	a=b;
	filep2=fopen("output.bin","w");
	/* sirali bir sekilde binary dosyaya asagidaki fonksiyonla yaziyoruz. */
	SortingAndWriteBinary(filep2,a);
	fclose(filep2);
    return 0;
}
PlayerScores* useMalloc()
{/* isimizi kolaylastirmak icin pointerlerimizi direk bu malloc fonksiyonuna
esitliyorum. */
	return (PlayerScores*)malloc(sizeof(PlayerScores));
}
void fillStruct (FILE * filep,PlayerScores * a)
{
	int i;
    char endOfLine;

	while (!feof(filep))
    {
        /* !feof(filep) ile dosyanin sonuna gelmedigi surece devam edecek bir
        dongu olusturuyoruz. */
		fscanf(filep,"%s",a->name);
		/* oyuncu adini okuyoruz. endofline karakteri dongu basa geldiginde 
		hala '\n' olarak kalacagi icin her basa sardiginda rasgele bir harfe
		's' ye atadim . */
		endOfLine = 's';
		a->scores=(double *) malloc(30*sizeof(double));
		for (i=0;endOfLine != '\n' && i<30 && !feof(filep);i++)
		{/* alt satira gecene kadar 1 sayi ve bosluk karakterini okuyoruz.
		bosluk karakteri yerine \n okudugunda dongu basa sarip siradaki
		oyuncuya geciyor.*/
			fscanf (filep,"%lf",&a->scores[i]);
			fscanf (filep,"%c",&endOfLine);
		}
		a->size = i;
        /* dongu bittiginde i sayisi toplam okunan eleman sayisina esit olcagi
        icin size yi i ye esitliyoruz. */
		if (!feof(filep))
		{
			a->next = useMalloc();
			a=a->next;
		}
	}/* son elemani anlamak icin NULL karakterine atiyoruz. */
	a = NULL;
}
void findAverage(PlayerScores * a)
{/*basit bir sekilde tum sayilari toplayip eleman sayisina bolup avg buluyor.*/
	int i;
	double sum;
	while (a != NULL)
	{
	sum=0.0;
	for (i=0;i<(a->size);i++)
	{
		sum += a->scores[i];
	}
	a->average = sum / (double) a->size;
	a = a->next;
	}
}
void SortingAndWriteBinary(FILE * filep2,PlayerScores * a)
{
	PlayerScores *temp,*c,*b;
	double max=a->average;
	int *count=(int*)malloc(sizeof(int)),i=0;
	*count = 1;
	c = a;
	b = a;
	/* ilginc bir sekilde dongu sartini c != NULL yaptigimda dongu 1 kere fazla
	dondugu icin count tutmak zorunda kaldim.  */
	while ( i < *count )
	{   *count=0;
		while (a != NULL)
		{/* bu dongunun 1 kere fazla donmesinin bir zarari olmayacagi icin buna
        		dokunmadim */
			if (a->average >= max)
			{/* elemainin avg si max dan daha buyukse onu max yapiyoruz ve bu
			donguden listenin tum elemanlarindan en buyuk average ye sahip olan
			elemani buluyoruz.*/
				max=a->average;
				temp = a;
			}
			a = a->next;
			(*count) ++ ;
		}
		/* donguden ciktiginda en buyuk elemani dosyaya yazip onun averagesini
		0 yapiyoruz ki bir sonraki en buyugu bulabilelim.Bu sekilde bir sonraki
		buyugu yaza yaza tum elemanlar buyukten kucuge dogru yazilmis oluyor.*/
		fwrite (temp,sizeof(PlayerScores),1,filep2);
		temp->average = 0;
		a = b;
		c = c->next;
		max = b->average;
		i++;
		(*count) --;
	}
	free(count);
}