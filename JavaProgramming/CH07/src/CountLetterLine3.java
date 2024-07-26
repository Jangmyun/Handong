import java.util.Scanner;

public class CountLetterLine3 {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    String option = "y";
    String input;

    while (option.equals("y")) {
      System.out.println("Enter a line of text, terminated by a period:");
      input = s.nextLine();

      while (input.charAt(input.length() - 1) != '.') {
        System.out.println("Your sentence does not end with a period.");
        System.out.println("Enter a line of text, terminated by a period:");
        input = s.nextLine();
      }

      System.out.print("The sentence you entered is ASCII CODE ");
      for (int i = 0; i < input.length(); i++) {
        if (input.charAt(i) != ' ') {
          int ascii = (int) (input.charAt(i));
          System.out.printf("%d ", ascii);
        }
      }
      System.out.println();

      input = input.toUpperCase();

      int[] freqArr = new int[26];

      for (int i = 0; i < input.length(); i++) {
        int ascii = (int) input.charAt(i);

        if (65 <= ascii && ascii <= 90) {
          freqArr[ascii - 65]++;
        }
      }
      for (int i = 0; i < freqArr.length; i++) {
        if (freqArr[i] != 0) {
          System.out.printf("%c %d\n", i + 65, freqArr[i]);
        }
      }
      System.out.print("Enter another line? (y for 'yes') or press any key to exit program: ");
      option = s.nextLine();
    }
  }
}
