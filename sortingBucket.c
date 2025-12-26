#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Vectors/intVector.h"

void printArray(int arr[], int size) {
    printf("Sorted Array: ");
    printf("[%d, ", arr[0]);
    for (int i = 1; i < size-1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[size-1]);
    return;
}

void insertionSort(intVector *vector) {
    for (int i = 1; i < vector->size; i++) {
        int element = vector->data[i];
        int j = i-1;
        while (j >= 0 && vector->data[j] > element) {
            vector->data[j+1] = vector->data[j];
            j--;
        }
        vector->data[j+1] = element;
    }
}

void bucketSort(int arr[], int size) {
    intVector bucket[size];
    for (int i = 0; i < size; i++) {
        initialise(&bucket[i]);
    }
    for (int i = 0; i < size; i++) {
        int index = arr[i];
        push(&bucket[index], arr[i]);
    }
    for (int i = 0; i < size; i++) {
        insertionSort(&bucket[i]);
    }
    int index = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < bucket[i].size; j++) {
            arr[index] = bucket[i].data[j];
            index++;
        }
        destroy(&bucket[i]);
    }
}

// int main() {
//     int arr[10] = {3, 4, 9, 1, 7, 0, 5, 2, 6, 8};
//     bucketSort(arr, 10);
//     printArray(arr, 10);
//     return 0;
// }

int main() {
    srand(time(NULL)); // Seed random number generator

    int size = 600001;   // 4 lakh + 1
    int *arr = (int *)malloc(size * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed for size %d\n", size);
        return 1;
    }

    // Fill array with random integers
    for (int j = 0; j < size; j++) {
        arr[j] = rand() % 600000;
    }

    clock_t start = clock();
    bucketSort(arr, size);
    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("BucketSort: Sorted %d elements in %.4f seconds\n", size, time_taken);

    free(arr);
    return 0;
}
