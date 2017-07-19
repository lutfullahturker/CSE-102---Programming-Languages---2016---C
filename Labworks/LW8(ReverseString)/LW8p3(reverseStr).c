#include <stdio.h>
#include <string.h>

char *reverser(char* str);

int main(void)
{
	char str[80]="lorem ipsum dolor sit amet";
	
	reverser(str);


	return 0;
}

char *reverser(char* str)
{
	char temp[255];
	int i,j=0,k,l,m=0,f=0,lengh;
	lengh=strlen(str);
	i=lengh-1;
	k=i;
	while (j<lengh/2)
	{
	f=j;
	while (j<lengh && str[j]!=' ' && str[j]!='\t' && str[j]!='\n'){j++;}
	while (k<lengh && str[k]!=' ' && str[k]!='\t' && str[k]!='\n'){k--;}
	strncpy(&temp[i-(j-f)+1],&str[f],j-f);
	strncpy(&temp[m],&str[k],i-k+1);
	m=m+i-k;
	
	
	
	for(l=0;l<lengh;l++)
		str[l]=temp[j];
	str[l+1]='\0';
	}
	temp[j+1]='\0';
	for(l=0;l<lengh;l++)
		printf("%c",temp[l]);
	return str;
}
