import java.util.Scanner;
/* 08:48
Today is 05/21/26 but I actually started this for part of a thing i wanted to do in the middle of class,
i'm pretty sure it was the morning of 04/08/26 when i actually began this xd
today i like randomly discovered this file in my home folder and decided to just finish it :p
(done 21:44)
*/
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
