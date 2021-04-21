#include <stdio.h>
#include <math.h>

#ifndef M_PI
    #define M_PI 3.14159265358979323846 //Определение числа пи, для создания входных значений
#endif

double eps = 0.0001; //определение погрешности вычисления собственной функции синуса

double mySin(double x, double eps);

int check(double input[12], double reference[12], double eps);

double input[] = {0, 0, M_PI/6, M_PI/3, M_PI/2, M_PI, 3*M_PI/2, -M_PI/6, -M_PI/3, -M_PI/2, -M_PI, -3*M_PI/2 }; //инициализация входных значений
double reference[12]; // подготовка массива для эталонных значений

int main(void) {
	printf("Input:		Reference:\n");
	for (int i =1; i<12; i++){
		reference[i]=sin(input[i]); //вычисление эталонных значений используя библиотечную функцию sin()
		printf("%f	%f\n",input[i], reference[i]); // вывод сопоставленных входных и эталонных значений
	}
	int res = check(input, reference, eps); // выполнение тестов разработанной функции и сохранение кода возврата
	if(res == 0) //проверка кода возврата и вывод результатов тестов
	printf("All test are passed!)");
	else
	printf("Incorrect for input №_%d: %f\n", res, input[res]);
	return 0;
}

double mySin(double x, double eps){
	double sum = 0; // значение синуса
	double preSum = x; // следующие слогаемое ряда тейлора
	int i =1;
	while (fabs(preSum)>eps){ //сравнение влияние следующего слогаемого ряда тейлора на конечное значение синуса
		sum += preSum; // добавляем следующие слогаемое к синусу
		preSum *= -x * x / (2 * i * (2 * i + 1)); //вычисляем следующие слагаемое, при вычисление каждого слагаемого на прямую через факториал и при более чем 24-х слогаемых, 25-ое не влезет в  double 
		i++;
	}
	
	return sum;
}

int check(double input[12], double reference[12], double eps){
	for(int i=0; i<12; i++){
		if( fabs( mySin( input[i], eps) - reference[i]) > eps) // сравниваем разницу между получившимся и эталонным значением с требуемой погрешностью,  если разница меньше тест успешен
			return i; // возвращаем код ошибки (номер проваленного теста)
	}
	return 0; // возвращаем код успешного выполнения
}



