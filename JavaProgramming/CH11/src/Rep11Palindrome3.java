import java.util.Scanner;

public class Rep11Palindrome3 {
  public static void main(String[] args) {

    Scanner s = new Scanner(System.in);

    String option = "y";
    String input;

    while (option.equals("y") || option.equals("Y")) {
      System.out.println("Enter a string");
      input = s.nextLine();
      input = input.replaceAll("[^a-zA-Z]", "");
      input = input.toUpperCase();
      palindrome(input);

      System.out.println();
      System.out.println("Enter another sentence? (y/n)");
      option = s.nextLine();
      if (option.equals("n") || option.equals("N")) {
        break;
      }
      System.out.println();
    }
  }

  private static void palindrome(String str) {
    if (str.equals("") || (str.length() == 1)) {
      System.out.println("The sentence is a palindrome");
      return;
    }
    if (str.charAt(0) != str.charAt(str.length() - 1)) {
      System.out.println("It is NOT a palindrome");
      return;
    }
    palindrome(str.substring(1, str.length() - 1));
  }
}
