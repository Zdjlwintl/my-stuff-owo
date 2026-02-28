import java.util.Scanner;

public class search {
	public static void main(String[] args) {
		int array[] = { 56, 39, 77, 19, 25, 33, 44 };
		int size = 7;
		Scanner in = new Scanner(System.in);
		System.out.print("Enter a number to search for: ");
		int item = in.nextInt();
		boolean found = false;

		for (int i = 0; i < size; i++) {
			if (array[i] == item) {
				found = true;
				break;
			}
		}

		if (found == true) {
			System.out.println("Item " + item + " found.");
		} else {
			System.out.println("Item " + item + " not found.");
		}
	}
}
// 17:49
