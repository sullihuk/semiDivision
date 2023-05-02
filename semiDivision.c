#include <stdio.h>
#include <math.h>


float bisec(float a, float b, float e, float e1);//Инициализация метода бисекции(половинного деления)
float func( float x);// Инициализация метода заданной функции 
int sign(float x);// Инициализация метода определяющего знак 

int main()
{
	printf("x = %f",bisec(1.5, 3, 0.0001, 0.0001));// Вывод на экран решения уравнения. Параметром вывода является результат метода реализующего, собственно, метод дихотомии. В свою очередь, параметрами функции являются начало и конец отрезка, на котором находится решение(Вариант 9), точность с которой будет решаться уравнение, значение, с которым будет сравниваться значение заданной функции на предмет приближения к нулю (по известной теореме, это и будет решением уравнения) соответственно.
}

float func( float x)//Метод возвращает значение заданной функции, вычисленной от текущего параметра 
{
	return sqrt(4x+7)-3*cos(x); //Вариант 6
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
	x=(a+b)/2;// Вычисление значения искомой переменной, собственно, половинное деление
	if (fabs(func(x))<e1) break; // Если асолютное значение функции в соответсвующей точке приближается к нулю с заданной точностью, цикл прекращается, и метод возвращает текущее значение х, которое и является решением уравнения с заданной точностью
	if (sign(func(a))==sign(func(x))) a=x; // Значению начальной точки присваивается значение текущей искомой переменной, если значение функции в начально точке равно значению функции в точке х
	else b=x; // Если предыдущее условие не выполнено значение переменной х присваивается концу заданного отрезка, на котором ищется решение
	}
	return x; //Метод возвращает значение переменной удовлетворяющее первому условию в цикле выше
}
