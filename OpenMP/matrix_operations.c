#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int mat1[3][3] = { {1, -5, 3}, {2, -9, 0}, {-6, 7, 8} };
	int mat2[3][3] = { {5, 8, -9}, {6, 0, -1}, {2, -3, 4} };
	int n=3;
	int i,j;
	int add[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
	int sub[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
	printf("Matrix 1:-\n");
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			printf("%d ", mat1[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	printf("Matrix 2:-\n");
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			printf("%d ", mat2[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	//PARALLEL COMPUTATION
	#pragma omp parallel
	{
		#pragma omp critical
		{
			for (i=0; i<n; i++)
			{
				for (j=0; j<n; j++)
				{
					add[i][j] = mat1[i][j] + mat2[i][j];
					sub[i][j] = mat1[i][j] - mat2[i][j];
				}
			}
		}
	}
	
	printf("Addition Matrix:-\n");
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			printf("%d ", add[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	printf("Subtraction Matrix:-\n");
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			printf("%d ", sub[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}

