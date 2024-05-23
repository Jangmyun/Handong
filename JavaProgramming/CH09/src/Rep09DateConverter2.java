import java.util.Scanner;

public class Rep09DateConverter2 {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    String date;
    System.out.print("Enter date in numerical month/day format: ");
    date = s.nextLine();

    isValidDate(date);
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
      System.out.println(d);
    } catch (Exception e) {
      System.out.println(e.getMessage());
      return false;
    }
    return true;
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
