import java.util.Scanner;

public class Rep05GradesGraph2 {
  static char indexGrade[] = { 'A', 'B', 'C', 'D', 'F' };
  int gradeNumArr[] = new int[5];
  int total;

  public static void main(String[] args) {
    System.out.println();
    System.out.println("Test case 1: readInput() and writeOutput()");
    Rep05GradesGraph2 grades = new Rep05GradesGraph2();
    grades.readInput();
    System.out.println();
    System.out.println("Verify results with writeOutput():");
    grades.writeOutput();
    System.out.println();
    System.out.println("return total number of grades");
    System.out.println();
    System.out.println("Total number of grades = "
        + grades.getTotalNumberOfGrades());
    System.out.println();
    System.out.println("===============================");

    System.out.println();
    System.out.println("Test case 2:");
    System.out.println("set counts as a group: A=1, B=2, C=3, D=4, F=5 etc.");
    grades.set(1, 2, 3, 4, 5);
    System.out.println();
    System.out.println("Verify results with writeOutput():");
    grades.writeOutput();
    System.out.println();
    System.out.println("return total number of grades");
    System.out.println();
    System.out.println("Total number of grades = "
        + grades.getTotalNumberOfGrades());
    System.out.println();
    System.out.println("===============================");

    System.out.println();
    System.out.println("Test case 3:");
    System.out.println("set counts individually");
    System.out.println("A=10, B=9, etc.");
    grades.setAcount(10);
    grades.setBcount(9);
    grades.setCcount(8);
    grades.setDcount(7);
    grades.setFcount(6);
    System.out.println();
    System.out.println("Verify results with writeOutput():");
    grades.writeOutput();
    System.out.println();
    System.out.println("return total number of grades");
    System.out.println();
    System.out.println("Total number of grades = "
        + grades.getTotalNumberOfGrades());
    System.out.println();
    System.out.println("===============================");

    System.out.println();
    System.out.println("Test case 4:");
    System.out.println("set counts individually");
    System.out.println("A=16, B=3, etc.");
    grades.setAcount(16);
    grades.setBcount(3);
    grades.setCcount(7);
    grades.setDcount(5);
    grades.setFcount(10);
    System.out.println();
    System.out.println("write (display) counts individually:");
    System.out.println();
    System.out.println("Verify A=16, B=3, etc.");
    System.out.println();
    grades.writeAcount();
    grades.writeBcount();
    grades.writeCcount();
    grades.writeDcount();
    grades.writeFcount();
    System.out.println();
    System.out.println("return total number of grades");
    System.out.println();
    System.out.println("Total number of grades = "
        + grades.getTotalNumberOfGrades());
    System.out.println();
    System.out.println("===============================");

    System.out.println();
    System.out.println("Test case 5:");
    System.out.println("set counts as a group: A=5, B=2, C=6, D=2, F=9 etc.");
    grades.set(5, 2, 6, 2, 9);
    System.out.println();
    System.out.println("return counts individually:");
    System.out.println();
    System.out.println("Verify A=5, B=2, etc.");
    System.out.println();
    System.out.println("A count = " + grades.getAcount());
    System.out.println("B count = " + grades.getBcount());
    System.out.println("C count = " + grades.getCcount());
    System.out.println("D count = " + grades.getDcount());
    System.out.println("F count = " + grades.getFcount());
    System.out.println();
    System.out.println();
    System.out.println("return total number of grades");
    System.out.println();
    System.out.println("Total number of grades = "
        + grades.getTotalNumberOfGrades());
    System.out.println();
    System.out.println("===============================");
  }

  void readInput() {
    Scanner s = new Scanner(System.in);
    int total = 0;

    for (int i = 0; i < Rep05GradesGraph1.indexGrade.length; i++) {

      System.out.printf("How many %c's?\n", Rep05GradesGraph1.indexGrade[i]);
      this.gradeNumArr[i] = s.nextInt();

      while (0 > this.gradeNumArr[i]) {
        System.out.println("Number of grade cannot be negative.");
        System.out.printf("Reenter number of %c's:\n", Rep05GradesGraph1.indexGrade[i]);
        this.gradeNumArr[i] = s.nextInt();
      }
      total += this.gradeNumArr[i];
    }
    setTotal(total);

    s.close();
  }

  int getTotalNumberOfGrades() {
    return this.total;
  }

  void writeOutput() {
    for (int i = 0; i < Rep05GradesGraph1.indexGrade.length; i++) {
      System.out.printf("Number of %c's = %d\n", Rep05GradesGraph1.indexGrade[i], this.gradeNumArr[i]);
    }
  }

  void set(int... numbers) {
    int total = 0;
    for (int i = 0; i < numbers.length; i++) {
      this.gradeNumArr[i] = numbers[i];
      total += numbers[i];
    }
    setTotal(total);
  }

  void setTotal(int total) {
    this.total = total;
  }

  void printTotal() {
    System.out.println("return total number of grades");
    System.out.println();
    System.out.printf("Total number of grade = %d", this.total);
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

  void setAcount(int n) {
    this.total -= this.gradeNumArr[0];
    this.total += n;
    this.gradeNumArr[0] = n;
  }

  void setBcount(int n) {
    this.total -= this.gradeNumArr[1];
    this.total += n;
    this.gradeNumArr[1] = n;
  }

  void setCcount(int n) {
    this.total -= this.gradeNumArr[2];
    this.total += n;
    this.gradeNumArr[2] = n;
  }

  void setDcount(int n) {
    this.total -= this.gradeNumArr[3];
    this.total += n;
    this.gradeNumArr[3] = n;
  }

  void setFcount(int n) {
    this.total -= this.gradeNumArr[4];
    this.total += n;
    this.gradeNumArr[4] = n;
  }
}
