#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<math.h>


int main()

{
int a,b,c,x,y,z;
float m,n;
	
#pragma omp parallel default(none) shared (a,b,c,x,y,z,m,n)

{
    printf("Enter i,j,k coefficients for the first vector\n");
    scanf("%d %d %d",&a,&b,&c);
    printf("Enter i,j,k coefficients for the second vector\n");
    scanf("%d %d %d",&x,&y,&z);
    printf("The sum is %d i + %d j + %d k\n",a+x,b+y,c+z);
    printf("The difference is %d i + %d j + %d k\n",a-x,b-y,c-z);
    m=(a*a+b*b+c*c);
    n=(x*x+y*y+z*z);
    printf("The magnitude of first vector is %lf ",sqrt(m));
printf("\n");
    printf("The magnitude of second vector is %lf ",sqrt(n));
printf("\n");
}

return 0;

}

