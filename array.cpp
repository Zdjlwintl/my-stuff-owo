#include <iostream>
using namespace std;

int main() {
    int myList[8] = { 4, 7, 11, -5, 8, 3, 1, -8 };
    int upperBound = 8;
    int lowerBound = 0;
    bool Found = 0;
    int item;

    cout << "Input a number to be found: " << flush;
    cin >> item;

    int index = lowerBound;
    do {
        if (myList[index] == item) {
            Found = 1;
        }
        index++;
    }
    while (!Found && index <= upperBound);

    if (Found) {
        cout << "Item found." << endl;
    }
    else {
        cout << "Item not found." << endl;
    }
    return 0;
}
