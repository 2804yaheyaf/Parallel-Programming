#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	printf("Work Sharing Construct: FOR (with nowait and reduction clause)\n");
	int n = 9;
	int a[9] = { 47, 26, -13, 71, 55, -98, 30, -62, 80 };
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
		#pragma omp for nowait reduction(+:sa)
		for (i=0; i<n; i++)
		{
			sa = sa + (a[i]);
		}
		printf("Sum of array:- %d", sa);
		printf("\n");
	}
	
	return 0;
}


