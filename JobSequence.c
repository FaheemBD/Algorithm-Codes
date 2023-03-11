#include <stdio.h>

struct Job {
    int id;
    int deadline;
    int profit;
};

void swap(struct Job* a, struct Job* b) {
    struct Job t = *a;
    *a = *b;
    *b = t;
}

void bubbleSort(struct Job arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].profit < arr[j+1].profit) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void printJobSequence(struct Job arr[], int n) {
    bubbleSort(arr, n);

    int result[n];
    int slot[n];

    for (int i = 0; i < n; i++) {
        slot[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = arr[i].deadline - 1; j >= 0; j--) {
            if (j < n && slot[j] == 0) {
                result[j] = i;
                slot[j] = 1;
                break;
            }
        }
    }

    printf("Job sequence: ");
    for (int i = 0; i < n; i++) {
        if (slot[i]) {
            printf("%d ", arr[result[i]].id);
        }
    }
}

int main() {
    struct Job arr[] = { {1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15} };
    int n = sizeof(arr) / sizeof(arr[0]);

    printJobSequence(arr, n);

    return 0;
}
