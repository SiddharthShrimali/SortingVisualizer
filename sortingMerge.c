// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// void merge(int arr2[], int start, int mid, int end) {
//     int temp[end - start + 1];
//     int i = start;
//     int j = mid + 1;
//     int k = 0;

//     while (i <= mid && j <= end) {
//         if (arr2[i] <= arr2[j]) {
//             temp[k++] = arr2[i++];
//         } else {
//             temp[k++] = arr2[j++];
//         }
//     }

//     while (i <= mid) {
//         temp[k++] = arr2[i++];
//     }

//     while (j <= end) {
//         temp[k++] = arr2[j++];
//     }

//     for (int l = 0; l < k; l++) {
//         arr2[start + l] = temp[l];
//     }
// }

// void mergeSort(int arr1[], int start, int end, int size) {
//     if (start < end) {
//         int mid = start + (end - start) / 2;
//         mergeSort(arr1, start, mid, size);
//         mergeSort(arr1, mid + 1, end, size);
//         merge(arr1, start, mid, end);
//     }
// }

// void print(int arr[], int size) {
//     printf("Sorted Array: [");
//     for (int i = 0; i < size; i++) {
//         printf("%d", arr[i]);
//         if (i < size - 1) printf(", ");
//     }
//     printf("]\n");
// }

// int main() {
//     int sizes[] = {50, 500, 5000, 50000, 500000 /*, 5000000*/};  // comment 50L
//     int n = sizeof(sizes) / sizeof(sizes[0]);

//     for (int i = 0; i < n; i++) {
//         int size = sizes[i];
//         int *arr = (int *)malloc(size * sizeof(int));
//         if (!arr) {
//             printf("Memory allocation failed for size %d\n", size);
//             continue;
//         }

//         for (int j = 0; j < size; j++) {
//             arr[j] = rand() % 1000000;
//         }

//         clock_t start = clock();
//         mergeSort(arr, 0, size - 1);
//         clock_t end = clock();

//         double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
//         printf("Sorted %d elements in %.4f seconds\n", size, time_taken);

//         free(arr);
//     }

//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr2[], int start, int mid, int end) {
    int size = end - start + 1;
    int *temp = (int *)malloc(size * sizeof(int));
    if (!temp) {
        printf("Memory allocation failed in merge\n");
        exit(1);
    }

    int i = start;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= end) {
        if (arr2[i] <= arr2[j]) {
            temp[k++] = arr2[i++];
        } else {
            temp[k++] = arr2[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr2[i++];
    }

    while (j <= end) {
        temp[k++] = arr2[j++];
    }

    for (int l = 0; l < k; l++) {
        arr2[start + l] = temp[l];
    }

    free(temp);
}


void mergeSort(int arr1[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        mergeSort(arr1, start, mid);
        mergeSort(arr1, mid + 1, end);
        merge(arr1, start, mid, end);
    }
}


int main() {
    int sizes[] = {50, 500, 5000, 50000, 500000, 5000000};  50L
    int n = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < n; i++) {
        int size = sizes[i];
        int *arr = (int *)malloc(size * sizeof(int));
        if (!arr) {
            printf("Memory allocation failed for size %d\n", size);
            continue;
        }


        for (int j = 0; j < size; j++) {
            arr[j] = rand() % 1000000;
        }

        clock_t start = clock();
        mergeSort(arr, 0, size - 1);
        clock_t end = clock();

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Sorted %d elements in %.4f seconds\n", size, time_taken);

        free(arr);
    }

    return 0;
}
