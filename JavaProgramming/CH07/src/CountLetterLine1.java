import java.util.Scanner;

public class CountLetterLine1 {
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
  }
}
