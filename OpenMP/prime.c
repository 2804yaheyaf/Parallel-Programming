#include<omp.h>
#include<stdio.h>

int main(int argc, char ** argv)
{
	int l, u, i, j;
	printf("Lower limit of interval:- ");
	scanf("%d", &l);
	
	printf("Upper limit of interval:- ");
	scanf("%d", &u);
	
	printf("Prime Numbers between %d and %d:-\n", l, u);
	int flag;
	omp_set_num_threads(4);
	
	#pragma omp parallel for schedule(static)
	for (i=l; i<=u; i++)
	{
		if (i==1 || i==0)
		continue;
		else
		{
			flag=0;
			for (j=2; j<=i/2; j++)
			{
				if (i%j==0)
				{
					flag=1;
					break;
				}
			}
			if (flag==0)
			printf("%d\n",i);
		}
	}
	
	return 0;
}



