


/* -----------------------------------------------------------------------  */
/*                                                                          */
/*                   HW02_141044050_Lütfullah_Türker                        */
/*                                                                          */
/*                                                                          */
/* -----------------------------------------------------------------------  */
/*                Created on 26/02/2016 by Lütfullah_Türker                 */
/*                                                                          */
/* Description                                                              */
/* -----------------------------------------------------------------------  */
/*    For the first part of the homework II, which are used for Calculating  */
/*    Overall Grade Of  The 3 Students..                                    */
/*                                                                          */
/*------------------------------------------------------------------------  */



#include <stdio.h>

    void calculateLastGrade(); /* Fonksiyonumuzun prototipini tanýmlýyoruz */

int main()
{
    calculateLastGrade();       /* Her öðrenci için ayrý ayrý 3 kere */
    calculateLastGrade();       /* fonksiyonumuzu çaðýrýyoruz.       */
    calculateLastGrade();


    return 0;
}

void calculateLastGrade()
{
        /* Not Agirliklarini Tanimliyoruz. */
	double midtWeight1;      /*Vize Not Agirliklari */
    double hwWeight1;       /* Homework Not Agirliklari */
    double finalExamWeight;   /* Final Not  Agirligi */

    /* Ders Notlari */
	double midtGrade1;
	double hwGrade1;
    double finalExamGrade;

    double finalGrade;   /* Sene Sonu  Ortalama Notu */

    printf("Please enter the 1. midterm weight:");
	scanf("%lf",&midtWeight1);

	printf("Please enter the 1. homework weight:");
	scanf("%lf",&hwWeight1);

	printf("Please enter the final exam weight:");
	scanf("%lf",&finalExamWeight);

	printf("Please enter the 1. midterm grade:");
	scanf("%lf",&midtGrade1);

	printf("Please enter the 1. homework grade:");
	scanf("%lf",&hwGrade1);

	printf("Please enter the final exam grade:");
	scanf("%lf",&finalExamGrade);

    finalGrade=((midtWeight1/100)*midtGrade1)+((hwWeight1/100)*hwGrade1)
	+((finalExamWeight/100)*finalExamGrade);

	printf("Your final grade is: %f\n",finalGrade);

}
