import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class MouseAdapterExample extends JFrame {
    private JLabel label;

    public MouseAdapterExample() {
        // Set up the frame
        setTitle("MouseAdapter Example");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new FlowLayout());

        // Create a label to display mouse information
        label = new JLabel("Perform mouse actions...");
        add(label);

        // Add a custom MouseAdapter to handle mouse events
        addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                label.setText("Mouse Clicked at X: " + e.getX() + " - Y: " + e.getY());
            }

            @Override
            public void mousePressed(MouseEvent e) {
                label.setText("Mouse Pressed at X: " + e.getX() + " - Y: " + e.getY());
            }
        });

        addMouseMotionListener(new MouseAdapter() {
            @Override
            public void mouseMoved(MouseEvent e) {
                label.setText("Mouse Moved to X: " + e.getX() + " - Y: " + e.getY());
            }
        });

        setVisible(true);
    }

    public static void main(String[] args) {
        new MouseAdapterExample();
    }
}
