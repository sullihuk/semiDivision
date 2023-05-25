#include <stdio.h>
#include <math.h>
#include <time.h>


float dihot(float a, float b, float e, float e1);//Инициализация метода дихотомии
float func( float x);// Инициализация метода заданной функции 
int sign(float x);// Инициализация метода определяющего знак 
int n = 0;


int main()
{
  clock_t start, end;
  start = clock();

	printf("x = %f\n", dihot(0, 2, 0.0001, 0.0001));// Вывод на экран решения уравнения. Параметром вывода является результат метода реализующего, собственно, метод дихотомии. В свою очередь, параметрами функции являются начало и конец отрезка, на котором находится решение, эти цифры можно менять; точность с которой будет решаться уравнение, значение, с которым будет сравниваться значение заданной функции на предмет приближения к нулю (по известной теореме, это и будет решением уравнения) соответственно.
  end = clock();
  double time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
  printf("Количество итераций равно: %d\n", n);
  printf("Времени затрачено: %f секунд\n",time_taken);
}

float func( float x)//Метод возвращает значение заданной функции, вычисленной от текущего параметра 
{
	return sqrt(4*x+7)-3*cos(x); //Вариант 6
}

int sign(float x)//Метод возвращает 1 либо -1 в зависимости от поступившего параметра. Параметром является текущее вычисленное х.
{
	int res;
	res=0;
	if (x<0) res=-1;
	if (x>0) res= 1;
	return res;
}

float dihot(float a, float b, float e, float e1)//Метод посредством цикла while делит заданный отрезок пополам до тех пор пока разница между концами отрезка не будет меньше или равна параметру е, либо абсолютное значение функции в текущей точке приблизится к нулю менее чем параметр е1
{
	float x;
	while (b-a>e)
	{
    n++;
    x=(a+b)/2;// Вычисление значения искомой переменной, собственно, половинное деление/метод дихотомии
    printf("Проход %d середина отрезка есть: %f \n", n, x);
    if (fabs(func(x))<e1) 
      break; // Если асолютное значение функции в соответсвующей точке приближается к нулю с заданной точностью, цикл прекращается, и метод возвращает текущее значение х, которое и является решением уравнения с заданной точностью
    if (sign(func(a))==sign(func(x))) {
      a=x; // Значению начальной точки присваивается значение текущей искомой переменной, если значение функции в начально точке равно значению функции в точке х
    }else 
      b=x; // Если предыдущее условие не выполнено значение переменной х присваивается концу заданного отрезка, на котором ищется решение
    
	}
	return x; //Метод возвращает значение переменной удовлетворяющее первому условию в цикле выше
}
