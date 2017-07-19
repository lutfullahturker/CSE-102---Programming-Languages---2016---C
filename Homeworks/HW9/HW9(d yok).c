/* -----------------------------------------------------------------------  */
/*                                                                          */
/*                   HW09_141044050_Lutfullah_Turker                        */
/*                                                                          */
/*                                                                          */
/* -----------------------------------------------------------------------  */
/*                Created on 25/04/2016 by Lutfullah_Turker                 */
/*                                                                          */
/* Aciklama                                                                 */
/* -----------------------------------------------------------------------  */
/*    9.odevde bir ulke struct i olusturuyor ve ulkenin belirli bilgilerini */
/*          yazarak ulkeler arasinda en yuksek alana veya askere sahip      */
/*          ulkeyi belirliyoruz.                                            */
/*                                                                          */
/*------------------------------------------------------------------------  */


/*--------------------------------------------------------------------------*/
/*                               Includes                                   */
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

#define COUNTRYSIZ 100

typedef struct{
    char name[25];
    int population;
    int area;
    int military;
    char neighbours[10][25];
} country_t;
/*---------------------------------------------------------------------------*/
/*                         Function Prototypes                               */
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
void addCountry(country_t *country);
void findPowerfulMilitary(country_t const countryArr[]);
void findTheLargestArea(country_t const countryArr[]);

int main (void)
{/* donguye girisi baslatmasi icin e disinda rasgele bir harf tanimliyoruz.*/
    char choice='k';
    int i=0;
    country_t countries[COUNTRYSIZ];
/* en fazla 100 ulkemizi kaydedecegimiz 100luk ulke arrayimizi olusturuyoruz.*/
    while (choice != 'e')
    { /*  choice secimimiz e olmadigi surece programimiz calisiyor ve e
        girildiginde Good Bye yazarak programdan cikiliyor. */
        printf("Make your choice:\n");
        scanf(" %c",&choice);
        switch(choice)
        {/* a girildiginde kullanicidan yeni bir ulke girilmesini isteyen
            addCountry fonksiyonumuz cagriliyor ve i sayisi 1 artiriliyor ki
    bir sonraki ulke girisinde yeni bilgiler ayni ulkenin uzerine yazilmasin*/
        case 'a':
            if (i<COUNTRYSIZ)
                addCountry(&countries[i++]);
            else
           /*array en fazla 100 ulke aldigi icin 100 den fazla ulke girilmesini
                bu if else ile engelliyoruz. */
                printf("Maximum number of country is reached !!");
            break;
        case 'b':
            /* b girildiginde en fazla askere sahip olan ulkenin hesaplandigi
            fonksiyonumuzu cagriyoruz. */
            findPowerfulMilitary(countries);
            break;
        case 'c':
            /* c girildiginde en fazla alana sahip olan ulkenin hesaplandigi
            fonksiyonumuzu cagriyoruz. */
            findTheLargestArea(countries);
            break;
        case 'd':
            break;
        case 'e':
            printf("Good Bye");
            break;
        default:
            printf("You have entered wrong key.\nPlease enter a,b,c,d or e\n");
        }
    }
    return 0;
}

void addCountry(country_t *country)
{/* name population area ve military bilgilerini tek scanf ile kolayca
    kullanicidan istiyoruz. */
    int i=0;
    scanf("%s%d%d%d",country->name,&country->population,&country->area,
          &country->military);
    /*neighbour bilgilerini ise neighbour sayisi bilinmedigi icin while ile
    10 a kadar veya -1 girilene kadar kullanicidan neighbour arrayini
  doldurmasini istiyoruz. -1 veya 10 tane komsu girildiginde donguden cikiyor*/
    while (i<10 && strcmp(country->neighbours[i-1],"-1")!=0)
        scanf("%s",country->neighbours[i++]);
}

