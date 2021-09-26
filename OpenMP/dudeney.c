#include<stdio.h>
#include <mpi.h>

// Dudeney Series 

int main(int argc,char *argv[])
{
    int rank,size,cubeRt;
    int c=0;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    //printf("Rank= %d\n",rank);
    long int sum=0,dig=0,ans,num;
int rem;
    int n; // Input number
int m; // Copy of input number n
int i; // Index variable to extract digits
int s = 0; // Variable to accumulate the sum of digits of n
int d;
int number;    
  if(rank==0)
   { 

	printf("rank= %d", rank);
    printf("\nEnter number to check");
    scanf("%d", &n); // Read n
	m = n; // Copy n to m
	// Extract and accumulate sum of digits
	for (i = 0; m ; ++i)
	{

	d = m % 10; // Find the next digit in m
// from right to left scan
	s = s + d; // Accumulate the sum of digits in s

	m = m / 10; // New m after removing
 // the right-most digit d
	}
// Check for Dudeney number condition and print
if (s*s*s == n )
printf("%d is a Dudeney number\n", n);
else
printf("%d is not a Dudeney number\n", n);

}

if (rank!=0)
{

printf("\nAll Dudeney Values:\n");    
    for(i=1;i<100;i++)
    {
	    
	    num=i*i*i;
	    ans=num;
	    while(num>0)
	    {
		rem=num%10;
		num=num/10;
		sum=sum+rem;
	    }
	    if(i==sum)
	    {
		printf("Rank= %d\n",rank);
		printf("%ld\n",ans);
	    }
	    sum=0;
	    dig=0;
            
    }
}   
//else if(rank==1)
//{
	
    
//}
    
    MPI_Finalize();
    return 0;
}
