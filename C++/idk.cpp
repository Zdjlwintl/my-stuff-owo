// 10:09
#include <cmath>
#include <iostream>
using namespace std;

int main() {	
	int list[] = {1, 2, 3, 4, 5, 6};
	int size = 6;
	int halfsize = size / 2;
	int newSize = (halfsize == float(size) / 2 ? halfsize : halfsize + 1);
	bool isHalf = (halfsize == float(size) / 2 ? true : false);
	int newlist1[newSize];
	int newlist2[halfsize];
	int j = 0;
	int k = 1;
	
	for (int i = 0; i < newSize; i++) {
		newlist1[i] = list[j];
		j += 2;
	}
	for (int i = 0; i < halfsize; i++) {
		newlist2[i] = list[k];
		k += 2;
	}
	if (!isHalf) {
		newlist1[halfsize] = list[size - 1];
	}
	
	cout << "[ " << flush;
	for (int i = 0; i < size - 1; i++) {
		cout << list[i] << ", " << flush;
	}
	cout << list[size - 1] << " ]" << endl;

	cout << "New list 1: [ " << flush;
	for (int i = 0; i < newSize - 1; i++) {
		cout << newlist1[i] << ", " << flush;
	}
	cout << newlist1[newSize - 1] << " ]" << endl;

	cout << "New list 2: [ " << flush;
	for (int i = 0; i < halfsize - 1; i++) {
		cout << newlist2[i] << ", " << flush;
	}
	cout << newlist2[halfsize - 1] << " ]" << endl;
	return 0;
}

// 12:28
// 15:29
