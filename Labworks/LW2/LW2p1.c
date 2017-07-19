#include <stdio.h>

int x;
int sec;
int first;
int third;
int y;
int main(void)
{
	printf("Please enter a 3-digit number: ");
	scanf("%d",&x);
	first= x%10;
	y= x%100;
	sec = y/10;
	third= x/100;
	printf("Reverse of the number: %d%d%d",first,sec,third);


return 0;

}
