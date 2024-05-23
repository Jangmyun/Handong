import java.util.Scanner;

public class Rep09DateConverter3 {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    String date;
    char option = 'Y';

    while (option != 'N') {
      System.out.print("Enter date in numerical month/day format: ");
      date = s.nextLine();

      isValidDate(date);

      System.out.print("Again? (y/n): ");
      option = s.next().charAt(0);
      s.nextLine();
    }
  }

  public static boolean isValidDate(String d) {
    String[] date = d.split("/");
    try {
      if (!date[0].matches("\\d+") || 1 > Integer.parseInt(date[0]) || Integer.parseInt(date[0]) > 12) {
        throw new MonthException();
      }
      int month = Integer.parseInt(date[0]);
      if (!date[1].matches("\\d+") || 1 > Integer.parseInt(date[1]) || Integer.parseInt(date[1]) > getDays(month)) {
        throw new DayException();
      }
      System.out.println(toDateString(d));
    } catch (Exception e) {
      System.out.println(e.getMessage());
      return false;
    }
    return true;
  }

  public static String toDateString(String date) {
    String[] dateArr = date.split("/");
    return String.format("%s %d", getMonth(Integer.parseInt(dateArr[0])), Integer.parseInt(dateArr[1]));
  }

  private static String getMonth(int month) {
    switch (month) {
      case 1:
        return "January";
      case 2:
        return "February";
      case 3:
        return "March";
      case 4:
        return "April";
      case 5:
        return "May";
      case 6:
        return "June";
      case 7:
        return "July";
      case 8:
        return "August";
      case 9:
        return "September";
      case 10:
        return "October";
      case 11:
        return "November";
      case 12:
        return "December";
    }
    return "";
  }

  private static int getDays(int month) {
    switch (month) {
      case 1:
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
      case 12:
        return 31;
      case 4:
      case 6:
      case 9:
      case 11:
        return 30;
      case 2:
        return 28;
      default:
        return -1;
    }
  }
}
