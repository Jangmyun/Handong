import java.util.*;

public class Rep11Palindrome2 {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    System.out.println("Enter a string");
    String input;
    input = s.nextLine();

    input = input.replaceAll("[^a-zA-Z]", "");
    input = input.toUpperCase();

    palindrome(input);

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
