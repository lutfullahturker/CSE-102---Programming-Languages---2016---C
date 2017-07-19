/* -----------------------------------------------------------------------  */
/*                                                                          */
/*                   HW03_141044050_Lütfullah_Türker                        */
/*                                                                          */
/*                                                                          */
/* -----------------------------------------------------------------------  */
/*                Created on 5/03/2016 by Lütfullah_Türker                  */
/*                                                                          */
/* Description                                                              */
/* -----------------------------------------------------------------------  */
/*    For the first part of the homework III, which are used for checking   */
/*  if the number is an odd,a factorial or a narcissistic number..          */
/*                                                                          */
/*------------------------------------------------------------------------  */

/*--------------------------------------------------------------------------*/
/*                               Includes                                   */
/*--------------------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>

/*---------------------------------------------------------------------------*/
/*                         Function Prototypes                               */
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

char verify(void);   /* devam etmek istiyor musunuz diye sordugumuz fonksiyon*/
char narcissisticNum(int number); /* narcissistic sayi bulma fonksiyonu*/
char factorialNum(int number); /* faktoriyel hesapladigimiz fonksiyon*/
char oddNum(int number); /* sayi tek mi cift mi diye kontrol ettigimiz fonk. */


int main(void)
{
    int number;        /* Programa girilen üzerinde islem yapilacak sayi*/
    char choice;/*Devam etmek isteyip istenmedigini
                    kontrol eden secim degiskeni*/
    int choosenNum;/*Programin yapacagi görevi belirtmek için seçtigimiz sayi*/

    printf("************************************************\n");
    printf("*                  WELCOME!                    *\n");
    printf("* This program checks whether the given number *\n");
    printf("*is an odd,a factorial or a narcissistic number*\n");
    printf("*                                              *\n");
    printf("************************************************\n");

    choice='y';  /* programimizin dongusunun baslamasi icin baslangicta  */
                /* secim degerini y yapip donguyu baslatiyoruz*/
    while(choice=='y'|| choice=='Y')
    {
        printf("\nPlease enter a positive integer  :");
        scanf("%d",&number);

        if (number>=0)  /* sayi 0'dan buyuk ise program devam ediyor */
        {
            printf("Which property would you like to check?\n1)Odd Number\n");
            printf("2)Factorial Number\n3)Narcissistic Number\n");
            printf("Please enter (1/2/3): ");
            /*sayi ile hangi islemi yapmak istedigimizi kullaniciya soruyoruz*/
            scanf("%d",&choosenNum);
            if (choosenNum==1)
            {
                choice=oddNum(number);
            }
            else if (choosenNum==3)
            {
                choice=narcissisticNum(number);
            }
            else if (choosenNum==2)
            {
                choice=factorialNum(number);
            }
            else
            {   /* 1,2,3 disinda bir karakter girildiginde hata vermesi icin*/
                /* else kullaniyoruz */
                printf("YOU HAVE ENTERED WRONG CHARACTER !!\n");
                printf("PLEASE ENTER 1(ODD NUMBER) OR 2(FACTORIAL NUMBER");
                printf(" OR 3(NARCISSISTIC NUMBER !!\n");
                choice=verify();/*yanlis girildigi icin devam onayi istiyoruz*/
            }
        }
        else
        {/*Girilen sayi pozitif degilse uyari vererek devam onayi istiyoruz*/
            printf("The entered number is not positive.\n");
            choice=verify();
        }
    }
    return 0;
}

char verify (void)
{   char choice;/*Devam etmek isteyip istenmedigini
                        kontrol eden secim degiskeni */
    printf("Do you want to continue (y/n)? : ");
    scanf(" %c",&choice);
    while (choice!='y' && choice!='n' && choice!='Y' && choice!='N')
                /* y veya n disinda bir karakter */
                /*girildiginde hata vermesi icin yaptigimiz dongu */
        {
            printf("PLEASE ENTER (Y)YES OR (N)NO !!\n");
            scanf(" %c",&choice);
        }
    if (choice=='n' || choice=='N')
    {   /* n karakteri girildiginde programdan cikmadan mesaj biraktiriyoruz*/
        printf("************  Good Bye  ************\n");
    }
    return choice;
}
char oddNum(int number)
{   char choice;
    if (number%2==1)
    {   /* 2 ile bolumunden kalana gore sayinin tek mi cift mi oldugunu */
        /* belirledigimiz fonksiyon .*/
        printf("%d is an odd number !\n",number);
       choice=verify();
    }
    if (number%2==0)
    {
        printf("%d is not an odd number !\n",number);
        choice=verify();
    }
    return choice;
}

