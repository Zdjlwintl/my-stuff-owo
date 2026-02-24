#include <iostream>
using namespace std;

void sort(int *arr, int size) {
	bool swap = false;
	do
	{
		swap = false;
		for (int i = 0; i < size - 1; i++) {
			if (*(arr + i) > *(arr + i + 1)) {
				int temp = *(arr + i);
				*(arr + i) = *(arr + i + 1);
				*(arr + i + 1) = temp;
				swap = true;
			}
		}
	} while (swap == true);
}
int main() {
	int array[] = { 7, 4, 5, 2 };
	int size = 4;
	
	cout << "Unsorted array: [" << flush;
	for (int i = 0; i < size - 1; i++) {
		cout << array[i] << ", " << flush;
	}
	cout << array[size - 1] << "]" << endl;

	sort(array, size);
	
	cout << "Sorted array: [" << flush;
	for (int i = 0; i < size - 1; i++) {
		cout << array[i] << ", " << flush;
	}
	cout << array[size - 1] << "]" << endl;
}
