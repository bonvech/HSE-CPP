/*
��������� ����������� ����� ���� ��������� ������� �� K �������
������.
*/
#include <iostream>
#include <ctime>
using namespace std;

void ShiftArray(int *arr, int N, int k);

int main()
{
	int min = 10, max = 100;
	int shift = 6;
	const int N = 15;
	int arr[N]; // �������� ������ �� 10 ���������

	// ���������� ������������ �����
	srand(time(0));

	// �������� ������
	cout << "array: ";
	for (int i = 0; i < N; i++)
	{
		arr[i] = min + rand() % (max - min + 1); // �������� �� min �� max
		cout << arr[i] << " ";
	}
	cout << endl;

	ShiftArray(arr, N, shift);

	cout << endl << "after: ";
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}

void ShiftArray(int *arr, int N, int k)
{
	for (int i = N - 1; i >= 0; i--)
	{
		if(i >= k) arr[i] = arr[i-k];
		else      arr[i] = 0;
	}

}