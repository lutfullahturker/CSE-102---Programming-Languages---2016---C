/* -----------------------------------------------------------------------  */
/*                                                                          */
/*                   HW06_141044050_Lütfullah_Türker                        */
/*                                                                          */
/*                                                                          */
/* -----------------------------------------------------------------------  */
/*                Created on 8/04/2016 by Lütfullah_Türker                  */
/*                                                                          */
/* Description                                                              */
/* -----------------------------------------------------------------------  */
/* Odevin ucuncu partinda bir char arrayin baska bir char array icinde cift */
/* sayili indisleri esit bir sekilde kac kere bulundugunu kontrol ediyoruz  */
/*                                                                          */
/*------------------------------------------------------------------------  */

/*--------------------------------------------------------------------------*/
/*                               Includes                                   */
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
/*---------------------------------------------------------------------------*/
/*                         Function Prototypes                               */
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
int count(char* str, char* substr);

int main (void)
{
   printf("return =>> %d",count("ececece","ece"));

    return 0;
}
int count(char* str, char* substr)
{/*bu fonksiyon part 2 deki fonksiyonla ayni olup sadece istenilene gore
    biraz degistirilmis halidir.*/
    int i,j,count,temp,sum=0;
    /*Eger ikinci string ilkinden uzunsa direk 0 return ediyoruz cunku zaten
    ikinci daha uzunsa ilkinin icinde bulunma ihtimali yoktur.*/
    if (strlen(str) < strlen(substr))
        return 0 ;
    for(i=0;i<strlen(str);i++)
    {/* bu dongude str icin elemanlari teker teker artirip substr nin
        ilk elemanina esit mi diye bakiyoruz.Esit oldugunda ise asagidaki if
        icine girip oradaki donguyu gerceklestirecek.*/
        count=0;/* eger esitse ve asagida count ve j degerleri degisip dongu
    basa sardigi icin her esit oldugunda bu degerleri 0 yapmamiz gerekiyor.*/
        count=0;
        j=0;
        if (str[i]==substr[0])
        {/*burada substr nin ilk elemani str de bulunduktan sonra 2 index
            atlaya atlaya eslesme kontrollerine basliyoruz.*/
            count++;/* eslesme sayisi sayacimizi ilk eleman bulunup eslestigi
            icin 1 artiriyoruz.*/
            temp=i;/* i degeri iceride degisecegi ve daha sonra ilk i degeri
            lazim oldugu icin burada temp kullaniyoruz ki i degismesin.*/
            while(j<strlen(substr))
            {/* substr nin sonuna gelene kadar 2 index atlaya atlaya kontrol
                yaptigimiz dongu. */
                j+=2;    temp+=2;
                if (temp<strlen(str) && j<strlen(substr))
                {/*eger 2 index atlamis hali birbirine esitse count sayacimizi
                   yine 1 artiriyoruz ve her esit oldugunda 1 artmis oluyor. */
                    if(substr[j]==str[temp])
                        count++;
                }
            }
            if (j/2==count)
                /* burada sayacimiz her 2 elemanda bir eslesip 1 arttigi icin
                ve J de toplam harf sayimiza esit oldugu icin  harf sayisi/2
                tum elemanlarin eslestigi durumda count a esit olacaktir.
            Esit degilse 2 index artmis durumlarindan en az birinde str
                ve substr nin elemanlari birbirine esit olmamis ve count da bu
                durumda eksik olmus olacak. */
                sum++;/* esitseler substr str nin icinde bulundu demek ve kac
            tane bulundugunu hesaplamak icin sum degiskenini 1 artiriyoruz ve
            donguye devam ediyoruz. */
        }
    }
    return sum ;/*en sonunda substr str nin icinde sum kadar bulunup donguden
    cýkacak ve biz de sum u return edecegiz. */

}
