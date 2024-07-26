import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class NewHashMapStudentDs02 {
  public static void main(String[] args) {
    HashMap<Integer, ArrayList<String>> studentHashMap = new HashMap<>();
    try {
      Scanner s = new Scanner(new File("./students.txt"));
      int lineNumber = 1;
      while (s.hasNext()) {
        int studentId = Integer.parseInt(s.next());
        if (studentHashMap.containsKey(studentId)) {
          studentHashMap.get(studentId).add(s.nextLine().trim());
        } else {
          studentHashMap.put(studentId, new ArrayList<String>());
          studentHashMap.get(studentId).add(s.nextLine().trim());
        }
        System.out.printf("students.txt line %d has been successfully stored in the HashMap.\n", lineNumber++);
      }
      s.close();
    } catch (Exception e) {
      System.out.println(e);
    }
  }
}
