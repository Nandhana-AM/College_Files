import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

public class MousePositionExample extends JFrame {

    private JLabel label; // Label to display coordinates

    public MousePositionExample() {
        // Set the title for the frame
        setTitle("Mouse Position Example");

        // Set the size of the window
        setSize(400, 400);

        // Set the layout manager
        setLayout(new FlowLayout());

        // Create a label to show the coordinates
        label = new JLabel("Move the mouse inside the window");
        add(label);

        // Add MouseMotionListener to capture the mouse movement
        addMouseMotionListener(new MouseMotionAdapter() {
            @Override
            public void mouseMoved(MouseEvent e) {
                // Get the x and y coordinates of the mouse
                int x = e.getX();
                int y = e.getY();
                
                // Update the label with the new mouse coordinates
                label.setText("X: " + x + "  Y: " + y);
            }
        });

        // Set default close operation
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Set the window visibility
        setVisible(true);
    }

    public static void main(String[] args) {
        // Create an instance of the frame to run the application
        new MousePositionExample();
    }
}
