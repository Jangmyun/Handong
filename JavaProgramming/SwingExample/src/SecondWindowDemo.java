import java.awt.Color;

public class SecondWindowDemo {
  public static void main(String[] args) {
    SecondWindow window1 = new SecondWindow();
    window1.setVisible(true);

    SecondWindow window2 = new SecondWindow(Color.PINK);
    window2.setVisible(true);
  }
}

// JFrame method
// public JFrame()
// getContentPane().add(Item)
// Container getContentPane();
// addWindowListener(WindowListener e);

// setBackground(Color c)
// setForeground(Color c)
// setSize(width, height)
// setTitle(String title);
// setVisible(boolean isVisible);