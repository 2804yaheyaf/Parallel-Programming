#include<omp.h>
#include<stdio.h>

int main(int argc, char ** argv)
{
	int n, i, next;
	int t1=0;
	int t2=1;
	
	printf("give no. of terms:- ");
	scanf("%d", &n);
	printf("\nFibonacci Series:-\n");
	omp_set_num_threads(1);
	
	#pragma omp parallel
	{
		#pragma omp critical
		for (i = 1; i <= n; ++i)
		{
			printf("%d, ", t1);
			next = t1 + t2;
			t1 = t2;
			t2 = next;
		}
		printf("\n");
	}
	
	return 0;
}




