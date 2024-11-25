public class Q2 {
    public static void main(String[] args) {
        // 1. Increment and Decrement Operators
        int a = 5;
        int b = a++; // Post-increment
        int c = ++a; // Pre-increment
        int d = a--; // Post-decrement
        int e = --a; // Pre-decrement

        System.out.println("Increment and Decrement Operators:");
        System.out.println("Initial value of a: 5");
        System.out.println("Value after post-increment (b = a++): " + b); // 5
        System.out.println("Value after pre-increment (c = ++a): " + c);  // 7
        System.out.println("Value after post-decrement (d = a--): " + d); // 7
        System.out.println("Value after pre-decrement (e = --a): " + e);  // 5
        System.out.println();

        // 2. Bitwise Complement Operator
        int f = 5;  // In binary: 0000 0101
        int g = ~f; // Bitwise complement: 1111 1010 (2's complement = -6)

        System.out.println("Bitwise Complement Operator:");
        System.out.println("Bitwise complement of 5 (~f): " + g);
        System.out.println();

        // 3. Arithmetic Operators
        int x = 10;
        int y = 3;

        System.out.println("Arithmetic Operators:");
        System.out.println("x + y = " + (x + y));  // Addition
        System.out.println("x - y = " + (x - y));  // Subtraction
        System.out.println("x * y = " + (x * y));  // Multiplication
        System.out.println("x / y = " + (x / y));  // Division
        System.out.println("x % y = " + (x % y));  // Modulus (remainder)
        System.out.println();

        // 4. Relational Operators
        System.out.println("Relational Operators:");
        System.out.println("x == y: " + (x == y)); // Equal to
        System.out.println("x != y: " + (x != y)); // Not equal to
        System.out.println("x > y: " + (x > y));   // Greater than
        System.out.println("x < y: " + (x < y));   // Less than
        System.out.println("x >= y: " + (x >= y)); // Greater than or equal to
        System.out.println("x <= y: " + (x <= y)); // Less than or equal to
        System.out.println();

        // 5. Bitwise Operators
        int h = 5;  // In binary: 0000 0101
        int i = 3;  // In binary: 0000 0011

        System.out.println("Bitwise Operators:");
        System.out.println("h & i (AND): " + (h & i));   // 0000 0001 = 1
        System.out.println("h | i (OR): " + (h | i));    // 0000 0111 = 7
        System.out.println("h ^ i (XOR): " + (h ^ i));   // 0000 0110 = 6
        System.out.println("h << 1 (Left shift): " + (h << 1)); // 0000 1010 = 10
        System.out.println("h >> 1 (Right shift): " + (h >> 1)); // 0000 0010 = 2
        System.out.println();

        // 6. Conditional (Ternary) Operator
        int j = 10;
        int k = 20;
        int max = (j > k) ? j : k;

        System.out.println("Conditional (Ternary) Operator:");
        System.out.println("The maximum value between j and k is: " + max);
    }
}
