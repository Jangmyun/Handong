import javax.swing.*;

public class Rep02BinaryToDigit1 {
  public static void main(String[] args) {
    String inputBinary = JOptionPane.showInputDialog("Enter a 4-bit binary number:");
    int binary = Integer.parseInt(inputBinary, 2);
    System.out.println(binary);
    JOptionPane.showMessageDialog(null, "The decimal value is: " + binary);
  }
}
