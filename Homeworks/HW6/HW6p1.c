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
/*    Odevin birinci partinda histogram tarzi bir char array icindeki her   */
/*  elemandan kacar tane oldugunu bulan bir fonksiyon yaziyoruz..           */
/*                                                                          */
/*------------------------------------------------------------------------  */

/*--------------------------------------------------------------------------*/
/*                               Includes                                   */
/*--------------------------------------------------------------------------*/
#include <stdio.h>
/*---------------------------------------------------------------------------*/
/*                         Function Prototypes                               */
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
void freq(char* str, int* fr);

int main(void)
{
    int fr[37];

    char str[]="abCd Ef ghIj kLM nopr stuv yzwxq 123 4 5 6 7 890 00 ?? |";

    freq(str, fr);

    return 0;
}
void freq(char* str, int* fr)
{
    int i,j;
   /*en basta tum elemanlari 0 yapiyoruz ki her buldugumuzda 1 er tane artsin*/
    for (i=0;i<37;i++)
        fr[i]=0;
    i=0;
    while(str[i] != '\0')
    {/*Arrayimizin sonuna kadar devam eden dongu icinde her elemana ASCII
   degerine gore bakarak 37 elemana ayri if condition yapmaktan kurtuluyoruz.*/
        if((str[i]<=90 && str[i]>=65) || (str[i]>=97 && str[i]<=122))
        {/*harflerin ASCII degeri buyuk harfler icin 65 den 90 a kadar ve kucuk
            harfler icin 97 den 122 ye kadar oldugu icin array elemanimiz eger
            buyuk veya kucuk harf ise bu if e geliyor ve fr arrayimizde gerekli
            yere yaziliyor.*/
            for(j=0;j<26;j++)
            {/*burada ornegin a veya A harfi str[i] olsun.A nin ASCII degeri
    65 oldugu icin 65 +j diyoruz ve A  65 +0 a esit oldugu icin ve j=0 oldugu
        icin fr[j] yi yani a ve A icin ayirdigimiz yeri 1 artiriyoruz.Bu diger
        harfler icin de 65 +j diye gidip J sayisi da fr arrayimizdeki o harf
        icin ayirdigimiz array elemani olacagi icin direk fr[j] yi artiririz.*/
                if (str[i]==(65+j) || str[i]==(97+j))
                {
                    fr[j]++;
                }
            }
        }
        else if(str[i]<=57 && str[i]>=48)
        {/*Ayni sekilde rakamlarin da ASCII kodu 48 ile 58 arasinda oldugu icin
            ayni mantiktaki islemlerimizi sayilar icin de yapiyoruz.Fakat
            sayilarda fr arrayimizde 26 ve 36 arasi elemanlar ayrildigi icin
            eleman bulununca fr[j] yerine fr[26+j] ye esitliyoruz ki ornegin
            0 sayisi icin fr[26] elemanina yazilsin.*/
            for(j=0;j<10;j++)
            {
                if (str[i]==(48+j))
                {
                    fr[26+j]++;
                }
            }
        }
        else/* diger elemanlari da direk 36. elemani artirarak sayiyoruz.*/
            fr[36]++;
        i++;
    }
    for(i=0;i<37;i++)
        printf("%d ",fr[i]);
}

