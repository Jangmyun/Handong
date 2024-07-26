import java.util.Scanner;

public class CountLetterLine2 {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);

    String input;
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
  }
}
