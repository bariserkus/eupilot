#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    float a = 100.0;

    // Example Random Number Generation
    //    for (int i=0; i<20; ++i)
    //    printf("%f\n", ((float)rand()/(float)(RAND_MAX)) * a);

/*
 * MATRIX SUMMATION
 */

    printf("Matrix Summation Example\n");
    int r = 10, c = 10;
    //int r = 45500, c = 45500;
    int n = r * c;

    printf("Size of Double: %ld Bytes\n", sizeof(double));
    printf("ArrA Size: %lld GB \n", (unsigned long long int) n / 134217728);
    printf("Total Memory Required: %lld GB \n", (unsigned long long int) 3 * n / 134217728);

    //Setup Matrix A
    clock_t begin = clock();
    double * arrA = calloc(n , sizeof(double));
    if (arrA == NULL) {
        printf("Unable to allocate memory for arrA\n");
        return -1;
    }

    for (int i = 0; i < n; ++i){
        srand((unsigned int)time(NULL));
        arrA[i] = ((float)rand() / (float)(RAND_MAX)) * a;
        // printf("a[%d]: %f\n", i, arrA[i]);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Matrix A Generated. Duration: %f sec\n", time_spent);

    //Setup Matrix B
    begin = clock();
    double * arrB = calloc(n , sizeof(double));
    if (arrA == NULL) {
        printf("Unable to allocate memory for arrB\n");
        return -1;
    }

    for (int i = 0; i < n; ++i){
        srand((unsigned int)time(NULL));
        arrB[i] = ((float)rand() / (float)(RAND_MAX)) * a;
        // printf("a[%d]: %f\n", i, arrA[i]);
    }
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Matrix B Generated. Duration: %f sec\n", time_spent);

    //Setup Matrix C
    begin = clock();
    double * arrC = calloc(n , sizeof(double));
    if (arrC == NULL) {
        printf("Unable to allocate memory for arrC\n");
        return -1;
    }
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Matrix C Memory Allocated. Duration: %f sec\n", time_spent);

    // Matrix Summation
    begin = clock();
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j) {
            arrC[i * c + j] = arrA[i * c + j] + arrB[i * c + j];
            //printf("Row: %d, Col: %d processed.\n", i, j);
        }
        //printf("\n");
    }
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Summation Complete. Duration: %f sec\n\n", time_spent);

    free(arrA);
    free(arrB);
    free(arrC);




/*
 * MATRIX MULTIPLICATION
 */

    printf("Matrix Multiplication Example\n");
    int rA = 1000, cA = 1500, rB = cA, cB = 2000;
    int rC = rA, cC = cB;
    int nA = rA * cA, nB = rB * cB, nC = rC * cC;

    printf("Size of Double: %ld Bytes\n", sizeof(double));
    printf("ArrA Size: %lld MB \n", (unsigned long long int) nA * 8 / 1024 / 1024);
    printf("ArrB Size: %lld MB \n", (unsigned long long int) nB * 8 / 1024 / 1024);
    printf("ArrC Size: %lld MB \n", (unsigned long long int) nC * 8 / 1024 / 1024);
    printf("Total Memory Required: %lld MB \n", (unsigned long long int) (nA + nB + nC) * 8 / 1024 / 1024);

    //Setup Matrix A
    begin = clock();
    arrA = calloc(nA, sizeof(double));
    if (arrA == NULL) {
        printf("Unable to allocate memory for arrA\n");
        return -1;
    }

    srand((unsigned int)time(NULL));
    for (int i = 0; i < nA; ++i){
        arrA[i] = ((float)rand() / (float)(RAND_MAX)) * a;
        // printf("a[%d]: %f\n", i, arrA[i]);
    }
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Matrix A Generated. Duration: %f sec\n", time_spent);

    //Setup Matrix B
    begin = clock();
    arrB = calloc( nB, sizeof(double));
    if (arrA == NULL) {
        printf("Unable to allocate memory for arrB\n");
        return -1;
    }

    srand((unsigned int)time(NULL));
    for (int i = 0; i < nB; ++i){
        arrB[i] = ((float)rand() / (float)(RAND_MAX)) * a;
        // printf("a[%d]: %f\n", i, arrA[i]);
    }
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Matrix B Generated. Duration: %f sec\n", time_spent);

    //Setup Matrix C
    begin = clock();
    arrC = calloc(nC , sizeof(double));
    if (arrC == NULL) {
        printf("Unable to allocate memory for arrC\n");
        return -1;
    }
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Matrix C Memory Allocated. Duration: %f sec\n", time_spent);


    // Check if the matrix dimensions match
    if (cA != rB) {
        printf("Columns of A should be equal to Rows of B\n");
        return -1;
    }

    // Matrix Multiplication
    begin = clock();
    double sum;
    for (int i = 0; i < rA; ++i){
        for (int k = 0; k < cB; ++k){
            sum = 0;
            for (int j = 0; j < cA; ++j) {
                arrC[i * cC + k] += arrA[i * cA + j] * arrB[j * cB + k];
            }
        }
        //printf("Row: %d processed.\n", i);
        //printf("\n");
    }
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Multiplication Complete. Duration: %f sec\n", time_spent);


/*
    r = rA, c = cA;
    printf("Matrix A: \n");
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j) {
            printf("%f  ", arrA[i * c + j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Matrix B: \n");
    r = rB, c = cB;
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j) {
            printf("%f  ", arrB[i * c + j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Matrix C: \n");
    r = rC, c = cC;
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j) {
            printf("%f  ", arrC[i * c + j]);
        }
        printf("\n");
    }
*/

    free(arrA);
    free(arrB);
    free(arrC);

    return 0;
}
