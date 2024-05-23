public class DayException extends Exception {
  public DayException() {
    super("Invalid day for the given month.");
  }

  public DayException(String message) {
    super(message);
  }
}
