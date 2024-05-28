import java.io.PrintWriter;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.lang.Math;

public class FileNumber1 {
  public static void main(String[] args) {
    String fileName = "input.dat";
    PrintWriter outputStream = null;

    try {
      outputStream = new PrintWriter(fileName);
    } catch (FileNotFoundException e) {
      System.out.println("Error opening the file " + fileName);
    }

    for (int i = 2; i <= 22; i += 2) {
      double input = (double) i;
      outputStream.println(input);
    }
    outputStream.close();

    fileName = "input.txt";
    try {
      outputStream = new PrintWriter(fileName);
    } catch (FileNotFoundException e) {
      System.out.println("Error opening the file " + fileName);
    }

    for (int i = 0; i < 100; i++) {
      outputStream.println((int) (Math.random() * 1000 + 1));
    }
    outputStream.close();
  }
}
