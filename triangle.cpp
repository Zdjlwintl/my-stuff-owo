// Begun on 17:50
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	class rightTriangle {
	private:
		const int maxHeight = 25;
		const int maxWidth = 30;
	public:
		int height;
		int width;
		
		int validateHeight() {
			if (height < 1 || height >= maxHeight) {
				cout << "Invalid height (must be 0-25 exclusive)" << endl;
				return 1;
			}
			return 0;
		}

		int validateWidth() {
			if (width < 1 || width >= maxWidth) {
				cout << "Invalid width (must be 0-30 exclusive)" << endl;
				return 1;
			}
			return 0;
		}
		float hypotenuse() {
			return sqrt(height*height + width*width);
		}
		float area() {
			return height * width / 2;
		}
		float perimeter() {
			return height + width + hypotenuse();
		}
	};
	
	rightTriangle Triangle;
	do
	{	
		cout << "Input the height and width of a right-angle triangle. Height must be between 0-25 and width must be 0-30 (exclusive)\nFormat: h w (e.g. 17 13 for height 17 and width 13)" << endl;
		cin >> Triangle.height >> Triangle.width;
		
		if (Triangle.validateHeight() == 1 || Triangle.validateWidth() == 1) {
			cout << "Invalid height or width." << endl;
		}
	} while (Triangle.validateHeight() == 1 && Triangle.validateWidth() == 1);

	int menu;
	do
	{
		cout << "Enter a number to choose which calculation to perform:\n1. Hypotenuse\n2. Area\n3. Perimeter\n" << endl;
		cin >> menu;
		switch (menu) {
			case 1:
				cout << "Hypotenuse: " << Triangle.hypotenuse() << endl;
				return 0;
			case 2:
				cout << "Area: " << Triangle.area() << endl;
				return 0;
			case 3:
				cout << "Perimeter: " << Triangle.perimeter() << endl;
				return 0;
			default:
				cout << "Invalid option." << endl;	
		}
	} while (true);
}
// 18:46
