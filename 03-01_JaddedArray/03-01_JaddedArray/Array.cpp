/*
*/
#include <iostream>
#include <iostream>
using namespace std;

int main()
{
	int N, size = 0, X=0;
	int i, j, last = 0, num = 0;

	cin >> N;

	// count array size
	while (size*(size+1)/2 < N)
		size++;
	last = N - ( size* (size - 1) / 2) ;
	cout << "size =" << size <<  endl;
	cout << "last =" << last << endl;

	// create jad Array
	int **ptrGen = new int *[size];
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

	system("pause");
}