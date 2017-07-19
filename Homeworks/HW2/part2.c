

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
/*  For the second part of the homework II, which are used for Calculating  */
/*  Area and Perimeter of certain geometric shapes..                        */
/*                                                                          */
/*------------------------------------------------------------------------  */



#include <stdio.h>
#define PI 3.14

/* Kullanacağımız fonksiyonlarımızın prototiplerini tanıtıyoruz. */
int areaOfRectangle(int width, int height);
int perimeterOfRectangle(int width, int height);

int areaOfSquare(int width);
int perimeterOfSquare(int width);

double areaOfCircle(int radius);
double perimeterOfCircle(int radius);



int main()
{
    int recWidth;
    int recHeight;
    int squareWidth;
    int radius;

    printf("Please enter the width of the rectangle:");
    scanf("%d",&recWidth);

    printf("Please enter the height of the rectangle:");
    scanf("%d",&recHeight);

    printf("The area of the rectangle is: "
            "%d\n",areaOfRectangle(recWidth,recHeight));
    printf("The perimeter of the rectangle is: "
            "%d\n",perimeterOfRectangle(recWidth,recHeight));

    printf("Please enter the width of the square:");
    scanf("%d",&squareWidth);
    printf("The area of the square is: %d\n",areaOfSquare(squareWidth));
    printf("The perimeter of the rectangle is: "
           "%d\n",perimeterOfSquare(squareWidth));


    printf("Please enter the radius of the circle:");
    scanf("%d",&radius);
    printf("The area of the circle is: %d\n",areaOfCircle(radius));
    printf("The perimeter of the circle is: %d\n",perimeterOfCircle(radius));

    return 0;
}

/* Fonksiyonlarımızı teker teker tanımlıyoruz. */
int areaOfRectangle(int width, int height)
{
    int areaofRec;
    areaofRec = width*height;

    return areaofRec;
}

int perimeterOfRectangle(int width, int height)
{
    int perimRec;
    perimRec=width*2+height*2;

    return perimRec;

}

int areaOfSquare(int width)
{
    int areaSquare;
    areaSquare=width*width;

    return areaSquare;


}

int perimeterOfSquare(int width)
{
    int perimSquare;
    perimSquare=4*width;

    return perimSquare;

}

double areaOfCircle(int radius)
{
    double areaCircle;
    areaCircle=PI*radius*radius;

    return areaCircle;

}
double perimeterOfCircle(int radius)
{
    double perimCircle;
    perimCircle=2*PI*radius;

	return perimCircle;
}
