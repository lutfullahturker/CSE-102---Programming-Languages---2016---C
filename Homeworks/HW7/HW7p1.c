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

/*---------------------------------------------------------------------------*/
/*                         Function Prototypes                               */
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
int isPalindrome(char * str);

int main(void)
{
    printf("return =>> %d\n",isPalindrome("abTba"));
    return 0;
}

int isPalindrome(char * str)
{
    char temp[255];
    /* islemlerimizi temp stringi uzerinden yapiyoruz.Cunku fonksiyona
    gonderilen string bir degisken olarak gonderilmeyip direk "string" olarak
    gonderildiginde string degistirilemiyor.bu yuzden islemlerimizi temp
    stringi uzerinden yapiyor ve ana stringimizi degistirmiyoruz.*/
    int i,k=0;
    if (str[0]=='\0')
        return 0;
        /* bos string delirse direk 0 return ediyoruz.*/
    for(i=0;str[i]!='\0';i++)
        temp[i]=str[i];
        /* str elemanlarini temp e atiyoruz ve ikisini esitliyoruz.*/
    temp[i]='\0';/* esitlendikten sonra tempin son elemanina \0 koyarak temp
    stringini tam olarak olusturmus oluyouz.*/
    while ((temp[k]<'A' || (temp[k]>'Z' && temp[k]<'a') || temp[k]>'z') && k<i)
        k++;
        /* bu dongude k 0 dan baslayip harf bulana kadar ilerliyor.yani
        k degiskeni soldan bulunan ilk harfin indexi.*/
    if (i==k && temp[k]!='\0')
    	return 0;
    while ((temp[i]<'A' || (temp[i]>'Z' && temp[i]<'a') || temp[i]>'z') && i>=0)
        i--;
        /*bu dongude de ayni islemin sagdan olan halini yapiyoruz.sagdan harf
        bulana kadar i azaliyor.yani i sagdan bulunan ilk harf indexi.*/
    if (k+1>i )
        /* recursive durdurma sartlarimiz.soldaki index sagdakini gecmeye yani
        ortada bulustuklarinda bitiriyoruz.*/
    	return 1;
    else if (k+1==i && (temp[i]==temp[k] || temp[i]==temp[k]+32 || temp[i]==temp[k]-32))
        return 1;
    else if (temp[i]==temp[k] || temp[i]==temp[k]+32 || temp[i]==temp[k]-32)
    {
    /* sagdaki ve soldaki ilk bulunan harf indexleri birbirine esit veya
    biri buyuk digeri ayni harfin kucuguyse (+32  -32  buyuk harfle kucuk harf
    arasi ASCII farki) i 'yi yani sagdaki harf indexini null yaparak sagdan
    bir eleman azaltiyoruz ve fonksiyonu 1. elemandan itibaren cagirarak da
soldan bir eleman azaltarak cagiriyoruz ki k ve i indexleri tekrar bulunmasin*/
            temp[i]='\0';
            return isPalindrome(&temp[k+1]);
    }
    else
        /* eger sagdaki ve soldaki bulunan ilk harfler birbirine esit degilse
        direk 0 return ediyoruz. */
        return 0;
}
