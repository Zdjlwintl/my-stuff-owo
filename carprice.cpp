// 22:08
#include <iostream>

using namespace std;

int main() {
	class Car {
	private:
		const float FirstYearReduction = 0.4;
		const float NextYearReduction = 0.2;
		int YearCount = 1;
	public:
		float Price;

		void NewPrice(){
			do
			{
				if (YearCount == 1) {
					Price *= (1 - FirstYearReduction); 		
				}
				else {
					Price *= (1 - NextYearReduction);
				}	
				cout << "Age: " << YearCount << " years, Price: $" << Price << endl;
				YearCount++;
			}
			while (YearCount <= 9 && Price > 1000);
		}
	};
	Car NewCar;
	cout << "Enter purchase price. (nearest $)" << endl;
	cin >> NewCar.Price;
	NewCar.NewPrice();
	return 0;
}
// 22:22
