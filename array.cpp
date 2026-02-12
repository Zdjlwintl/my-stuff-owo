/* I actually uploaded an image of this on a youtube post of mine when I originally finished it xd
basically it was for a short assignment where we had to write code to demonstrate linear search and I decided to use that opportunity to write this:
my first actual program in c++ hehe X3

Finished on: 02/10/26
*/
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
