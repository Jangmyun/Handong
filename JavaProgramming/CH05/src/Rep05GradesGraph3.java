import java.util.Scanner;

public class Rep05GradesGraph3 {
  static char indexGrade[] = { 'A', 'B', 'C', 'D', 'F' };
  int gradeNumArr[] = new int[5];
  int total;

  public static void main(String[] args) {
    System.out.println();
    System.out.println("Test case 1: readInput() and writeOutput()");
    Rep05GradesGraph3 grades = new Rep05GradesGraph3();
    grades.readInput();
    System.out.println();
    System.out.println("Verify results with writeOutput():");
    grades.writeOutput();
    System.out.println();
    grades.draw();
    System.out.println("===============================");
    System.out.println();

    System.out.println();
    System.out.println("Test case 2:");
    System.out.println("set counts as a group: A=1, B=2, c=3,d=4,e=5 etc.");
    grades.set(1, 2, 3, 4, 5);
    System.out.println();
    System.out.println("Verify results with writeOutput():");
    grades.writeOutput();
    System.out.println();
    grades.draw();
    System.out.println("===============================");
    System.out.println();

    System.out.println();
    System.out.println("Test case 3:");
    System.out.println("set counts individually");
    System.out.println("A=5, B=3, etc.");
    grades.setAcount(5);
    grades.setBcount(3);
    grades.setCcount(2);
    grades.setDcount(1);
    grades.setFcount(9);
    System.out.println();
    System.out.println("Verify results with writeOutput():");
    grades.writeOutput();
    System.out.println();
    grades.draw();
    System.out.println("===============================");
    System.out.println();

    System.out.println();
    System.out.println("Test case 4:");
    System.out.println("return percentages of each grade");
    System.out.println();
    grades.set(10, 9, 8, 7, 6);
    System.out.println("Verify percentages A=25, B=23, C=20, D=18, F=15");
    System.out.println();
    System.out.println("A = " + grades.getPercentA());
    System.out.println("B = " + grades.getPercentB());
    System.out.println("C = " + grades.getPercentC());
    System.out.println("D = " + grades.getPercentD());
    System.out.println("F = " + grades.getPercentF());
    System.out.println();
    grades.draw();
    System.out.println("===============================");
    System.out.println();

    System.out.println();
    System.out.println("Test case 5:");
    System.out.println("Draw graph of grade percentages");
    System.out.println();
    System.out.println("Verify A=100%");
    grades.set(1, 0, 0, 0, 0);
    System.out.println();
    grades.draw();
    System.out.println("===============================");
    System.out.println();

    System.out.println();
    System.out.println("Test case 6:");
    System.out.println("Draw graph of grade percentages");
    System.out.println();
    System.out.println("Verify all 0%");
    grades.set(0, 0, 0, 0, 0);
    System.out.println();
    grades.draw();
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

  void draw() {
    int count = this.gradeNumArr.length;

    System.out.println("2    10   20   30   40   50   60   70   80   90   100");
    System.out.println("|    |    |    |    |    |    |    |    |    |    |");
    System.out.println("***************************************************");

    if (this.total == 0) {
      for (int i = 0; i < count; i++) {
        System.out.printf(" %c %d\n", Rep05GradesGraph3.indexGrade[i], 0);
      }
      return;
    }

    for (int i = 0; i < count; i++) {
      for (int j = 0; j < getPercent(i) / 2; j++) {
        System.out.print("*");
      }
      System.out.printf(" %c %d\n", Rep05GradesGraph3.indexGrade[i], getPercent(i));
    }
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

  int getPercent(int n) {
    return this.gradeNumArr[n] * 100 / this.total;
  }

  int getPercentA() {
    return getPercent(0);
  }

  int getPercentB() {
    return getPercent(1);
  }

  int getPercentC() {
    return getPercent(2);
  }

  int getPercentD() {
    return getPercent(3);
  }

  int getPercentF() {
    return getPercent(4);
  }
}
