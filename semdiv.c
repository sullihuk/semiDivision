#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
//#include <Windows.h>


int funcComp;
double expectedvalue = -7.0/4.0;
int computationFunc(int i);
double func(double x);// Инициализация метода заданной функции 
double started = 0;
double finished = 0;
double functionAccuracy = 0;
double argumentAccuracy = 0;
double step = 0;
void separation (double start, double step, double finish);
void semidiv (double a, double b, double epsx, double epsy, int n);
double stepMin = 0.1;
double stepMax = 1.0;


int main()
{
  //system("chcp 65001");
  printf("Введите начальную точку интервала:\n " );
  scanf("%lf", &started);
  while (started<expectedvalue )
  {
    printf("Введенное значение не входит в область определения, значение должно быть более чем %.f:\n ", expectedvalue  );
    scanf("%lf", &started);
  }

  printf("Введите значение конца интервала:\n " );
  scanf("%lf", &finished);

  printf("Введите значение шага сетки для отделения корней \nРекомендуемое значение от  %.2f до %.2f: \n",stepMin, stepMax );
  scanf("%lf", &step);
  while (step<=stepMin && step>=stepMax)
  {
    printf("Введенное значение не входит в рекомендуюмую область, значение должно быть в пределах %.2f - %.2f:\n ", stepMin, stepMax );
    scanf("%lf", &step);
  }

  printf("Введите точность решения:\n ");
  scanf("%lf", &functionAccuracy);

  printf("Введите точность по аргументу решения:\n " );
  scanf("%lf", &argumentAccuracy);


  clock_t start, end;
  start = clock();
  separation(started, step, finished);
  printf("Количество вычислений функции f(x): %d\n",funcComp+1);
  end = clock();
  double time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
  //printf("Количество итераций равно: %d\n", n);
  printf("Времени затрачено: %f секунд\n",time_taken);
}

int computationFunc(int i)
{
  funcComp +=i;
  return funcComp;
}

double func( double x)//Метод возвращает значение заданной функции, вычисленной от текущего параметра 
{
	return sqrt(4*x+7)-3*cos(x); //Вариант 6
}

void separation (double start, double s, double finish)
{
  int u = 0;
  int i=0;
  double x1 = start;
  double x2;
  double y1;
  double y2;
  x2 = x1 + s;
  y1 = func(x1);

  while (x2<finish)
  {
    y2 = func(x2);
    i++;
    if (y1*y2<=0){
      
      u++;
      printf("x1: %f,\tx2: %f\ny1: %f\ty2: %f\n", x1, x2, y1, y2);
      semidiv(x1, x2, functionAccuracy, argumentAccuracy, u);
    }
    x1 = x2;
    x2 = x1+s;
    y1 = y2;
  }
    computationFunc(i);
    printf("Количество итераций отделения корней: %d: \n", i );
}

void semidiv (double a, double b, double epsy, double epsx, int n)
{
  double c;
  int t;

  while(fabs(b-a) > epsx && fabs(func(a)) > epsy)
  {
    t++;
    c = (a+b)/2;
    if (func(a)*func(c) < 0)
    {
      b = c;
    }
    else {
      a = c;
    }
  }
  c = (a+b)/2;

  printf("Значение функции при найденном решении: %.10f\n", func(c));
  printf("Количество итераций уточнения корня: %d\n", t);
  printf("Корень x_%d: %.10f\n", n, c); 
  computationFunc(t);
  puts("==============================================");
}
