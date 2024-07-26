import javax.swing.*;
import java.awt.*;

public class FlowLayoutDemo extends JFrame {
  public static void main(String[] args) {
    FlowLayoutDemo gui = new FlowLayoutDemo();
    gui.setVisible(true);
  }

  public FlowLayoutDemo() {
    super();
    setSize(300, 200);
    Container contentPane = getContentPane();
    addWindowListener(new WindowDestroyer());
    setTitle("Layout Demonstration");

    contentPane.setLayout(new FlowLayout());

    JLabel label1 = new JLabel("First Label here");
    contentPane.add(label1);
    JLabel label2 = new JLabel("Second Label here");
    contentPane.add(label2);
    JLabel label3 = new JLabel("Third Label here");
    contentPane.add(label3);
  }
}
