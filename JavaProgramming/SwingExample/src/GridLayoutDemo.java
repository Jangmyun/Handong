import javax.swing.*;
import java.awt.*;

public class GridLayoutDemo extends JFrame {

  public static void main(String[] args) {
    GridLayoutDemo gui = new GridLayoutDemo();
    gui.setVisible(true);
  }

  public GridLayoutDemo() {
    super();
    setSize(300, 200);
    addWindowListener(new WindowDestroyer());
    setTitle("Layout Demonstration");

    Container contentPane = getContentPane();
    contentPane.setLayout(new GridLayout(2, 3));
    JLabel l1 = new JLabel("First");
    JLabel l2 = new JLabel("Second");
    JLabel l3 = new JLabel("Third");
    JLabel l4 = new JLabel(""); // empty String label
    JLabel l5 = new JLabel("Fifth");

    contentPane.add(l1);
    contentPane.add(l2);
    contentPane.add(l3);
    contentPane.add(l4);
    contentPane.add(l5);

  }
}
