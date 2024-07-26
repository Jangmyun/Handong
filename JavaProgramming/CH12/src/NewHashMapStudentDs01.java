import java.io.File;
import java.util.Scanner;

public class NewHashMapStudentDs01 {
  public static void main(String[] args) {
    try {
      Scanner s = new Scanner(new File("./students.txt"));
      while (s.hasNextLine()) {
        System.out.println(s.nextLine());
      }
      s.close();
    } catch (Exception e) {
      System.out.println(e);
    }

  }
}
