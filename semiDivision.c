#include <stdio.h>
#include <math.h>

float bisec(float a, float b, float e, float e1);
float func( float x);
int sign(float x);

int main()
{
	printf("x = %f",bisec(1.5, 3, 0.0001, 0.0001));
}

float func( float x)
{
	return x*cos(3*sqrt(x));
}

int sign(float x)
{
	int res;
	res=0;
	if (x<0) res=-1;
	if (x>0) res= 1;
	return res;
}

float bisec(float a, float b, float e, float e1)
{
	float x;
	while (b-a>e)
	{
	x=(a+b)/2;
	if (fabs(func(x))<e1) break;
	if (sign(func(a))==sign(func(x))) a=x;
	else b=x;
	}
	return x;
}
