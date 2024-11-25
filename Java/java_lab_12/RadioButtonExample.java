import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class RadioButtonExample extends JFrame implements ActionListener {
    private JRadioButton redButton, greenButton, blueButton;
    private JLabel resultLabel;

    public RadioButtonExample() {
        // Set up the frame
        setTitle("Radio Button Example");
        setSize(300, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new FlowLayout());

        // Create radio buttons
        redButton = new JRadioButton("Red");
        greenButton = new JRadioButton("Green");
        blueButton = new JRadioButton("Blue");

        // Group the radio buttons to allow only one selection at a time
        ButtonGroup colorGroup = new ButtonGroup();
        colorGroup.add(redButton);
        colorGroup.add(greenButton);
        colorGroup.add(blueButton);

        // Add ActionListener to the radio buttons
        redButton.addActionListener(this);
        greenButton.addActionListener(this);
        blueButton.addActionListener(this);

        // Create a label to display the selected color
        resultLabel = new JLabel("Choose a color");

        // Add components to the frame
        add(redButton);
        add(greenButton);
        add(blueButton);
        add(resultLabel);

        // Make the frame visible
        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        // Check which radio button was selected and update the label accordingly
        if (e.getSource() == redButton) {
            resultLabel.setText("Selected Color: Red");
        } else if (e.getSource() == greenButton) {
            resultLabel.setText("Selected Color: Green");
        } else if (e.getSource() == blueButton) {
            resultLabel.setText("Selected Color: Blue");
        }
    }

    public static void main(String[] args) {
        new RadioButtonExample();
    }
}
