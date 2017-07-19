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
/*   Ikinci partda bir char arrayin baska bir char array icinde cift        */
/* sayili indisleri esit bir sekilde bulunup bulunmadigini kontrol ediyoruz */
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
char* matcher(char* haystack, char* needle);


int main (void)
{
    char* ptr = matcher("lorem ipsum dolor sit amet.", "ihsamedal");
    printf("%s\n",ptr);

    return 0;
}
char* matcher(char* haystack, char* needle)
{
    int i,j,count,temp;
    /*Eger ikinci string ilkinden uzunsa direk NULL return ediyoruz cunku zaten
    ikinci daha uzunsa ilkinin icinde bulunma ihtimali yoktur.*/
    if (strlen(haystack) < strlen(needle))
        return NULL ;
    for(i=0;i<strlen(haystack);i++)
    {/* bu dongude haystack icin elemanlari teker teker artirip needle nin
        ilk elemanina esit mi diye bakiyoruz.Esit oldugunda ise asagidaki if
        icine girip oradaki donguyu gerceklestirecek.*/
        count=0;/* eger esitse ve asagida count ve j degerleri degisip dongu
    basa sardigi icin her esit oldugunda bu degerleri 0 yapmamiz gerekiyor.*/
        j=0;
        if (haystack[i]==needle[0])
        {/*burada needle nin ilk elemani haystack de bulunduktan sonra 2 index
            atlaya atlaya eslesme kontrollerine basliyoruz.*/
            count++;/* eslesme sayisi sayacimizi ilk eleman bulunup eslestigi
            icin 1 artiriyoruz.*/
            temp=i;/* i degeri iceride degisecegi ve daha sonra ilk i degeri
            lazim oldugu icin burada temp kullaniyoruz ki i degismesin.*/
            while(j<strlen(needle))
            {/* needle nin sonuna gelene kadar 2 index atlaya atlaya kontrol
                yaptigimiz dongu. */
                j+=2;    temp+=2;
                if (temp<strlen(haystack))
                {/*eger 2 index atlamis hali birbirine esitse count sayacimizi
                   yine 1 artiriyoruz ve her esit oldugunda 1 artmis oluyor. */
                    if(needle[j]==haystack[temp])
                        count++;
                }
            }
            if (j/2==count)
                /* burada sayacimiz her 2 elemanda bir eslesip 1 arttigi icin
                ve J de toplam harf sayimiza esit oldugu icin  harf sayisi/2
                tum elemanlarin eslestigi durumda count a esit olacaktir.
            Esit degilse 2 index artmis durumlarindan en az birinde haystack
                ve needle nin elemanlari birbirine esit olmamis ve count da bu
                durumda eksik olmus olacak ve return etmeyecektir. */
                return &haystack[i];/* eslestikten sonra ilk eslesen elemandan
            itibaren haystack i return ediyoruz.*/
        }
    }
    return NULL ;
    /*eger eslesmezse fonksiyon buraya kadar gelip NULL return edecek. */
}
