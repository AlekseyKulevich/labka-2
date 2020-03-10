#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double input(void)
{
	char str[1000];
	int indexPoint;
	double number = 0;
	do
	{
		indexPoint = -1;
		int badInput = 0;
		gets_s(str, 1000);
		// проверка на различные неразрешённые символы в строке
		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] == '.' && indexPoint == -1) indexPoint = i;
			else if (str[i] == '.')	badInput = 1;
			if (str[i] == '-' && i != 0) badInput = 1;
			if ((str[i] < '0' || str[i] >'9') && str[i] != '.' && str[i] != '-') badInput = 1;
			if (badInput) break;
		}
		//проверка на ведущие нули
		int counter = 0;
		if (str[0] == '-') counter = 1;
		if (strlen(str) == 0) badInput = 1;
		if (str[counter] == '0' && str[counter + 1] != '.' && str[counter + 1] != '\0') badInput = 1;
		// если что-то найдено, то новая итерация цикла , следовательно, и новый ввод
		if (badInput)
		{
			printf("\nError. Invalid input. Try again\n");
			continue;
		}
		// перевод числа в double
		if (indexPoint == -1) indexPoint = strlen(str);
		for (; counter < indexPoint; counter++)
			number = 10 * number + str[counter] - '0';
		for (counter = indexPoint + 1; counter < strlen(str); counter++)
			number += (str[counter] - '0') * pow(10.0, indexPoint - counter);
		if (str[0] == '-') number *= -1;
		// выходим из цикла, если ввод корректный
		if (badInput == 0) break;
	} while (1);
	return number;
}

int factorialCalculationUsingRecursion(int number)
{
	if (number < 0) return -1;
	else if (number == 0) return 1;
	else return number * factorialCalculationUsingRecursion(number - 1);
}



double sumCalculatingWithRecursionFactorial(double number, double accuracy)
{
	double sum = 0;
	int amountOfNumbers = 1;
	//увеличивая количество членов ряда, вычисляем сумму до тех пор, пока не достигнется заданная точность
	do
	{
		sum = sum + pow(-1, amountOfNumbers - 1) * pow(number, 2 * amountOfNumbers - 1) / factorialCalculationUsingRecursion(2 * amountOfNumbers - 1);
		amountOfNumbers++;
	} while (fabs(sum - sin(number)) >= accuracy);
	printf("(rec)For a given n, the expression differs from sin(x) and decomposition less than a given error: ");
	printf("%d\n", amountOfNumbers);
	return sum;
}


void main(void)
{
	double number = 0, sumOfTheSeriesRec, sumOfTheSeriesIter, answerSin, accuracy = 0;
	do
	{
		printf("Enter the number for which the values will be calculated: ");
		//выполняем ввод числа, учитывая ограничения
		do
		{
			number = input();
			if (number <= 0 || number > 1) printf("\nError. Invalid input. Try again\n");
			else break;
		} while (1);
		printf("Enter the accuracy: ");
		//выполняем ввод погрешности, учитывая ограничения
		do
		{
			accuracy = input();
			if (accuracy <= 0 || accuracy > 1) printf("\nError. Invalid input. Try again\n");
			else break;
		} while (1);
		//вычисляем значение синуса и сумму двумя способами
		sumOfTheSeriesRec = sumCalculatingWithRecursionFactorial(number, accuracy);
		answerSin = sin(number);
		printf("%20s| %20s| %20s\n", "x", "sin(x)", "decomposition(rec)");
		printf("%20lf| %20lf| %20lf\n", number, answerSin, sumOfTheSeriesRec);
		printf("\nIf you would like to continue - press 'y'\n\n");
	} while (_getch() == 'y');
}