char narcissisticNum(int number)
{
    char choice;
    int numOfDigits=0,temp,remainder,temp2,sum=0;
    temp=number;
    if (temp==0)
    {
        numOfDigits=1; /*sadece sayimiz 0 oldugunda farkli sonuc verdigi icin*/
    }               /* 0 a ozel sart koyuyoruz. */
    while (temp!=0)
    {   /* sayiyi her seferinde 10'a bolerek basamak sayisini birer birer */
        /* azaltirken basamak sayisi degiskenimizi de artiriyor ve basamak */
        /* sayisini buluyoruz.Donguyu sayi 0 olmadigi surece yapiyoruz.cunku */
/*sayinin 10a bolumunde cevap 0 geldigi zaman basamak sayisi bulunmus oluyor.*/
        temp/=10;
        numOfDigits++;
    }
    temp2=number;
    while (temp2!=0)
    {/*bu dongude de sayinin son basamagini */
    /* 10a bolumunden kalan olarak buluyoruz ve remainder ussu basamak sayisi*/
    /* formuluyle tek tek basamaklari toplayarak narcissistic olup olmadigini*/
/*kontrol ediyoruz.buldugumuz sum toplami sayiya esitse narcissistic diyoruz.*/
        remainder=temp2%10;
        sum+=pow((double) remainder,(double) numOfDigits);
        temp2/=10;
    }
    if (sum==number)
    {
        printf("%d is a narcissistic number !\n",number);
    }
    else
    {
        printf("%d is not a narcissistic number !\n",number);
    }
    choice=verify();
    return choice;
}
char factorialNum(int number)
{
    char choice;
    int factNum,temp,fact;
    temp=number;
    fact=1;
    if (number>0)
    {/*faktoriyelin carpimlari sirali rakamlar oldugu icin bu rakamlari */
        /* tek tek artacak sekilde factNum degiskenine atadik.ve sayinin */
        /* factNum'a bolumunden kalan 0 oldugu surece factNumu artirarak */
        /* hangi sayinin faktoriyeli oldugunu anliyoruz.*/
        /* bu dongu sonucunda girilen sayi kaca kadar olan sayilarin carpimi */
        /* oldugunu tespit ediyoruz.Dongunun sonunda ornegin 120 girildiginde*/
        /* factNum 6 cikardigi icin her seferinde factNum'u 1 azaltarak dogru*/
        /* sonuca ulasiyoruz. */
    for (factNum=1;temp%factNum==0;factNum++)
    {
        temp/=factNum;
    }
    factNum--;
    while (factNum>1)
    { /* factNumu tespit ettikten sonra birer birer azaltarak 1'den factNum'a*/
        /* kadar olan sayilari carpiyoruz. */
        fact*=factNum*(factNum-1);
        factNum-=2;
    }
    if (fact==number)
    {   /* eger ustteki dongudeki carpimin sonucu girilen sayiya esitse */
        /* o sayi faktoriyel bir sayidir diyerek ciktimizda belirtiyoruz .*/
        printf("%d is a factorial number !\n",number);
        choice=verify();/*ve baska bir islem yapılmak
                        isteniyormu diye test ediyoruz*/
    }
    else
    {   /* fact degiskeni girilen sayiya esit degilse de sayi */
        /* faktoriyel degilidir diye ciktida belirtiyoruz. */
        printf("%d is not a factorial number !\n",number);
        choice=verify();
    }
    }
    else if (number==0)
    {
        printf("0 is a factorial number !\n");
        choice=verify();
    }
    return choice;
}

/*---------------------------------------------------------------------------*/
/*                         End of HW3_141044050.c                            */
/*---------------------------------------------------------------------------*/
