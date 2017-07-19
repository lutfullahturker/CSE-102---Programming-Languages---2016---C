#include <stdio.h>

int num1,num2,num3,num4;
int sum(int num1,int num2,int num3,int num4);

int main (void)
{
	printf("%d\n",sum(10,200,5,6));



return 0;

}

int sum(int num1,int num2,int num3,int num4)
{
	int maxnum,minnum,kalantoplam;
	if (num1>=num2 && num1>=num3 && num1>=num4)
{		maxnum=num1;
}
	if (num2>=num1 && num2>=num3 && num2>=num4)
{		maxnum=num2;
}
	if (num3>=num1 && num3>=num2 && num3>=num4)
{		maxnum=num3;
}
	if (num4>=num1 && num4>=num2 && num4>=num3)
{		maxnum=num4;
}
	if (num1<=num2 && num1<=num3 && num1<=num4)
{		minnum=num1;
}
	if (num2<=num3 && num2<=num4 && num2<=num1)
{		minnum=num2;
}
	if (num3<=num1 && num3<=num2 && num3<=num4)
{		minnum=num3;
}
	if (num4<=num1 && num4<=num2 && num4<=num3)
{		minnum=num4;
}
	kalantoplam=(num1+num2+num3+num4)-(maxnum+minnum);
	return kalantoplam;
}
