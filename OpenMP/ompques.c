#include<stdio.h>
  #include <omp.h> 
   int main () 
       {
        int a[10],sq[10],cu[10],total_sum=0;
	   int n;
int sqaure_sum=0;
int cube_sum=0;
printf("Yaheya Farooqui \n");
printf("Enter size of array \n");
scanf("%d",&n);
printf("Enter the odd numbers \n");
for(int j=0;j<n;j++)
{
scanf("%d",&a[j]);
}
	    #pragma omp parallel for
		for (int i=0; i < n; i++) 
		{
		sq[i] = a[i]*a[i];
		sqaure_sum+=sq[i];
		cu[i] = a[i]*a[i]*a[i]; 
		cube_sum+=cu[i];		
		}
		
		#pragma omp parallel for reduction(+: total_sum)	
		for (int k=0;k<n;k++)
		{
			total_sum+=sq[k]+cu[k];
			//total_sum+=total_sum;
		}
		printf("Sum of squares = %d \n",sqaure_sum);
		printf("Sum of cubes = %d \n", cube_sum);
		printf("Total sum of cubes and squares %d \n", total_sum);

}
