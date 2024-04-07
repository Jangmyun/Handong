import java.util.*;

public class Rep03CheckDate1 {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    System.out.println("Please enter a date to be checked (mm/dd/yyyy), or type 'exit' to quit:");
    s.useDelimiter("[/\n]");

    String month = s.next();
    String day = s.next();
    String year = s.next();

    if (isValidDate(month, day, year)) {
      System.out.printf("Your date was %s/%s/%s\n", month, day, year);
      System.out.println("It is a valid date.");
    } else {
      System.out.println("Invalid format. Please enter the date in mm/dd/yyyy format.");
    }
    s.close();
  }

  static boolean isValidDate(String month, String day, String year) {
    if ((month.length() != 2) || (day.length() != 2) || (year.length() != 4)) {
      return false;
    }
    if (!(isNumber(month) && isNumber(day) && isNumber(year))) {
      return false;
    }
    // int monthN = Integer.parseInt(month);
    // int dayN = Integer.parseInt(day);
    // int yearN = Integer.parseInt(year);

    return true;
  }

  static boolean isNumber(String str) {
    return str.matches("\\d+");
  }
}
