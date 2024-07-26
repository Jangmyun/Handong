import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import java.util.Set;

public class NewHashMapStudentDs03 {
  public static void main(String[] args) {
    HashMap<Integer, ArrayList<String>> studentHashMap = new HashMap<>();
    try {
      Scanner s = new Scanner(new File("./students.txt"));
      while (s.hasNext()) {
        int studentId = Integer.parseInt(s.next());
        if (studentHashMap.containsKey(studentId)) {
          studentHashMap.get(studentId).add(s.nextLine().trim());
        } else {
          studentHashMap.put(studentId, new ArrayList<String>());
          studentHashMap.get(studentId).add(s.nextLine().trim());
        }
      }

      Set<Integer> keys = studentHashMap.keySet();
      for (int key : keys) {
        System.out.printf("Student: %d\n", key);
        for (String sub : studentHashMap.get(key)) {
          System.out.printf("%s ", sub);
        }
        System.out.println();
      }
      s.close();
    } catch (Exception e) {
      System.out.println(e);
    }

  }
}
