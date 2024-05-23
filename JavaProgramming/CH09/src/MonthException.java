public class MonthException extends Exception {
  public MonthException() {
    super("Invalid month. Month must be between 1 and 12.");
  }

  public MonthException(String message) {
    super(message);
  }
}
