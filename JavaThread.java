// simple program to do matrix multiplication using threads
public class JavaThread {

    static final int SIZE = 3; // 3x3 matrix

    // define matrix A
    static int[][] A = {
        {2, 4, 6},
        {1, 2, 3},
        {3, 6, 9}
    };

    // define matrix B
    static int[][] B = {
        {1, 2, 3},
        {2, 4, 6},
        {3, 6, 9}
    };

    // result matrix C
    static int[][] C = new int[SIZE][SIZE];

    // this class is used for make thread
    static class MultiplyThread extends Thread {
        int row; // which row this thread will work

        MultiplyThread(int row) {
            this.row = row;
        }

        // this run when thread start
        public void run() {
            // for each column in matrix
            for (int col = 0; col < SIZE; col++) {
                C[row][col] = 0; // start value is 0

                // do multiplication and add
                for (int k = 0; k < SIZE; k++) {
                    C[row][col] += A[row][k] * B[k][col];
                }
            }
        }
    }

    public static void main(String[] args) throws InterruptedException {
        MultiplyThread[] threads = new MultiplyThread[SIZE]; // array for threads

        // make and start thread for each row
        for (int i = 0; i < SIZE; i++) {
            threads[i] = new MultiplyThread(i); // give row number
            threads[i].start(); // start thread
        }

        // wait for all threads to finish
        for (int i = 0; i < SIZE; i++) {
            threads[i].join(); // wait until thread complete
        }

        // print result matrix
        System.out.println("Result Matrix C:");
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                System.out.print(C[i][j] + " "); // print each value
            }
            System.out.println(); // new line after each row
        }
    }
}
