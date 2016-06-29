/*
*/
#include <iostream>
using namespace std;

int ** structure_create( int N );

int main()
{
	int N;
	int ** X;

	cin >> N;

	X = structure_create(N);

	// print Array
	int size = 0;
	int num = 0;
	// count array size
	while (size*(size + 1) / 2 < N)
		size++;
	int last = N - (size* (size - 1) / 2);
	cout << endl << "Array:" << endl;
	for (int i = 0; i < size; i++)
	{
		if (i != (size - 1))
			num = i + 1;
		else
			num = last;
		for (int j = 0; j < num; j++)
		{
			cout << *(*(X + i) + j) << " ";
		}
		cout << endl;
	}


	system("pause");
	return 0;
}


int ** structure_create(int N)
{
	int size = 0, X = 0;
	int i, j, last = 0, num = 0;

	// count array size
	while (size*(size+1)/2 < N)
		size++;
	last = N - ( size* (size - 1) / 2) ;
	cout << "size =" << size <<  endl;
	cout << "last =" << last << endl;

	// create jad Array
    int ** ptrGen = new int *[size];
	for (i = 0; i < size; i++)
	{
		if (i != (size - 1))
			num = i + 1;
		else
			num = last;
		ptrGen[i] = new int[num];
		for (j = 0; j < num; j++)
		{
			*(*(ptrGen + i) + j) = X++;
			//cout << *(*(ptrGen + i) + j) << " ";
		}
		//cout << endl;
	}

	// print Array
	cout << endl << "Array:" << endl; 
	for (i = 0; i < size; i++)
	{
		if (i != (size - 1))
			num = i + 1;
		else
			num = last;
		for (j = 0; j < num; j++)
		{
			cout << *(*(ptrGen + i) + j) << " ";
		}
		cout << endl;
	}

	return ptrGen;
}