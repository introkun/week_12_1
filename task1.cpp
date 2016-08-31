#include <iostream>
#include <ctime>
#include <locale.h>

using namespace std;

int arring(int arr[10][10], int const);
void arring(int arr[10][10]);
void arring(int arr[10][10], int, int);
int arring(int arr[10][10], int);
int arring(int arr[10][10], const int* size);

int main()
{
	setlocale(LC_ALL, "rus");
	int min = INT_MAX;
	int max = INT_MIN;
	int const size = 10;
	int arr[size][size];
	srand(time(NULL));
	int ex;
	arring(arr, size);		//Инициализация квадратной матрицы
	do
	{
		cout << "выберете действие:\n1 - Инициализация квадратной матрицы\n"
			"2 - Вывод матрицы на экран\n3 - Определение максимального и минимального элемента на главной диагонали матрицы\n"
			"4 - Сортировка элементов по возрастанию отдельно для каждой строки матрицы\n0 - выход\n";
		cin >> ex;
		if (ex == 1)
		{
			arring(arr, size);		//Инициализация квадратной матрицы
		}
		else if (ex == 2)
		{
			arring(arr);	//Вывод матрицы на экран
		}
		else if (ex == 3)
		{
			arring(arr, min, max);	//Определение максимального и минимального элемента на главной диагонали матрицы
		}
		else if (ex == 4)
		{
			arring(arr, &size);	//Сортировка элементов по возрастанию отдельно для каждой строки матрицы
		}
	} while (ex != 0);
}

int arring(int arr[10][10], int const size)		//Инициализация квадратной матрицы
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = rand() % 199 - 99;
		}
	}
	return arr[size][size];
}

int arring(int arr[10][10], const int * size)	//Сортировка элементов по возрастанию отдельно для каждой строки матрицы
{
	for (int l = 0; l < *size; l++)
	{
		for (int i = 0; i < *size; i++)
		{
			for (int j = 0; j < *size - 1 - l; j++)
			{
				if (arr[i][j] > arr[i][j + 1])
				{
					int t = arr[i][j];
					arr[i][j] = arr[i][j + 1];
					arr[i][j + 1] = t;
				}
				
			}
		}
	}
	return arr[*size][*size];
}

void arring(int arr[10][10])	//Вывод матрицы на экран
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (arr[i][j] >= 10 ||
				arr[i][j] > -10 &
				arr[i][j] < 0)
			{
				cout << " ";
			}
			else if (arr[i][j] >= 0)
			{
				cout << "  ";
			}
			cout << arr[i][j];
			if (j == 9)
			{
				cout << endl;
			}
		}
	}
}

void arring(int arr[10][10], int min, int max)		//Определение максимального и минимального элемента на главной диагонали матрицы
{
	for (int i = 0; i < 10; i++)
	{
		if (arr[i][i] > max)
		{
			max = arr[i][i];
		}
		if (arr[i][i] < min)
		{
			min = arr[i][i];
		}
	}
	cout << "min = " << min << endl << "max = " << max << endl;
}