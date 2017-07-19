#include <stdio.h>
#include <math.h>

int lwRevInt(int input);

int main(void)
{
	printf("ans =>> %d \n",lwRevInt(123456789));


	return 0;
}

int lwRevInt(int input)
{
	int i,ans;
	i=log10(input);
	if (i>=0)
		ans =input%10*pow(10,i)+lwRevInt(input/10);
	return ans;
}
