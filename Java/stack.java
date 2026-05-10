import java.util.Scanner;

public class stack {
	public static class Stack {
		int stack[] = {27, 34, 82, 79, 0, 0, 0, 0, 0, 0}; 
		int topPointer = 3;
		int basePointer = 0;
		int stackful = 9;
		
		void push(int item) {
			if (topPointer < stackful) {
				topPointer++;
				stack[topPointer] = item;
			} else {
				System.out.println("Stack is full, cannot push.");
			}
		}
		int pop() {
			if (topPointer == basePointer - 1) {
				System.out.println("Stack is empty, cannot pop.");
				return 0;
			} else {
				int item = stack[topPointer];
				stack[topPointer] = 0;
				topPointer--;
				return item;
			}
		}
	}
	public static void main(String[] args) {
		Stack myStack = new Stack();
		Scanner inp = new Scanner(System.in);
		System.out.print("Enter 1 to push an item or 2 to pop: ");
		int option = inp.nextInt();
		
		if (option == 1) {
			System.out.print("Enter item to push: ");
			int item = inp.nextInt();
			myStack.push(item);
		} else if (option == 2) {
			int item = myStack.pop();
			if (item != 0) {
				System.out.println("Popped " + item);
			}
		}

		System.out.print("{");
		for (int i = 0; i < 9; i++) {
			System.out.print(myStack.stack[i] + ", ");
		}
		System.out.println(myStack.stack[9] + "}");

	}
}

// 16:58
