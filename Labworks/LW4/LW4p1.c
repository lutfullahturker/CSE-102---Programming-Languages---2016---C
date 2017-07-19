#include <stdio.h>


double avg( int sentinel);
int main(void)
{	int sentinel;
	printf("sayi girin :");
	scanf("%d",&sentinel);
	printf("%f",avg(sentinel));
	return 0;
}

double avg( int sentinel)
{	int i,k=0;
	double ort;
	i=1;
	while (sentinel!=-1)
	{
		printf("sayi girin :");
		scanf("%d",&sentinel);
		while (sentinel!=-1)
		{
		ort=(sentinel+k)/i;
		k=sentinel;
		i++;
		}
	}
	return ort;
}
