#include<stdlib.h>
#include<stdio.h> 
#include<omp.h>
#include<time.h>
#define cs 10

int main(int argc, char* argv[])
{
// assume 2 random 3x3 square matrices for Matrix Multiplication 
int n = 3;
int a[3][3] = { {1, -5, 3}, {2, -9, 0}, {-6, 7, 8} };
int b[3][3] = { {5, 8, -9}, {6, 0, -1}, {2, -3, 4} };

// Multiplication Matrix initiated to Null/Empty Matrix 
int c[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };

int i, j, k;

printf("Matrix 1:-\n"); 
for(i=0; i<n; i++)
{
for(j=0; j<n; j++)
{
printf("%d\t", a[i][j]);
}
printf("\n");
}
printf("\n");

printf("Matrix 2:-\n"); 
for(i =0; i<n; i++)
{
for(j=0; j<n; j++)
{
printf("%d\t", b[i][j]);
 
}
printf("\n");
}
printf("\n"); j ,k = 0;

clock_t start = clock();
#pragma omp parallel for shared(a, b, c) firstprivate(j, k) schedule(dynamic, cs) 
for(int i=0; i<3; i++)
{
for(j=0; j<3; j++)
{
for(k=0; k<3; k++)
{
c[i][j] = c[i][j] + (a[i][k] * b[k][j]);
}
}
}
clock_t end = clock();

printf("Matrix Multiplication:-\n"); 
for(i=0; i<3; i++)
{
for(j=0; j<3; j++)
{
printf("%d\t", c[i][j]);
}
printf("\n");
}
printf("\n");
double timespent = ((double)(end - start) / CLOCKS_PER_SEC); 
printf("Time:- %f\n", timespent);

return 0;
}

