import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CheckboxesAndOptions {
    public static void main(String[] args) {
        // Create the frame
        JFrame frame = new JFrame("Checkboxes and Option Buttons");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 300);
        frame.setLayout(new FlowLayout());

        // Create checkboxes
        JCheckBox checkbox1 = new JCheckBox("1");
        JCheckBox checkbox2 = new JCheckBox("2");
        JCheckBox checkbox3 = new JCheckBox("3");

        // Create radio buttons and group them
        JRadioButton radioButton1 = new JRadioButton("4");
        JRadioButton radioButton2 = new JRadioButton("5");
        ButtonGroup radioGroup = new ButtonGroup();
        radioGroup.add(radioButton1);
        radioGroup.add(radioButton2);

        // Create a button to display selected numbers
        JButton displayButton = new JButton("Display Selected");
        
        // Create a text field to show the selected numbers
        JTextField textField = new JTextField(20);
        textField.setEditable(false);

        // Add an ActionListener to the button
        displayButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                StringBuilder selectedNumbers = new StringBuilder();

                // Check which checkboxes are selected
                if (checkbox1.isSelected()) {
                    selectedNumbers.append("1 ");
                }
                if (checkbox2.isSelected()) {
                    selectedNumbers.append("2 ");
                }
                if (checkbox3.isSelected()) {
                    selectedNumbers.append("3 ");
                }

                // Check which radio button is selected
                if (radioButton1.isSelected()) {
                    selectedNumbers.append("4 ");
                } else if (radioButton2.isSelected()) {
                    selectedNumbers.append("5 ");
                }

                // Display the selected numbers in the text field
                textField.setText(selectedNumbers.toString().trim());
            }
        });

        // Add components to the frame
        frame.add(checkbox1);
        frame.add(checkbox2);
        frame.add(checkbox3);
        frame.add(radioButton1);
        frame.add(radioButton2);
        frame.add(displayButton);
        frame.add(textField);

        // Make the frame visible
        frame.setVisible(true);
    }
}

