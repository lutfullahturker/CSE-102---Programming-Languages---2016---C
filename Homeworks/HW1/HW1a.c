


/* -----------------------------------------------------------------------  */ 
/*                                                                          */ 
/*                   HW01_141044050_Lütfullah_Türker                        */ 
/*                                                                          */ 
/*                                                                          */ 
/* -----------------------------------------------------------------------  */ 
/*                Created on 20/02/2016 by Lütfullah_Türker                 */ 
/*                                                                          */ 
/* Description                                                              */ 
/* -----------------------------------------------------------------------  */
/*    For the first part of the homework I, which are used for Calculating  */ 
/*    Overall Grade Of  The Students..                                      */ 
/*                                                                          */ 
/*------------------------------------------------------------------------  */ 




#include <stdio.h>


int main(void)
{        /* Not Agirliklarini Tanimliyoruz. */
	double midtWeight1;      /*Vize Not Agirliklari */
	double midtWeight2;
	double midtWeight3;
	double hwWeight1;       /* Homework Not Agirliklari */
	double hwWeight2;
	double finalExamWeight;   /* Final Not  Agirligi */

           /* Ders Notlari */
	double midtGrade1;
	double midtGrade2;
	double midtGrade3;
	double hwGrade1;
	double hwGrade2;
	double finalExamGrade;

	double finalGrade;   /* Sene Sonu  Ortalama Notu */

	printf("Please enter the 1. midterm weight:");
	scanf("%lf",&midtWeight1);
	printf("Please enter the 2. midterm weight:");
	scanf("%lf",&midtWeight2);
	printf("Please enter the 3. midterm weight:");
	scanf("%lf",&midtWeight3);
	printf("Please enter the 1. homework weight:");
	scanf("%lf",&hwWeight1);
	printf("Please enter the 2. homework weight:");
	scanf("%lf",&hwWeight2);
	printf("Please enter the final exam weight:");
	scanf("%lf",&finalExamWeight);
	
	printf("Please enter the 1. midterm grade:"); 
	scanf("%lf",&midtGrade1);
	printf("Please enter the 2. midterm grade:");
	scanf("%lf",&midtGrade2);
	printf("Please enter the 3. midterm grade:");
	scanf("%lf",&midtGrade3);
	printf("Please enter the 1. homework grade:");
	scanf("%lf",&hwGrade1);
	printf("Please enter the 2. homework grade:");
	scanf("%lf",&hwGrade2);
	printf("Please enter the final exam grade:");
	scanf("%lf",&finalExamGrade);

	
	finalGrade=((midtWeight1/100)*midtGrade1)+((midtWeight2/100)*midtGrade2)
	+((midtWeight3/100)*midtGrade3)+((hwWeight1/100)*hwGrade1)
	+((hwWeight2/100)*hwGrade2)+((finalExamWeight/100)*finalExamGrade);
	
	printf("Your final grade is: %f\n",finalGrade);
	
	return 0;
}
