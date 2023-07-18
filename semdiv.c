#include <stdio.h>
#include <math.h>
#include <time.h>


float dihot(float a, float b, float s, float e, float e1);//Инициализация метода дихотомии
float func(float x);// Инициализация метода заданной функции 
int n = 0;
float started;
float finished;
float functionAccuracy;
float argumentAccuracy;
float step;
void separation (float start, float step, float finish);
float semidiv (float a, float b, float eps);


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

  printf("Введите значение шага сетки для отделения корней: \nРекомендуемое значение от 0.1 до 1: \n" );
  scanf("%f", &step);
  while (step<=0.1 && step>=1)
  {
    printf("Введенное значение не входит в рекомендуюмую область, значение должно быть в пределах %.f - %.f:\n ", 0.1, 1 );
    scanf("%f", &step);
  }

  printf("Введите точность решения:\n ");
  scanf("%f", &functionAccuracy);
  //printf("Введите точность по аргументу решения :\n " );
  //scanf("%f", &argumentAccuracy);
  //separation(started, step, finished);
  printf("x = %f",semidiv(started, finished, 0.0000001));
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
      printf("x1: %f,\tx2: %f\n y1: %f\ty2: %f\n", x1, x2, y1, y2);
      printf("Корень x_%d: %f\n", i, semidiv(x1, x2, functionAccuracy));
    }
    x1 = x2;
    x2 = x1+s;
    y1 = y2;
  }
}

float semidiv (float a, float b, float eps)
{
  float c;
  do {
  c=(b-a)/2;  
  if (func(a)*func(b)>0)
    a=c;
    else
    b=c;
  } while(b-a<eps);
  c=(a+b)/2;
  return c;
  }


/*int sign(float x)//Метод возвращает 1 либо -1 в зависимости от поступившего параметра. Параметром является текущее вычисленное х.
{
	int res;
	res=0;
	if (x<0) res=-1;
	if (x>0) res= 1;
	return res;
}*/

/*float dihot(float a, float b, float e )//Метод посредством цикла while делит заданный отрезок пополам до тех пор пока разница между концами отрезка не будет меньше или равна параметру е, либо абсолютное значение функции в текущей точке приблизится к нулю менее чем параметр е1
{
	float x;
  float c;
	while (b-a>e)
	{
    n++;
    x=(a+b)/2;// Вычисление значения искомой переменной, собственно, половинное деление/метод дихотомии
    printf("Проход %d середина отрезка есть: %f \n", n, x);
    if (fabs(func(x))<(a+b)/2) 
      break; // Если асолютное значение функции в соответсвующей точке приближается к нулю с заданной точностью, цикл прекращается, и метод возвращает текущее значение х, которое и является решением уравнения с заданной точностью
    if (func(x)<0) {
      a=x; // Значению начальной точки присваивается значение текущей искомой переменной, если значение функции в начально точке равно значению функции в точке х
    }else 
      b=x; // Если предыдущее условие не выполнено значение переменной х присваивается концу заданного отрезка, на котором ищется решение
    
	}
	return x; //Метод возвращает значение переменной удовлетворяющее первому условию в цикле выше
}*/