void findPowerfulMilitary(country_t const countryArr[])
{/*komsularinin ve onlarin komsulari arasinda military kiyaslamasi yapmak icin
    ulke arrayimizi const olarak gonderiyoruz.*/
    char country[25],temp[25];
    /*kiyaslama yapilacak ulkeyi kullanicidan istemek icin country degiskenini,
  maximum military ye sahip ulkeyi kaydetmek icin temp degiskenini kullandim.*/
    int i,found=0,maxMilitary,j,k,l,m;
    while (found==0)
    {/* ulkeyi kullanicidan alirken ulke arrayinde olmayan bir ulke girilirse
        if e girip ulke bulunamadi diyerek tekrar kullanicidan ulke girmesini
        istiyor.Eger ulke arrayinde girilen ulke bulunursa found 1 olup
     donguden cikiyor ve o ulkenin arraydeki indexini (i-1) olarak buluyoruz.*/
        scanf("%s",country);
        for(i=0;i<COUNTRYSIZ && strcmp(countryArr[i-1].name,country) !=0;i++){}
        if (strcmp(countryArr[i-1].name,country) !=0 && i==COUNTRYSIZ)
            printf("Country is not found.Try again.\n");
        else
            found =1;
    }
    /*girilen ulkenin military sini karsilastirmak icin maxMilitary ye atiyoruz
    ve ismini de tempe atiyoruz.*/
    maxMilitary=countryArr[i-1].military;
    strcpy(temp,countryArr[i-1].name);
    for (j=0;j<10 && strcmp(countryArr[i-1].neighbours[j],"-1") != 0;j++)
    {/*komsulari arasinda gezip kiyaslama yapmak icin 0dan 10 a kadar veya
        -1 sayisini gorene kadar komsulari arasinda karsilastirma yapiyoruz.*/
        for(k=0;k<COUNTRYSIZ && strcmp(countryArr[k-1].name,
                        countryArr[i-1].neighbours[j]) !=0;k++){}
        /*bu for dongusu ile komsunun ulke arrayindeki indexi bulunuyor.
        ve komsu, ulke arrayi icinde yoksa rasgele bir deger atmamasi icin
        asagidaki if e giriyor ve else if e girmemesini sagliyoruz.*/
        if (strcmp(countryArr[k-1].name,countryArr[i-1].neighbours[j]) !=0
                        && k==COUNTRYSIZ){}
        /*eger komsu , ulke arrayinde bulunursa ve maxMilitary den daha buyukse
       maxMilitary yi komsunun military si yapiyor ve tempimizi de komsunun adi
        yapiyoruz.*/
        else if (maxMilitary<countryArr[k-1].military)
        {
            maxMilitary=countryArr[k-1].military;
            strcpy(temp,countryArr[k-1].name);
        }
        if (strcmp(countryArr[k-1].name,countryArr[i-1].neighbours[j]) ==0
                        && k!=COUNTRYSIZ)
        {/* eger komsunun adi girilen ulkenin j. komsusunun adiyla eslesiyorsa
            yani komsu ulke, a secenegi ile kaydedildiyse */
            for(m=0;m<10 && strcmp(countryArr[k-1].neighbours[m],"-1") !=0;m++)
            {/* komsunun komsulari arasinda da karsilastirma yapmak icin bu
                donguyu kullaniyoruz.yukaridaki ayni durumlari burada da
                komsunun komsulari icin tekrarliyoruz ve her komsu gectiginde
                onun komsularina da bakip kontrol ediyor.*/
                for (l=0;l<COUNTRYSIZ && strcmp(countryArr[k-1].neighbours[m],
                        countryArr[l-1].name)!=0;l++){}
                if (strcmp(countryArr[k-1].neighbours[m],
                        countryArr[l-1].name)!=0 && l==COUNTRYSIZ){}
                else if (maxMilitary<countryArr[l-1].military)
                {
                    maxMilitary=countryArr[l-1].military;
                    strcpy(temp,countryArr[l-1].name);
                }
            }
        }
    }
/* ve fonksiyonun sonunda maxMilitary ye sahip komsu ulkenin adini tuttugumuz
   temp degiskenini ekrana basiyoruz.*/
    printf("%s\n",temp);
}

void findTheLargestArea(country_t const countryArr[])
{
    /* bu fonksiyon Military fonksiyonun tamemen aynisi olup sadece military
    degiskenlerinin area yapilmis halidir.yukaridaki hersey aynen gecerlidir.*/
    char country[25],temp[25];
    int i,found=0,maxArea,j,k,l,m;
    while (found==0)
    {
        scanf("%s",country);
        for(i=0;i<COUNTRYSIZ && strcmp(countryArr[i-1].name,country) !=0;i++){}
        if (strcmp(countryArr[i-1].name,country) !=0 && i==COUNTRYSIZ)
            printf("Country is not found.Try again.\n");
        else
            found =1;
    }
    maxArea=countryArr[i-1].area;
    strcpy(temp,countryArr[i-1].name);
    for (j=0;j<10 && strcmp(countryArr[i-1].neighbours[j],"-1") != 0;j++)
    {
        for(k=0;k<COUNTRYSIZ && strcmp(countryArr[k-1].name,
                        countryArr[i-1].neighbours[j]) !=0;k++){}
        if (strcmp(countryArr[k-1].name,countryArr[i-1].neighbours[j]) !=0
                        && k==COUNTRYSIZ){}
        else if (maxArea<countryArr[k-1].area)
        {
            maxArea=countryArr[k-1].area;
            strcpy(temp,countryArr[k-1].name);
        }
        if (strcmp(countryArr[k-1].name,countryArr[i-1].neighbours[j]) ==0
                        && k!=COUNTRYSIZ)
        {
            for(m=0;m<10 && strcmp(countryArr[k-1].neighbours[m],"-1") !=0;m++)
            {
                for (l=0;l<COUNTRYSIZ && strcmp(countryArr[k-1].neighbours[m],
                        countryArr[l-1].name)!=0;l++){}
                if (strcmp(countryArr[k-1].neighbours[m],
                        countryArr[l-1].name)!=0 && l==COUNTRYSIZ){}
                else if (maxArea<countryArr[l-1].area)
                {
                    maxArea=countryArr[l-1].area;
                    strcpy(temp,countryArr[l-1].name);
                }
            }
        }
    }
    printf("%s\n",temp);
}

