import java.util.Arrays;

public class Rep08Student2 {
  public static void main(String[] args) {
    Student3[] students = new Student3[4];

    students[0] = new Student3("Fred", 991);
    students[1] = new Student3("Bill", 331);
    students[2] = new Student3("Adam", 412);
    students[3] = new Student3("Chris", 121);

    Arrays.sort(students);

    // Output the sorted array of students
    for (Student3 s : students) {
      System.out.println(s.toString());
    }
  }
}

class Student3 extends Student implements Comparable<Student3> {
  public Student3(String initialName, int initialStudentNumber) {
    super(initialName, initialStudentNumber);
  }

  public int compareTo(Student3 s) {
    return this.getName().compareTo(s.getName());
  }

}
