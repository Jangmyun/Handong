import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class MemoSaver extends JFrame implements ActionListener {

  private JTextArea theText;
  private String memo1 = "No Memo 1";
  private String memo2 = "No Memo 2";

  public MemoSaver() {
    super();
    setSize(300, 200);
    addWindowListener(new WindowDestroyer());
    setTitle("Memo Saver");
    Container contentPane = getContentPane();
    contentPane.setLayout(new BorderLayout());

    JPanel buttonPanel = new JPanel();
    buttonPanel.setBackground(Color.WHITE);
    buttonPanel.setLayout(new FlowLayout());

    JButton memoBtn1 = new JButton("Save Memo 1");
    memoBtn1.addActionListener(this);
    buttonPanel.add(memoBtn1);

    JButton memo2Button = new JButton("Save Memo 2");
    memo2Button.addActionListener(this);
    buttonPanel.add(memo2Button);

    JButton clearButton = new JButton("Clear");
    clearButton.addActionListener(this);
    buttonPanel.add(clearButton);

    JButton get1Button = new JButton("Get Memo 1");
    get1Button.addActionListener(this);
    buttonPanel.add(get1Button);

    JButton get2Button = new JButton("Get Memo 2");
    get2Button.addActionListener(this);
    buttonPanel.add(get2Button);

    contentPane.add(buttonPanel, BorderLayout.SOUTH);
    JPanel textPanel = new JPanel();
    textPanel.setBackground(Color.WHITE);
    theText = new JTextArea(10, 40);

    theText.setBackground(Color.WHITE);
    theText.setLineWrap(true);
    textPanel.add(theText);
    contentPane.add(textPanel, BorderLayout.CENTER);
  }

  public void actionPerformed(ActionEvent e) {
    String actionCommand = e.getActionCommand();
    if (actionCommand.equals("Save Memo 1"))
      memo1 = theText.getText();
    else if (actionCommand.equals("Save Memo 2"))
      memo2 = theText.getText();
    else if (actionCommand.equals("Clear"))
      theText.setText("");
    else if (actionCommand.equals("Get Memo 1"))
      theText.setText(memo1);
    else if (actionCommand.equals("Get Memo 2"))
      theText.setText(memo2);
    else
      theText.setText("Error in memo interface");
  }

  public static void main(String[] args) {
    MemoSaver guiMemo = new MemoSaver();
    guiMemo.setVisible(true);
  }
}
