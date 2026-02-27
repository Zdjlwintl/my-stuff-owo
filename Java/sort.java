/* Finished at 21:00; today is 02/27/26

Welcome to my first actual java program!! :3
this is basically just sort.cpp, just with a different array and different Language.

at some point or another i need to myself into using java,
because i'm not actually allowed to use C++ during like actual exams (idk blame the syllabus x_x)
if i wanted to i could've just as easily switched back to python but,,
by this point i'm so disjointed from it i might as well learn the closest thing to C/C++ that i'm allowed to use :p
*/

public class sort { 
	public static void main(String[] args) {
		int arr[] = {38, 25, 33, 51, 87, 19};
		int size = 6;
		boolean swap;
		
		System.out.print("Unsorted array: [");
		for (int i = 0; i < size - 1; i++) {
			System.out.print(arr[i] + ", ");
		}
		System.out.println(arr[size - 1] + "]");

		do
		{
			swap = false;
			for (int i = 0; i < size - 1; i++) {
				if (arr[i] > arr[i + 1]) {
					int temp = arr[i + 1];
					arr[i + 1] = arr[i];
					arr[i] = temp;
					swap = true;
				}
			}
		} while (swap == true);

		System.out.print("Sorted array: [");
		for (int i = 0; i < size - 1; i++) {
			System.out.print(arr[i] + ", ");
		}
		System.out.println(arr[size - 1] + "]");
	}
}
