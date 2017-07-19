#include <stdio.h>

char *reverser(char* str);

int main (void)
{
	char str[80]="lorem ipsum dolor sit amet ";
	
	printf("%s",reverser(str));
	
	return 0;
}

char *reverser(char* str)
{
	char temp[50];
	int i=0,j,k=0;
	while (str[i]=='\0')
		i++;
	for (j=0;str[j]!=' ';j++)
	{}
	while (j>=0)
	{
		temp[k++]=str[j];
		str[j]=str[i];
		str[i+1]=temp[k-1];
		j--;
		i--;
	}
	j=0;
	return str;
}
