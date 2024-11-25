import javax.swing.*;
import javax.swing.table.DefaultTableModel;

public class TableExample {

    public static void main(String[] args) {
        // Create frame
        JFrame frame = new JFrame("Table Example");

        // Create data for the table (2D array)
        String[][] data = {
            {"1", "John", "25"},
            {"2", "Jane", "30"},
            {"3", "Alice", "22"},
            {"4", "Bob", "28"}
        };

        // Column names for the table
        String[] columnNames = {"ID", "Name", "Age"};

        // Create a table with the data and column names
        JTable table = new JTable(data, columnNames);

        // Add the table to a scroll pane to make it scrollable
        JScrollPane scrollPane = new JScrollPane(table);

        // Add the scroll pane to the frame
        frame.add(scrollPane);

        // Set default close operation
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Set frame size
        frame.setSize(400, 300);

        // Make frame visible
        frame.setVisible(true);
    }
}
