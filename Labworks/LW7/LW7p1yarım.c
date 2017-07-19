#include <stdio.h>

char * concat(char *destination,char *source);
int * compare(char *str1,char *str2);
char * copystr(char *destination,char *source);
char * rpos(char *str,char ch);


int main (void)
{
	char str1[50]="deneme123";
	char str2[50]="helloworld";
	printf("%s",concat(str1,str2));
	
	return 0;
}

char * concat(char *destination,char *source)
{
	int i,j;
	for (i=0;destination[i]!='\0';i++)
	{
		if (destination[i+1]=='\0')
		{
			for (j=0;source[j]!='\0';j++)
			{
				destination[i+1+j]=source[j];
			}
			return destination;
		}
	}
	return 0;
}
int * compare(char *str1,char *str2)
{
return 0;
}
char * copystr(char *destination,char *source)
{
	int i;
	for (i=0;source[i]!='\0';i++)
	{
		destination[i]=source[i];
	}
	destination[i+1]='\0';
	return destination;
}
char * rpos(char *str,char ch)
{
	int i=0,j,k,temp;
	while (str[i]!='\0')
		i++;
	j=i;
	while (str[j]!=ch)
	{
		j--;
	}
	temp=j;
	for(k=0;str[temp]!='\0';k++,temp++)
	{
		str[k]=str[temp];
	}
	str[k]='\0';
	return str;
	
	


}
