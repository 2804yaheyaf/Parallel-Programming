#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	printf("Work Sharing Construct: SINGLE\n");
	int n = 9;
	int a[9] = { -95, 34, 50, 14, 86, 73, 60, -22, 49 };
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
		#pragma omp single nowait
		for (i=0; i<n; i++)
		{
			sa = sa + (a[i]);
		}
		printf("Sum of array:- %d", sa);
		printf("\n");
	}
	
	return 0;
}

