import java.util.Scanner;

public class Rep03CheckDate2 {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    System.out.println("Please enter a date to be checked (mm/dd/yyyy), or type 'exit' to quit:");
    s.useDelimiter("[/\n]");

    String month = s.next();
    String day = s.next();
    String year = s.next();

    isValidDate(month, day, year);

    s.close();
  }

  static boolean isValidDate(String month, String day, String year) {
    if ((month.length() != 2) || (day.length() != 2) || (year.length() != 4)) {
      System.out.println("Invalid format. Please enter the date in mm/dd/yyyy format.");
      return false;
    }
    if (!(isNumber(month) && isNumber(day) && isNumber(year))) {
      System.out.println("Invalid format. Please enter the date in mm/dd/yyyy format.");
      return false;
    }

    int monthN = Integer.parseInt(month);
    int dayN = Integer.parseInt(day);
    int yearN = Integer.parseInt(year);

    if (!(0 < monthN && monthN <= 12)) { // 달이 올바르게 입력됐는지 체크
      System.out.printf("Your date was %d/%d/%d\n", monthN, dayN, yearN);
      System.out.println("It is not a valid date.");
      System.out.println("The reason it is invalid: The month value is not from 1 to 12.");
      return false;
    }
    isValidDay(monthN, dayN, yearN);

    return true;
  }

  static boolean isNumber(String str) {
    return str.matches("\\d+");
  }

  static boolean isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
      return true;
    }
    return false;
  }

  static boolean isValidDay(int month, int day, int year) {
    if (month < 1) {
      System.out.printf("Date is %d/%d/%d\n", month, day, year);
      System.out.printf("Your date was %d/%d/%d\n", month, day, year);
      System.out.println("It is not a valid date.");
      System.out.println("The reason it is invalid: The day value must not be 0 or less.");
      return false;
    }
    if (month == 2 && !isLeapYear(year) && day > 28) {
      System.out.printf("Date is %d/%d/%d\n", month, day, year);
      System.out.printf("Your date was %d/%d/%d\n", month, day, year);
      System.out.println("It is not a valid date.");
      System.out.println("The reason it is invalid: The day value is greater than 28 in February in a non-leap year.");
      return false;
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
      System.out.printf("Date is %d/%d/%d\n", month, day, year);
      System.out.printf("Your date was %d/%d/%d\n", month, day, year);
      System.out.println("It is not a valid date.");
      System.out.println("The reason it is invalid: The day value is greater than 30.");
      return false;
    }
    if (day > 31) {
      System.out.printf("Date is %d/%d/%d\n", month, day, year);
      System.out.printf("Your date was %d/%d/%d\n", month, day, year);
      System.out.println("It is not a valid date.");
      System.out.println("The reason it is invalid: The day value is greater than 31.");
      return false;
    }
    System.out.printf("Date is %d/%d/%d\n", month, day, year);
    System.out.printf("Your date was %d/%d/%d\n", month, day, year);
    System.out.println("It is a valid date.");

    return true;
  }
}
