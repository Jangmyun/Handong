import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.*;
import javax.swing.*;

public class ButtonDemo extends JFrame implements ActionListener {
  public static void main(String[] args) {
    ButtonDemo buttonGui = new ButtonDemo();
    buttonGui.setVisible(true);
  }

  public ButtonDemo() {
    super();
    setSize(300, 200);
    addWindowListener(new WindowDestroyer());
    setTitle("Button Demo");
    Container contentPane = getContentPane();

    contentPane.setLayout(new FlowLayout());

    JButton stopButton = new JButton("Red");
    stopButton.addActionListener(this);
    contentPane.add(stopButton);

    JButton goButton = new JButton("Green");
    goButton.addActionListener(this);
    contentPane.add(goButton);
  }

  public void actionPerformed(ActionEvent e) {
    Container contentPane = getContentPane();
    if (e.getActionCommand().equals("Red")) {
      contentPane.setBackground(Color.RED);
    } else if (e.getActionCommand().equals("Green")) {
      contentPane.setBackground(Color.GREEN);
    } else {
      System.out.println("Error in button interface");
    }
  }
}
