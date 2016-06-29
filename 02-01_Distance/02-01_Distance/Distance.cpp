#include <iostream>
#include <ctime>
using namespace std;

int CountDistance(int *arr, int k);

int main()
{
	int min, max, dist = 0;
	int arr[10]; // определён массив из 10 элементов
	// инициируем рандомизацию чисел
	srand(time(0));

	cin >> min >> max;

	//cout << "RAND_MAX = " << RAND_MAX << "\n"; // значение константы RAND_MAX
	//cout << "Random value " << min + rand() % (max - min + 1) << "\n";

	// заполним массив
	for (int i = 0; i < 10; i++) {
		arr[i] = min + rand() % (max - min + 1); // значение от 0 до 99
		cout << arr[i] << " ";
	}

	dist = CountDistance(arr, 10);
	cout << endl << "dist = " << dist << endl;
	
	system("pause");
	return 0;
}

int CountDistance(int *arr, int k)
{
	int min, max;
	int nmin = 0, nmax = 0;

	max = arr[0];
	min = arr[0];
	for (int i = 1; i < k; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			nmin = i;
		}
		if (arr[i] > max)
		{
			max = arr[i];
			nmax = i;
		}
	}
	cout << endl << "min = " << min << " nmin = " << nmin << endl;
	cout         << "max = " << max << " nmax = " << nmax << endl;

	return (nmax > nmin) ? nmax - nmin - 1 : nmin - nmax - 1;
}
