import java.util.Scanner;
public class triangle {
	public static class Triangle {
		double height;
		double width;
		
		Triangle(double h, double w) {
			this.height = h;
			this.width = w;
		}

		double area() {
			return height * width / 2;
		} 
	}
		
	public static void main(String[] args) {
		Scanner inp = new Scanner(System.in);
		System.out.print("Height: ");
		double h = inp.nextDouble();
		System.out.print("Width: ");
		double w = inp.nextDouble();
		
		Triangle t = new Triangle(h, w);

		System.out.println("Area = " + t.area());
		System.out.print("Input height: ");
	}
}
