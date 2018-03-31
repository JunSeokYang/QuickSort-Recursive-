#include <iostream>
#include <stdlib.h>
#include <time.h>

#define SZ 30

using namespace std;

void QuickSort(int *a, int l, int r) {
	int buf, left = l + 1, right = r;
	if (l == r)
		return;
	if (left != right) {
		while (left < right) {
			while (a[l] >= a[left] && left + 1 != right)
				left++;
			while (a[l] < a[right] && left != right)
				right--;
			if (left < right) {
				buf = a[left];
				a[left] = a[right];
				a[right] = buf;
				left++;
			}
			if (left == right) {
				if (a[l] < a[left])
					left--;
				break;
			}
		}
	}

	if (a[l] > a[left]) {
		buf = a[left];
		a[left] = a[l];
		a[l] = buf;
	}

	if (left - l>1)
		QuickSort(a, l, left - 1);
	if (r - left>1)
		QuickSort(a, left + 1, r);
	return;
}

int main() {
	int a[SZ];
	srand(time(NULL));
	for (int i = 0; i < SZ; i++)
		cout << (a[i] = rand() % 10) << ' ';
	cout << endl;


	QuickSort(a, 0, SZ - 1);
	
	
	for (int i = 0; i < SZ; i++)
		cout << a[i] << ' ';
	cout << endl;


}