#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	printf("Work Sharing Construct: SECTIONS (with nowait and reduction clause)\n");
	int n = 9;
	int a[9] = { -74, 22, 61, 33, -15, 49, -80, 93, 58 };
	int i;
	int sa=0;
	printf("Array:-\n");
	for (i=0; i<n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	#pragma omp parallel shared(a, n, sa) private(i)
	{
		#pragma omp sections nowait reduction(+:sa)
		{
			#pragma omp section
			{
				for (i=0; i<n; i++)
					sa = sa + (a[i]);
			}
		
			#pragma omp section
			{
				printf("Sum of array:- %d", sa);
				printf("\n");
			}
		}
	}
	
	return 0;
}

