import java.io.PrintWriter;
import java.io.FileNotFoundException;
import java.io.File;
import java.util.Scanner;
import java.lang.Math;

public class FileNumber3 {
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
    double datAvg = printMinMaxAvg("input.dat");

    System.out.println("The result of test file:");
    double txtAvg = printMinMaxAvg("input.txt");

    int datRounded = (int) Math.round(datAvg);
    int txtRounded = (int) Math.round(txtAvg);
    int lcm = getLcm(datRounded, txtRounded);
    int gcd = getGcd(datRounded, txtRounded);

    fileName = "result.txt";
    try {
      outputStream = new PrintWriter(fileName);
    } catch (FileNotFoundException e) {
      System.out.println("Error opening the file " + fileName);
    }

    outputStream.printf("GCD: %d\n", gcd);
    outputStream.printf("LCM: %d\n", lcm);
    outputStream.close();
  }

  private static int getGcd(int a, int b) {
    if (a % b == 0) {
      return b;
    }
    return getGcd(b, a % b);
  }

  private static int getLcm(int a, int b) {
    return (a * b) / getGcd(a, b);
  }

  static double printMinMaxAvg(String fileName) {
    Scanner inputStream = null;
    try {
      inputStream = new Scanner(new File(fileName));
    } catch (Exception e) {
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
    double avg = sum / total;

    System.out.printf("Largest = %.1f\n", max);
    System.out.printf("Smallest = %.1f\n", min);
    System.out.printf("Average = %.1f\n", avg);
    System.out.println();

    inputStream.close();
    return avg;
  }
}
