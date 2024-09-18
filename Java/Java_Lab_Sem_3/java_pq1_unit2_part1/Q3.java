public class Q3 {

    public static void main(String[] args) {
        // One-dimensional array demonstration
        int[] arr1D = {1, 2, 3, 4, 5};
        
        System.out.println("One-dimensional array:");
        for (int i = 0; i < arr1D.length; i++) {
            System.out.print(arr1D[i] + " ");
        }
        System.out.println("\nLength of the one-dimensional array: " + arr1D.length + "\n");

        // Two-dimensional array demonstration
        int[][] arr2D = {
            {1, 2, 3},
            {4, 5, 6}
        };

        System.out.println("Two-dimensional array:");
        for (int i = 0; i < arr2D.length; i++) {
            for (int j = 0; j < arr2D[i].length; j++) {
                System.out.print(arr2D[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println("Number of rows in the two-dimensional array: " + arr2D.length);
        System.out.println("Number of columns in the first row: " + arr2D[0].length + "\n");

        // Multi-dimensional array demonstration
        int[][][] multiDimArray = {
            {
                {1, 2},
                {3, 4}
            },
            {
                {5, 6},
                {7, 8}
            }
        };

        System.out.println("Multi-dimensional array:");
        for (int i = 0; i < multiDimArray.length; i++) {
            for (int j = 0; j < multiDimArray[i].length; j++) {
                for (int k = 0; k < multiDimArray[i][j].length; k++) {
                    System.out.print(multiDimArray[i][j][k] + " ");
                }
                System.out.println();
            }
            System.out.println();
        }
        System.out.println("Number of dimensions in the multi-dimensional array: " + multiDimArray.length);
    }
}
