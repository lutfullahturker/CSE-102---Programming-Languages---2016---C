


/* -----------------------------------------------------------------------  */ 
/*                                                                          */ 
/*                   HW01_141044050_Lütfullah_Türker                        */ 
/*                                                                          */ 
/*                                                                          */ 
/* -----------------------------------------------------------------------  */ 
/*                Created on 20/02/2016 by Lütfullah_Türker                 */ 
/*                                                                          */ 
/*                          Description                                     */ 
/* -----------------------------------------------------------------------  */
/*    For the second part of the homework I, which are used for Calculating */ 
/*    Lived Time in Different Planets..                                     */ 
/*                                                                          */ 
/*------------------------------------------------------------------------  */ 




#include <stdio.h>

int main(void)
{     /* Mevcut  Zaman Bilgileri */
	int curYear;
	int curMonth;
	int curDay;
	  /* Doğum Bilgileri */
	int birthYear;
	int birthMonth;
	int birthDay;

	int livedDay;   /* Dünyada Yaşanılan Gün Sayısı */

	int hours; /* Gezegendeki Bir Günde Kaç Saat Olduğu */
	int days; /* Gezegendeki Bir Ayda Kaç Gün Olduğu */
	int months; /* Gezegendeki Bir Yılda Kaç Ay Olduğu */

	  /* Gezegende Olsaydı Yaşanmış Olacak  Zaman*/
	int nYear;  
	int planetDay;

	  /* Gezegendeki Bilgiler */

	int nDay;
	int nMonth;

	printf("Please enter the current date.\nYear:");
	scanf("%d",&curYear);
	printf("Month:");  scanf("%d",&curMonth);
	printf("Day:");    scanf("%d",&curDay);

	printf("Please enter your birthday.\nYear:");
	scanf("%d",&birthYear);
	printf("Month:");   scanf("%d",&birthMonth);
	printf("Day:");     scanf("%d",&birthDay);

	livedDay = ( curYear - birthYear -1)*365+(12- birthMonth)*30+ 
	(30- birthDay)+(curMonth-1)*30+ curDay+5;
	/* Aylar 30 gün olduğundan ve bir yılı 365 gün aldığımızdan dolayı 
	* son senemizin sonunda 5 günlük bir kayıp oluyor.Bu yüzden sona +5 
	* ekledik */


	printf("You have lived %d days.\nPlease enter about the time"
	" of another planet\nHow many hours is a day?",livedDay);
	scanf("%d",&hours);
	printf("How many days is a month?");  scanf("%d",&days);
	printf("How many months is a year?"); scanf("%d",&months);

	planetDay= (livedDay*24)/ hours; /*Gezegendeki Toplam Yaşadığımız Gün*/
	nYear= planetDay/(months*days);  /*Gezegendeki Toplam Yaşadığımız Yıl*/

	nMonth= (planetDay-(nYear*months*days))/days;
	nDay= (planetDay-(nYear*months*days))%days;
	printf("If you lived in a planet where a day is %d hours, a"
	" month is %d ",hours,days);
	printf("days and a year is %d months: you were %d years",months,nYear);
	printf(", %d months and %d days old\n",nMonth,nDay);

	
	
	
	return 0;



}
