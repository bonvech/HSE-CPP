#include <iostream>
using namespace std;

int main()
{
	for (int i = 1; i < n; i++) {
		// Левее i-ого элемента массив отсортирован
		int k = a[i]; // Запоминаем, потому что затрем сдвигом
		int j = i - 1;
		while (j >= 0 && a[j] > k) {
			// Двигаем все элементы, больше k
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = k; // Ставим k на место
	}
}
