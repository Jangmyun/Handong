import javax.swing.JFrame;
import javax.swing.JLabel;

import java.awt.BorderLayout;
import java.awt.Container;

public class BorderLayoutDemo extends JFrame {
  public static void main(String[] args) {
    BorderLayoutDemo gui = new BorderLayoutDemo();
    gui.setVisible(true);
  }

  public BorderLayoutDemo() {
    super();
    setSize(300, 200);
    addWindowListener(new WindowDestroyer());

    Container contentPane = getContentPane();

    // getContentPane().setLayout(new BorderLayout());
    // Border Layout Manager
    contentPane.setLayout(new BorderLayout());

    JLabel label1 = new JLabel("First Label here");
    contentPane.add(label1, BorderLayout.NORTH);
    JLabel label2 = new JLabel("Second Label here");
    contentPane.add(label2, BorderLayout.SOUTH);
    JLabel label3 = new JLabel("Third Label anywhere");
    contentPane.add(label3, BorderLayout.CENTER);
  }
}
