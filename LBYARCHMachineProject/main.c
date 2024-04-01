#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

extern double dot_product_asm(double valA, double valB);

double dot_product_c(double *A, double *B, int n) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        result += A[i] * B[i];
    }
    return result;
}

int main() {
    int n;
    double *A, *B, sdot;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the length of the vectors: ");
    scanf_s("%d", &n);

    A = (double*)malloc(n * sizeof(double));
    B = (double*)malloc(n * sizeof(double));

    // value randomizer function
    start = clock();
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        A[i] = (double)rand() / RAND_MAX;
        // printf("%d A: %.2f \n", i+1, A[i]);
        B[i] = (double)rand() / RAND_MAX;
        // printf("%d B: %.2f \n", i+1, B[i]);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by number randomizer: %.2f seconds\n", cpu_time_used);

    // C - timing, computing, printing
    start = clock();
    sdot = dot_product_c(A, B, n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Dot Product (C): %.2f \n", sdot);
    printf("Time taken by C kernel: %.2f seconds\n", cpu_time_used);

    // Assembly - timing, computing, printing
    double valA = 0.0;
    double valB = 0.0;
    sdot = 0.0;

    start = clock();
    for (int i = 0; i < n; i++) {
        valA = A[i];
        valB = B[i];
        sdot += dot_product_asm(valA, valB);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Dot Product (Assembly): %.2f \n", sdot);
    printf("Time taken by Assembly kernel: %.2f seconds\n", cpu_time_used);

    free(A);
    free(B);
    
    return 0;
}