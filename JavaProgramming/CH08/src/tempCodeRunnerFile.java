import java.util.*;

public class Rep08Student3 {
  public static void main(String[] args) {
    Person[] personArr = {
        new Student2("Bob", 200),
        new Student3("Wendy", 303),
        new Student2("Eli", 500),
        new Student3("Xavier", 404),
        new Student2("Alice", 100),
        new Student3("Uma", 101),
        new Student2("Dana", 400),
        new Student3("Victor", 202),
        new Student2("Charlie", 300),
        new Student3("Yara", 505)
    };

    int s2Num = 0, s3Num = 0;

    for (int i = 0; i < personArr.length; i++) {
      if (personArr[i] instanceof Student2) {
        s2Num++;
      }
      if (personArr[i] instanceof Student3) {
        s3Num++;
      }
    }

    Student2[] s2Arr = new Student2[s2Num];
    Student3[] s3Arr = new Student3[s3Num];

    for (int i = 0; i < personArr.length; i++) {
      if (personArr[i] instanceof Student2) {
        s2Arr[--s2Num] = (Student2) personArr[i];
      }
      if (personArr[i] instanceof Student3) {
        s3Arr[--s3Num] = (Student3) personArr[i];
      }
    }

    Arrays.sort(s2Arr);
    Arrays.sort(s3Arr);
    System.out.println("Information of Student2");
    System.out.println();
    for (int i = 0; i < s2Arr.length; i++) {
      System.out.println(s2Arr[i]);
    }
    System.out.println();
    System.out.println("Information of Student3");
    System.out.println();
    for (int i = 0; i < s3Arr.length; i++) {
      System.out.println(s3Arr[i]);
    }

  }
}
