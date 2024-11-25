import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Calculator extends JFrame {
    private JTextField num1Field, num2Field, resultField;
    private JButton addButton, subtractButton, multiplyButton, divideButton;

    public Calculator() {
        // Set up the frame
        setTitle("Basic Calculator");
        setSize(400, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new GridLayout(5, 2, 10, 10)); // 5 rows, 2 columns

        // Create components
        JLabel num1Label = new JLabel("Enter first number:");
        num1Field = new JTextField();
        JLabel num2Label = new JLabel("Enter second number:");
        num2Field = new JTextField();
        JLabel resultLabel = new JLabel("Result:");
        resultField = new JTextField();
        resultField.setEditable(false); // Result field is read-only

        addButton = new JButton("Add");
        subtractButton = new JButton("Subtract");
        multiplyButton = new JButton("Multiply");
        divideButton = new JButton("Divide");

        // Add components to the frame
        add(num1Label);
        add(num1Field);
        add(num2Label);
        add(num2Field);
        add(addButton);
        add(subtractButton);
        add(multiplyButton);
        add(divideButton);
        add(resultLabel);
        add(resultField);

        // Add action listeners for the buttons
        addButton.addActionListener(new CalculatorActionListener("+"));
        subtractButton.addActionListener(new CalculatorActionListener("-"));
        multiplyButton.addActionListener(new CalculatorActionListener("*"));
        divideButton.addActionListener(new CalculatorActionListener("/"));

        // Make the frame visible
        setVisible(true);
    }

    // ActionListener class for handling button clicks
    private class CalculatorActionListener implements ActionListener {
        private String operation;

        public CalculatorActionListener(String operation) {
            this.operation = operation;
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            try {
                // Parse input numbers
                double num1 = Double.parseDouble(num1Field.getText());
                double num2 = Double.parseDouble(num2Field.getText());
                double result = 0;

                // Perform the operation
                switch (operation) {
                    case "+":
                        result = num1 + num2;
                        break;
                    case "-":
                        result = num1 - num2;
                        break;
                    case "*":
                        result = num1 * num2;
                        break;
                    case "/":
                        if (num2 == 0) {
                            JOptionPane.showMessageDialog(null, "Division by zero is not allowed!", "Error", JOptionPane.ERROR_MESSAGE);
                            return;
                        }
                        result = num1 / num2;
                        break;
                }

                // Display the result
                resultField.setText(String.valueOf(result));
            } catch (NumberFormatException ex) {
                JOptionPane.showMessageDialog(null, "Please enter valid numbers!", "Input Error", JOptionPane.ERROR_MESSAGE);
            }
        }
    }

    public static void main(String[] args) {
        new Calculator();
    }
}
