#include <stdio.h>



double num1,num2;
char operation;

double calculator(double num1,double num2,char operation);

int main (void)
{

printf("result : %f",calculator(6.0,3.0,'*'));



return 0;

}

double calculator(double num1,double num2,char operation)
{
	double result;

	switch(operation)
	{
	case '+':
		result=num1+num2;
		break;
	case '-':
		result=num1-num2;
		break;
	case '*':
		result=num1*num2;
		break;
	case '/':
		result=num1/num2;
		break;


	}

	return result;
}





