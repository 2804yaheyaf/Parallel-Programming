#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<omp.h>
#include<time.h>
#define SEED time(NULL)

int main()
{
	srand(SEED);
	int i, n;
	int count=0;
	int square=0;
	double x, y, z, pi;
	
	printf("no. of iterations = ");
	scanf("%d", &n);
	count = 0;
	
	#pragma omp parallel
	{
		#pragma omp critical
		{
			for (i=0; i<(n*n); ++i)
			{
				x = (double)rand() / RAND_MAX;
				y = (double)rand() / RAND_MAX;
				z = (x*x) + (y*y);
				if (z<=1)
				count++;
				square++;
			}
		}
	}
	pi = 4*(double) count / square ;
	printf("Approximate PI = %g\n", pi);

	return(0);
}

