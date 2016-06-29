/*
�� �������������� ������� A ������������ ������������
������ B, ���������� ���������� �������� ���������� ���������
������� A �� �������� �������� ��������� �������
*/
#include <iostream>
#include <ctime>
using namespace std;

void FillSigmaArray(int *arr, double *sig, int k);

int main()
{
	int min = 10, max = 100;
	int arr[10]; // �������� ������ �� 10 ���������
	double sig[10] = { 0. };

	// ���������� ������������ �����
	srand(time(0));

	// �������� ������
	cout << "arr: ";
	for (int i = 0; i < 10; i++)
	{
		arr[i] = min + rand() % (max - min + 1); // �������� �� min �� max
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
