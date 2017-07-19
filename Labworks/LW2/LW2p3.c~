#include <stdio.h>
#include <math.h>

double Ax;
double Ay;
double Bx;
double By;
double Velo;
double Uzaklik;
double Time;
double Coordx;
double Coordy;

int main (void)
{
	printf("Coordinates of the A: ");
	scanf("%lf %lf",&Ax,&Ay);

	printf("Coordinates of the B: ");
	scanf("%lf %lf",&Bx,&By);
	printf("Average velocity of the vehicle: ");
	scanf("%lf",&Velo);

	Uzaklik= sqrt((Bx-Ax)*(Bx-Ax)+(By-Ay)*(By-Ay)); /* x=v*t */ 
	Time= Uzaklik/Velo;
	
	printf("Arrival time: %.2f hour(s)\n",Time);
	
	Coordx= Ax+((Bx-Ax)/Time);
	Coordy= Ay+((By-Ay)/Time);
	
	printf("Coordinates of the vehicle after 1 hour: %.2f %.2f\n",Coordx,Coordy);

return 0;
}
