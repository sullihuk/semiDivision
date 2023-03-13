#include <stdio.h>
#include <math.h>

float bisec(float a, float b, float e, float e1);//Инициализация метода бисекции(половинного деления)
float func( float x);// Инициализация метода заданной функции 
int sign(float x);// Инициализация метода определяющего знак 

int main()
{
	printf("x = %f",bisec(1.5, 3, 0.0001, 0.0001));// Вывод на экран решения уравнения 
}

float func( float x)//Метод возвращает значение заданной функции, вычисленной от текущего параметра 
{
	return x*cos(3*sqrt(x)); //Вариант 9
}

int sign(float x)//Метод возвращает 1 либо -1 в зависимости от поступившего параметра
{
	int res;
	res=0;
	if (x<0) res=-1;
	if (x>0) res= 1;
	return res;
}

float bisec(float a, float b, float e, float e1)//Метод посредством цикла while делит заданный отрезок пополам до тех пор пока разница между концами отрезка не будет меньше или равна параметру е, либо абсолютное значение функции в текущей точке приблизится к нулю менее чем параметр е1
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
