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
