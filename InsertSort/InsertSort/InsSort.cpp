#include <iostream>
using namespace std;

int main()
{
	for (int i = 1; i < n; i++) {
		// ����� i-��� �������� ������ ������������
		int k = a[i]; // ����������, ������ ��� ������ �������
		int j = i - 1;
		while (j >= 0 && a[j] > k) {
			// ������� ��� ��������, ������ k
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = k; // ������ k �� �����
	}
}
