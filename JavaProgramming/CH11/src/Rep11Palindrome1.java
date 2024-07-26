import java.util.Scanner;

public class Rep11Palindrome1 {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    System.out.println("Enter a string");
    String input;
    input = s.nextLine();

    input = input.replaceAll("[^a-zA-Z]", "");
    input = input.toUpperCase();

    int startIndex = 0;
    int endIndex = input.length() - 1;

    while (startIndex < endIndex) {
      if (input.charAt(startIndex) != input.charAt(endIndex)) {
        System.out.println("It is NOT a palindrome");
        return;
      }
      startIndex++;
      endIndex--;
    }
    System.out.println("The sentence is a palindrome");
  }
}