import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

public class MenuDialogExample {

    public static void main(String[] args) {
        // Create a frame
        JFrame frame = new JFrame("Menu and Dialog Example");

        // Set the default close operation
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        // Set the size of the frame
        frame.setSize(400, 400);
        
        // Set the layout
        frame.setLayout(new BorderLayout());

        // Create a menu bar
        JMenuBar menuBar = new JMenuBar();
        
        // Create a menu
        JMenu menu = new JMenu("Options");
        
        // Create menu items
        JMenuItem showDialogItem = new JMenuItem("Show Dialog");
        JMenuItem exitItem = new JMenuItem("Exit");
        
        // Add action listeners for menu items
        showDialogItem.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Show a dialog box when the menu item is clicked
                JOptionPane.showMessageDialog(frame, "This is a dialog box!", "Dialog", JOptionPane.INFORMATION_MESSAGE);
            }
        });
        
        exitItem.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Exit the application when the Exit menu item is clicked
                System.exit(0);
            }
        });

        // Add menu items to the menu
        menu.add(showDialogItem);
        menu.addSeparator(); // Adds a separator line between items
        menu.add(exitItem);

        // Add menu to the menu bar
        menuBar.add(menu);

        // Set the menu bar for the frame
        frame.setJMenuBar(menuBar);
        
        // Make the frame visible
        frame.setVisible(true);
    }
}
