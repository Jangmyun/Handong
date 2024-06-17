import javax.swing.JFrame;
import javax.swing.JLabel;

public class FirstWindow extends JFrame {
  public FirstWindow() {
    super();

    setSize(300, 200);
    JLabel label = new JLabel("Please don't click that button!");
    getContentPane().add(label);

    WindowDestroyer listener = new WindowDestroyer();
    addWindowListener(listener);
  }
}
