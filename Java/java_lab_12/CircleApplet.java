import java.applet.Applet;
import java.awt.Graphics;

public class CircleApplet extends Applet {
    @Override
    public void paint(Graphics g) {
        // Set the coordinates and size of the circle
        int x = 50; // x-coordinate of the top-left corner
        int y = 50; // y-coordinate of the top-left corner
        int width = 100; // Diameter of the circle
        int height = 100; // Diameter of the circle (same for a perfect circle)

        // Draw the circle
        g.drawOval(x, y, width, height);

        // Add text to describe the circle
        g.drawString("This is a circle!", x + 20, y + 120);
    }
}
