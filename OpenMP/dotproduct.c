#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<math.h>


int main()

{
int a,b,c,x,y,z;
float m,n;
	
#pragma omp parallel default(none) shared (a,b,c,x,y,z)

{

    printf("Enter i,j,k coefficients for the first vector\n");
    printf("\n");
    scanf("%d %d %d",&a,&b,&c);
    printf("Enter i,j,k coefficients for the second vector\n");
    scanf("%d %d %d",&x,&y,&z);
 
    printf("The dot product of the two vectors is %d\n",(a*x+b*y+c*z));
    
printf("\n");

}

return 0;
}
