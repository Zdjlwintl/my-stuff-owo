import java.util.Scanner;
// 08:48
public class spheres {
	public static double radius;
	public static void inputRadius() {
		System.out.print("Input radius of sphere (enter 0 to exit) ");
		Scanner inp = new Scanner(System.in);
		radius = inp.nextDouble();
		while (radius < 0) {
			System.out.print("Please enter a positive number. ");
			radius = inp.nextDouble();
		}
	}
	public static class Sphere {
		public static final double pi = 3.142;
		double radius;
		Sphere(double r) {
			this.radius = r;
		}

		double calculateVolume() {
			return 4 / 3 * pi * radius * radius * radius;
		}
		
		double calculateSurfaceArea() {
			return 4 * pi * radius * radius;
		}
	}
	public static void main(String[] args) {
		inputRadius();
		while (radius != 0) {
			Sphere mySphere = new Sphere(radius);
			Scanner inp = new Scanner(System.in);
			int option;
			do {
				System.out.println("Enter number to choose an option:\n1. Calculate surface area\n2. Calculate volume");
				option = inp.nextInt();
				switch (option) {
					case 1:
						System.out.println("Surface area: " + mySphere.calculateSurfaceArea());
						break;
					case 2:
						System.out.println("Volume: " + mySphere.calculateVolume());
						break;
					default:
						System.out.println("Invalid option.");
				}
			} while (option != 1 && option !=2);
			inputRadius();
		}
	}
}
