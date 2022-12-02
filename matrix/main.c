#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    srand((unsigned int)time(NULL));
    float a = 100.0;

    // Example Random Number Generation
    //    for (int i=0; i<20; ++i)
    //    printf("%f\n", ((float)rand()/(float)(RAND_MAX)) * a);

    int r = 30000, c = 32500;
    int n = r * c;

    //Setup Matrix A
    clock_t begin = clock();
    double * arrA = calloc(n , sizeof(double));
    if (arrA == NULL) {
        printf("Unable to allocate memory for arrA\n");
        return -1;
    }

    for (int i = 0; i < n; ++i){
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

    printf("Summation Complete. Duration: %f sec", time_spent);

/*
 * Use for printing:
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j) {
            printf("%f  ", arrA[i * c + j]);
        }
        printf("\n");
    }
*/
    free(arrA);
    return 0;
}
