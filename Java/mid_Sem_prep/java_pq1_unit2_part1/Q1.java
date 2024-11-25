public class Q1 {
    // Instance variables (fields) automatically get default values
    byte defaultByte;
    short defaultShort;
    int defaultInt;
    long defaultLong;
    float defaultFloat;
    double defaultDouble;
    char defaultChar;
    boolean defaultBoolean;

    public static void main(String[] args) {
        // Create an instance of the class
        Q1 d = new Q1();

        // Displaying default values
        System.out.println("Default value of byte: " + d.defaultByte);
        System.out.println("Default value of short: " + d.defaultShort);
        System.out.println("Default value of int: " + d.defaultInt);
        System.out.println("Default value of long: " + d.defaultLong);
        System.out.println("Default value of float: " + d.defaultFloat);
        System.out.println("Default value of double: " + d.defaultDouble);
        System.out.println("Default value of char: " + d.defaultChar + " (Unicode value: " + (int) d.defaultChar + ")");
        System.out.println("Default value of boolean: " + d.defaultBoolean);
    }
}
