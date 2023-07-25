#include <stdio.h>
#include <math.h>
#include <time.h>
//#include <Windows.h>


int funcComp;
float expectedvalue = -7.0/4.0;
int computationFunc(int i);
float func(float x);// Инициализация метода заданной функции 
float started;
float finished;
float functionAccuracy;
float argumentAccuracy;
float step;
void separation (float start, float step, float finish);
void semidiv (float a, float b, float epsx, float epsy, int n);


int main()
{
  //system("chcp 65001");
  printf("Введите начальную точку интервала:\n " );
  scanf("%f", &started);
  while (started<expectedvalue )
  {
    printf("Введенное значение не входит в область определения, значение должно быть более чем %.f:\n ", expectedvalue  );
    scanf("%f", &started);
  }

  printf("Введите значение конца интервала:\n " );
  scanf("%f", &finished);

  printf("Введите значение шага сетки для отделения корней \nРекомендуемое значение от  %.2f до %.2f: \n", 0.1, 1.0 );
  scanf("%f", &step);
  while (step<=0.1 && step>=1)
  {
    printf("Введенное значение не входит в рекомендуюмую область, значение должно быть в пределах %.2f - %.2f:\n ", 0.1, 1.0 );
    scanf("%f", &step);
  }

  printf("Введите точность решения:\n ");
  scanf("%f", &functionAccuracy);

  printf("Введите точность по аргументу решения:\n " );
  scanf("%f", &argumentAccuracy);


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

float func( float x)//Метод возвращает значение заданной функции, вычисленной от текущего параметра 
{
	return sqrt(4*x+7)-3*cos(x); //Вариант 6
}

void separation (float start, float s, float finish)
{
  int u = 0;
  int i=0;
  float x1 = start;
  float x2;
  float y1;
  float y2;
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

void semidiv (float a, float b, float epsy, float epsx, int n)
{
  float c;
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
