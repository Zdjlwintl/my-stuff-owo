/* Finished on 22:31, today is 03/01/26
learning basic file handling in java, this is basically identical to fileHandling.cpp xd
i am learning a lot :3
*/

import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class files {
	public static void main(String[] args) throws Exception {
		String myFile = "MyText.txt";
		Scanner inp = new Scanner(System.in);
		String Ln;	
		FileWriter fileW = new FileWriter(myFile);
		do
		{
			System.out.print("Enter a line of text: ");
			Ln = inp.nextLine();
			if (Ln != "") {
				fileW.write(Ln + "\n");
			} else {
				fileW.close();	
			}
		} while (Ln != "");

		Scanner fileR = new Scanner(new File(myFile));
		while (fileR.hasNextLine()) {
			System.out.println(fileR.nextLine());
		}
	}
}
