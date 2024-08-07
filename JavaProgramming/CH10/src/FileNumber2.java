import java.io.PrintWriter;
import java.io.FileNotFoundException;
import java.io.File;
import java.util.Scanner;
import java.lang.Math;

public class FileNumber2 {
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

    System.out.println("The result of binary file:");
    printMinMaxAvg("input.dat");

    System.out.println("The result of test file:");
    printMinMaxAvg("input.txt");
  }

  static void printMinMaxAvg(String fileName) {
    Scanner inputStream = null;
    try {
      inputStream = new Scanner(new File(fileName));
    } catch (FileNotFoundException e) {
      System.out.println("Error opening the file " + fileName);
    }

    double tmp = inputStream.nextDouble();
    double min = tmp, max = tmp, sum = tmp;
    int total = 1;

    while (inputStream.hasNextDouble()) {
      tmp = inputStream.nextDouble();
      if (min > tmp) {
        min = tmp;
      }
      if (max < tmp) {
        max = tmp;
      }
      sum += tmp;
      total++;
    }
    System.out.printf("Largest = %.1f\n", max);
    System.out.printf("Smallest = %.1f\n", min);
    System.out.printf("Average = %.1f\n", sum / total);
    System.out.println();

    inputStream.close();
  }

}
