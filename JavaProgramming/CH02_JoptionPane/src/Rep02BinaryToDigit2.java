import javax.swing.JOptionPane;

public class Rep02BinaryToDigit2 {
  public static void main(String[] args) {
    String inputBinary = JOptionPane.showInputDialog("Enter a 4-bit binary number:");
    int binary = 0;
    if (inputBinary.length() != 4) {
      JOptionPane.showMessageDialog(null, "Invalid input. Please enter a 4-bit binary number.");
      return;
    } else {
      for (int i = 0; i < 4; i++) {
        if (inputBinary.charAt(i) != '0' && inputBinary.charAt(i) != '1') {
          JOptionPane.showMessageDialog(null, "Invalid input. Please enter a 4-bit binary number.");
          return;
        }
      }
      binary = Integer.parseInt(inputBinary, 2);
      System.out.println(binary);
    }
    JOptionPane.showMessageDialog(null, "The decimal value is: " + binary);
  }
}
