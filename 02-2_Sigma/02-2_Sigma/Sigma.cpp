/*
ѕо целочисленному массиву A сформировать вещественный
массив B, содержащий абсолютные значени€ отклонений элементов
массива A от среднего значени€ элементов массива
*/
#include <iostream>
#include <ctime>
using namespace std;

void FillSigmaArray(int *arr, double *sig, int k);

int main()
{
	int min = 10, max = 100;
	int arr[10]; // определЄн массив из 10 элементов
	double sig[10] = { 0. };

	// инициируем рандомизацию чисел
	srand(time(0));

	// заполним массив
	cout << "arr: ";
	for (int i = 0; i < 10; i++)
	{
		arr[i] = min + rand() % (max - min + 1); // значение от min до max
		cout << arr[i] << " ";
	}
	cout << endl;

	FillSigmaArray(arr, sig, 10);

	cout << endl << "sig: " ;
	for (int i = 0; i < 10; i++) 
	{
		cout << sig[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}

void FillSigmaArray(int *arr, double *sig, int k)
{
	double av = 0;

	// count average
	for (int i = 0; i < k; i++)
	{
		av += arr[i];
	}
	av /= (double) k;
	cout << "average = " << av << endl;

	// fill array
	for (int i = 0; i < k; i++)
	{
		sig[i] = fabs((double) arr[i] - av);
	}
}
