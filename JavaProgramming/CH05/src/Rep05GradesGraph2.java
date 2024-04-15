import java.util.Scanner;

public class Rep05GradesGraph2 {
  static char indexGrade[] = { 'A', 'B', 'C', 'D', 'F' };
  int gradeNumArr[] = new int[5];

  public static void main(String[] args) {
    System.out.println();
    System.out.println("Test case 1: readInput() and writeOutput()");
    Rep05GradesGraph2 grades = new Rep05GradesGraph2();
    grades.readInput();
    System.out.println();
    System.out.println("Verify results with writeOutput():");
    grades.writeOutput();
    System.out.println("===============================");

    System.out.println();
    System.out.println("Test case 2:");
    grades.set(1, 2, 3, 4, 5);
    System.out.println("write (display) counts individually:");
    System.out.println();
    System.out.println("Use the method to change the grade value and verify that each grade value has changed.");
    System.out.println();
    grades.writeAcount();
    grades.writeBcount();
    grades.writeCcount();
    grades.writeDcount();
    grades.writeFcount();
    System.out.println("===============================");

    System.out.println();
    System.out.println("Test case 3:");
    grades.set(10, 4, 6, 2, 8);
    System.out.println("return counts individually:");
    System.out.println();
    System.out.println("Use the method to change the grade value and verify that each grade value has changed.");
    System.out.println();
    System.out.println("A count = " + grades.getAcount());
    System.out.println("B count = " + grades.getBcount());
    System.out.println("C count = " + grades.getCcount());
    System.out.println("D count = " + grades.getDcount());
    System.out.println("F count = " + grades.getFcount());
    System.out.println();
    System.out.println("===============================");
  }

  void readInput() {
    Scanner s = new Scanner(System.in);

    for (int i = 0; i < Rep05GradesGraph1.indexGrade.length; i++) {

      System.out.printf("How many %c's?\n", Rep05GradesGraph1.indexGrade[i]);
      this.gradeNumArr[i] = s.nextInt();

      while (0 > this.gradeNumArr[i]) {
        System.out.println("Number of grade cannot be negative.");
        System.out.printf("Reenter number of %c's:\n", Rep05GradesGraph1.indexGrade[i]);
        this.gradeNumArr[i] = s.nextInt();
      }
    }

    s.close();
  }

  void writeOutput() {
    for (int i = 0; i < Rep05GradesGraph1.indexGrade.length; i++) {
      System.out.printf("Number of %c's = %d\n", Rep05GradesGraph1.indexGrade[i], this.gradeNumArr[i]);
    }
  }

  void set(int... numbers) {
    for (int i = 0; i < numbers.length; i++) {
      this.gradeNumArr[i] = numbers[i];
    }
  }

  void printSum(int sum) {
    System.out.printf("Total number of grade = %d", sum);
  }

  void writeAcount() {
    System.out.printf("Number of A's = %d\n", this.gradeNumArr[0]);
  }

  void writeBcount() {
    System.out.printf("Number of A's = %d\n", this.gradeNumArr[1]);
  }

  void writeCcount() {
    System.out.printf("Number of A's = %d\n", this.gradeNumArr[2]);
  }

  void writeDcount() {
    System.out.printf("Number of A's = %d\n", this.gradeNumArr[3]);
  }

  void writeFcount() {
    System.out.printf("Number of A's = %d\n", this.gradeNumArr[4]);
  }

  int getAcount() {
    return this.gradeNumArr[0];
  }

  int getBcount() {
    return this.gradeNumArr[1];
  }

  int getCcount() {
    return this.gradeNumArr[2];
  }

  int getDcount() {
    return this.gradeNumArr[3];
  }

  int getFcount() {
    return this.gradeNumArr[4];
  }
}
