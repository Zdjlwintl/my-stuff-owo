/* Begun on 22:08
Today is 02/19/26

So this is part of the same homework where I wrote triangle.cpp, except this time we weren't actually asked to write it in
a programming language in the first place at all LOL.
But y'know I'll take any excuse to practice C++ hehe :3 though I won't worry about input validation much,,
for now at the very least..
Also for anyone interested, I'll put the pseudocode from the original question on the bottom :p
*/
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
/* 22:22

Pseudocode from the original question:

OUTPUT “Enter purchase price”
INPUT PurchasePrice
CurrentValue ← PurchasePrice
YearCount ← 1
WHILE YearCount <= 9 AND CurrentValue > 1000
	IF YearCount == 1 THEN
		CurrentValue ← CurrentValue * (1 - 40 / 100)
	ELSE
		CurrentValue ← CurrentValue * (1 - 20 / 100)
	ENDIF
		OUTPUT YearCount, CurrentValue
		YearCount ← YearCount + 1
	ENDWHILE
*/
