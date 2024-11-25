import java.applet.Applet;
import java.awt.Graphics;

public class AppletLifeCycleDemo extends Applet {
    @Override
    public void init() {
        // Called when the applet is first loaded
        System.out.println("Applet is being initialized (init method)");
    }

    @Override
    public void start() {
        // Called when the applet starts or resumes
        System.out.println("Applet has started (start method)");
    }

    @Override
    public void paint(Graphics g) {
        // Called to redraw the applet
        System.out.println("Applet is being painted (paint method)");
        g.drawString("Welcome to Applet Lifecycle Demo!", 20, 20);
    }

    @Override
    public void stop() {
        // Called when the applet is stopped
        System.out.println("Applet is being stopped (stop method)");
    }

    @Override
    public void destroy() {
        // Called when the applet is being destroyed
        System.out.println("Applet is being destroyed (destroy method)");
    }
}
