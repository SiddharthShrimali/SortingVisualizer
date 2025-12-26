#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
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


// Lomuto partition
int partition(int arr[], int first, int last) {
    int pivot = arr[last];
    int i = first - 1;
    for (int j = first; j < last; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[last]);
    return i + 1;
}

void quickSort(int arr[], int first, int last) {
    if (first < last) {
        int pivot = partition(arr, first, last);
        quickSort(arr, first, pivot - 1);
        quickSort(arr, pivot + 1, last);
    }
}

int main() {
    int arr[10] = {3, 4, 9, 1, 7, 0, 5, 2, 6, 8};
    quickSort(arr, 0, 9);
    print(arr, 10);
    return 0;
}
*/

/*
// Hoare partition
int partition(int arr[], int first, int last) {
    int pivot = arr[first];
    int i = first - 1;
    int j = last + 1;
    while (1) {
        do {
            i++;
        } while (arr[i] < pivot);
        do {
            j--;
        } while (arr[j] > pivot);
        if (i >= j) 
            break;
        swap(&arr[i], &arr[j]);
    }
    return j;
}

void quickSort(int arr[], int first, int last) {
    if (first < last) {
        int pivot = partition(arr, first, last);
        quickSort(arr, first, pivot);
        quickSort(arr, pivot + 1, last);
    }
}

int main() {
    int arr[10] = {3, 4, 9, 1, 7, 0, 5, 2, 6, 8};
    quickSort(arr, 0, 9);
    print(arr, 10);
    return 0;
}
*/

/*
//Random Partitioning through Lomuto
int partition(int arr[], int first, int last) {
    int pivot = first + rand() % (last - first + 1);
    swap(&arr[pivot], &arr[last]);
    pivot = arr[last];
    int i = first - 1;
    for (int j = first; j < last; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[last]);
    return i + 1;
}

void quickSort(int arr[], int first, int last) {
    if (first < last) {
        int pivot = partition(arr, first, last);
        quickSort(arr, first, pivot - 1);
        quickSort(arr, pivot + 1, last);
    }
}

int main() {
    int arr[10] = {3, 4, 9, 1, 7, 0, 5, 2, 6, 8};
    quickSort(arr, 0, 9);
    print(arr, 10);
    return 0;
}
*/

/*
//Random Partitioning through Hoare
int partition(int arr[], int first, int last) {
    int pivot = first + rand() % (last - first + 1);
    swap(&arr[pivot], &arr[first]);
    pivot = arr[first];
    int i = first - 1;
    int j = last + 1;
    while (1) {
        do {
            i++;
        } while (arr[i] < pivot);
        do {
            j--;
        } while (arr[j] > pivot);
        if (i >= j) 
            break;
        swap(&arr[i], &arr[j]);
    }
    return j;
}

void quickSort(int arr[], int first, int last) {
    if (first < last) {
        int pivot = partition(arr, first, last);
        quickSort(arr, first, pivot);
        quickSort(arr, pivot + 1, last);
    }
}

int main() {
    int arr[10] = {3, 4, 9, 1, 7, 0, 5, 2, 6, 8};
    quickSort(arr, 0, 9);
    print(arr, 10);
    return 0;
}
*/


int main() {
    srand(time(NULL)); // Seed random number generator

    int sizes[] = {50, 500, 5000, 50000, 500000, 5000000}; // includes 50 lakh
    int n = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < n; i++) {
        int size = sizes[i];
        int *arr = (int *)malloc(size * sizeof(int));
        if (!arr) {
            printf("Memory allocation failed for size %d\n", size);
            continue;
        }

        // Fill array with random integers
        for (int j = 0; j < size; j++) {
            arr[j] = rand() % 1000000;
        }

        clock_t start = clock();
        quickSort(arr, 0, size - 1);
        clock_t end = clock();

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("QuickSort: Sorted %d elements in %.4f seconds\n", size, time_taken);

        free(arr);
    }

    return 0;
}

