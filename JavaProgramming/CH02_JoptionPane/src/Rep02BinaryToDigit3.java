import javax.swing.JOptionPane;

public class Rep02BinaryToDigit3 {
  public static void main(String[] args) {
    while (true) {
      String inputBinary = JOptionPane.showInputDialog("Enter a 4-bit binary number:");
      int binary = 0;
      boolean isValid = true;
      if (inputBinary.length() != 4) {
        JOptionPane.showMessageDialog(null, "Invalid input. Please enter a 4-bit binary number.");
        isValid = false;
      } else {
        for (int i = 0; i < 4; i++) {
          if (inputBinary.charAt(i) != '0' && inputBinary.charAt(i) != '1') {
            JOptionPane.showMessageDialog(null, "Invalid input. Please enter a 4-bit binary number.");
            isValid = false;
          }
        }
      }
      if (isValid) {
        binary = Integer.parseInt(inputBinary, 2);
        JOptionPane.showMessageDialog(null, "The decimal value is: " + binary);
      }
      int another = JOptionPane.showConfirmDialog(null, "Do you want to convert another number?", "Select an Option",
          JOptionPane.YES_NO_CANCEL_OPTION);
      if (another == 1) {
        break;
      }
    }
  }
}
