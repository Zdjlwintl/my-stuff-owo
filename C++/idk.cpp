/* 10:09
sooo little story, last night i was talking with a friend of mine about finals and stuff, and she talked about how
she had to take like python courses for her major (one that isn't related to stem lol) and brought up a particular
question that she struggled the most with, which in essence is to write a function takes in an array and returns
two separate arrays where each element is every other element;
i.e. [1, 2, 3, 4, 5, 6] is split up to [1, 3, 5] and [2, 4, 6]
this was more or less like my very first thought into approaching this, obviously it can be done a lot better,
and yeah this attempt is cheating cuz i didn't actually write a function (not yet at least),
I mean I tried to at first but I think I didn't work out the memory management right
because my function returned a pointer to an array of pointers to the newlist arrays which i didn't actually realise would
all dissipate outside the function LOL (give me a break i first tried this at like 11 in the evening last night lmao)
*/
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
