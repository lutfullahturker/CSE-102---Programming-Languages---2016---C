#include <stdio.h>
#include <math.h>


int Poly;
int a;
int b;
int c;
double root1;
double root2;


int main(void)
{
	printf("a        : ");
	scanf("%d",&a);
	printf("b        : ");
	scanf("%d",&b);
	printf("c        : ");
	scanf("%d",&c);
	
	root1= (-b+ sqrt(b*b-4*a*c))/(2*a);
	root2= (-b- sqrt(b*b-4*a*c))/(2*a);

	printf("Roots are: %.2f %.2f\n",root1,root2);







return 0;
}
