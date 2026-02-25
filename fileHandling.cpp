#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
	string textLn;
	string myFile = "myText.txt";
	fstream file(myFile, ios::out);
	do
	{
		cout << "Enter a line of text: " << flush;
		getline(cin, textLn);
		if (textLn != "") {
			file << textLn << endl;
		} else {
			file.close();
		}
	} while (textLn != "");
	
	cout << "The file contains these lines of text:" << endl;
	file.open(myFile, ios::in);
	while (getline(file, textLn)) {
		cout << textLn << endl;
		if (file.eof()) {
			break;
		}
	}
	return 0;
}
