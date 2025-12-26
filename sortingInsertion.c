#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <time.h>

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int element = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > element) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = element;
    }
    return;
}

void print(int arr[], int size) {
    printf("Sorted Array: ");
    printf("[%d, ", arr[0]);
    for (int i = 1; i < size-1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[size-1]);
    return;
}

// int main() {
//     clock_t start, end;
//     double cpu_time_used;
//     int array[size_];
//     for (int i = 0; i < size_; i++) {
//         array[i] = size_ * (i-10);
//     }
//     start = clock();
//     insertionSort(array, size_);
//     end = clock();
//     cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
//     print(array, size_);
//     printf("%d\n", size_);
//     printf("Execution time: %f seconds\n", cpu_time_used);
//     return 0;
// }

// int main() {
//     clock_t start, end;
//     double cpu_time_used;
    
//     int sizes[] = {5, 50, 500, 5000, 50000, 500000, 5000000};
//     int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

//     srand(time(NULL));

//     for (int k = 0; k < num_sizes; k++) {
//         int size_ = sizes[k];
//         int* array = malloc(sizeof(int) * size_);

//         for (int i = 0; i < size_; i++) {
//             array[i] = rand() % size_ + 1;
//         }

//         start = clock();
//         insertionSort(array, size_);
//         end = clock();

//         cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

//         printf("Size: %d\n", size_);
//         printf("Execution time: %f seconds\n", cpu_time_used);

//         free(array);
//     }

//     return 0;
// }