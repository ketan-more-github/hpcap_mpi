#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<sys/time.h>
#include<omp.h>

#define N 999999999

int main()
{

	int i, j;
	double area, pi;
	double dx, y, x;
	
	
	dx = 1.0/N;
	x = 0.0;
	area = 0.0;

	
    #pragma omp parallel for default(none) reduction(+:area) private(x,y) shared(dx) 
	for(i=0;i<N;i++)
	{
		x = i*dx;
		y = sqrt(1-x*x);
		area += y*dx;
	}
	

	pi = 4.0*area;

	printf("\n Value of pi is = %.16lf\n Execution time is =seconds\n", pi);
	
}

