#include <stdio.h>
#include <pthread.h>  // for use threads in C

#define SIZE 3  // matrix size is 3x3

// define matrix A
int A[SIZE][SIZE] = {
    {2, 4, 6},
    {1, 2, 3},
    {3, 6, 9}
};

// define matrix B
int B[SIZE][SIZE] = {
    {1, 2, 3},
    {2, 4, 6},
    {3, 6, 9}
};

// result matrix C
int C[SIZE][SIZE]; 

// this function run by thread to calculate one row of result matrix
void* calculateRow(void* arg) {
    int row = *(int*)arg;  // get the row number this thread will work

    // loop all columns
    for (int col = 0; col < SIZE; col++) {
        C[row][col] = 0;  // start with 0

        // multiply row of A with column of B
        for (int k = 0; k < SIZE; k++) {
            C[row][col] += A[row][k] * B[k][col];  // add multiplied value
        }
    }

    pthread_exit(NULL);  // thread finish
}

int main() {
    pthread_t threads[SIZE];      // array for thread id
    int rowIndexes[SIZE];         // store row number to send for thread

    // create threads for each row
    for (int i = 0; i < SIZE; i++) {
        rowIndexes[i] = i;  // store the row number
        pthread_create(&threads[i], NULL, calculateRow, &rowIndexes[i]);  // start thread
    }

    // wait for all threads to finish
    for (int i = 0; i < SIZE; i++) {
        pthread_join(threads[i], NULL);  // wait for thread to complete
    }

    // print the result matrix
    printf("Result Matrix C:\n");
    for (int i = 0; i < SIZE; i++) {          // go through rows
        for (int j = 0; j < SIZE; j++) {      // go through columns
            printf("%d ", C[i][j]);           // print each value
        }
        printf("\n");                         // new line after row
    }

    return 0;  // end program
}
