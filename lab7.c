#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int data;
    int numswaps;
} element;

element* numSwapsBubbleSort(int* arr, int size) {
    element* swaps = (element*)malloc(sizeof(element) * size);
    if (swaps == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        swaps[i].data = arr[i];
        swaps[i].numswaps = 0;
    }
    int temp, count;
    for (int i = 0; i < size - 1; i++) {
        count = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                count++;
            }
        }
        swaps[i].numswaps = count;
    }
    return swaps;
}

void printReport(int report[], int size) {
    for (int i = 0; i < size; i++) {
        if (report[i] > 0) {
            printf("%d: %d\n", i, report[i]);
        }
    }
}

int selectionSort(int arr[], int n, int report[]) {
    int swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
        swaps++;
        report[arr[i]]++;
    }
    return swaps;
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);

    printf("array1 bubble sort:\n");
    element* result1 = numSwapsBubbleSort(array1, size1);
    int totalSwaps1 = 0;
    for (int i = 0; i < size1; i++) {
        printf("%d: %d\n", array1[i], result1[i].numswaps);
        totalSwaps1 += result1[i].numswaps;
    }
    printf("%d\n\n", totalSwaps1);

    printf("array2 bubble sort:\n");
    element* result2 = numSwapsBubbleSort(array2, size2);
    int totalSwaps2 = 0;
    for (int i = 0; i < size2; i++) {
        printf("%d: %d\n", array2[i], result2[i].numswaps);
        totalSwaps2 += result2[i].numswaps;
    }
    printf("%d\n\n", totalSwaps2);

    printf("array1 selection sort:\n");
    int report1[110] = {0};
    int totalSwaps3 = selectionSort(array1, size1, report1);
    printReport(report1, 110);
    printf("%d\n\n", totalSwaps3);

    printf("array2 selection sort:\n");
    int report2[110] = {0};
    int totalSwaps4 = selectionSort(array2, size2, report2);
    printReport(report2, 110);
    printf("%d\n", totalSwaps4);

    free(result1);
    free(result2);

    return 0;
}

