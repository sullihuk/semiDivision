#include <stdio.h>
#include <math.h>
#include <time.h>


float func(float x);// Инициализация метода заданной функции 
float started;
float finished;
float functionAccuracy;
float argumentAccuracy;
float step;
void separation (float start, float step, float finish);
float semidiv (float a, float b, float epsx, float epsy);


int main()
{
  printf("Введите начальную точку интервала:\n " );
  scanf("%f", &started);
  while (started<-7/4)
  {
    printf("Введенное значение не входит в область определения, значение должно быть более чем %.f:\n ", -7/4 );
    scanf("%f", &started);
  }

  printf("Введите значение конца интервала:\n " );
  scanf("%f", &finished);

  printf("Введите значение шага сетки для отделения корней \nРекомендуемое значение от  %.2f до %.2f: \n", 0.1, 1 );
  scanf("%f", &step);
  while (step<=0.1 && step>=1)
  {
    printf("Введенное значение не входит в рекомендуюмую область, значение должно быть в пределах %.2f - %.2f:\n ", 0.1, 1 );
    scanf("%f", &step);
  }

  printf("Введите точность решения:\n ");
  scanf("%f", &functionAccuracy);

  printf("Введите точность по аргументу решения :\n " );
  scanf("%f", &argumentAccuracy);

  separation(started, step, finished);
  //printf("x = %f\n",semidiv(started, finished, functionAccuracy));
  clock_t start, end;
  start = clock();

	//printf("x = %f\n", dihot(started, finished,step,functionAccuracy));// Вывод на экран решения уравнения. Параметром вывода является результат метода реализующего, собственно, метод дихотомии. В свою очередь, параметрами функции являются начало и конец отрезка, на котором находится решение, эти цифры можно менять; точность с которой будет решаться уравнение, значение, с которым будет сравниваться значение заданной функции на предмет приближения к нулю (по известной теореме, это и будет решением уравнения) соответственно.
  end = clock();
  double time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
  //printf("Количество итераций равно: %d\n", n);
  printf("Времени затрачено: %f секунд\n",time_taken);
}

float func( float x)//Метод возвращает значение заданной функции, вычисленной от текущего параметра 
{
	return sqrt(4*x+7)-3*cos(x); //Вариант 6
}

void separation (float start, float s, float finish)
{
    float x1 = start;
    float x2;
    float y1;
    float y2;
    x2 = x1 + s;
    y1 = func(x1);
  while (x2<finish)
  {
    y2 = func(x2);
    int i;
    i++;
    if (y1*y2<=0){
      printf("x1: %f,\tx2: %f\ny1: %f\ty2: %f\n", x1, x2, y1, y2);
      printf("Корень x_%d: %f\n", i, semidiv(x1, x2, functionAccuracy,argumentAccuracy));
    }
    x1 = x2;
    x2 = x1+s;
    y1 = y2;
  }
}

float semidiv (float a, float b, float epsx, float epsy)
{
  float c = (a+b)/2;

  while(fabs(b-a) > epsx && fabs(func(a) > epsy))
  {
    if (func(a)*func(c) < 0)
    {
      b = c;
      printf("lalala\n");
    }
    else{
      a = c;
      printf("hahahah\n");
  }
    c = (a+b)/2;
  }

  return c;
  }
