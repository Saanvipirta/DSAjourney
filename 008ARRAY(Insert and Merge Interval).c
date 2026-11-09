//Given a set of non-overlapping intervals[][] where intervals[i] = [starti , endi] represent the start and the end of the ith event and intervals is sorted in ascending order by starti and a new interval, insert the interval at the correct position such that after insertion, the intervals remain sorted. If the insertion results in overlapping intervals, then merge the overlapping intervals. Assume that the set of non-overlapping intervals is sorted based on start time.

#include <stdio.h>

void insertInterval(int arr[][2], int n, int newInt[2]) {
    int result[100][2];
    int i = 0, k = 0;

    // Step 1: Add intervals before new interval
    while (i < n && arr[i][1] < newInt[0]) {
        result[k][0] = arr[i][0];
        result[k][1] = arr[i][1];
        k++;
        i++;
    }

    // Step 2: Merge overlapping intervals
    while (i < n && arr[i][0] <= newInt[1]) {
        if (arr[i][0] < newInt[0])
            newInt[0] = arr[i][0];

        if (arr[i][1] > newInt[1])
            newInt[1] = arr[i][1];

        i++;
    }

    result[k][0] = newInt[0];
    result[k][1] = newInt[1];
    k++;

    // Step 3: Add remaining intervals
    while (i < n) {
        result[k][0] = arr[i][0];
        result[k][1] = arr[i][1];
        k++;
        i++;
    }

    // Print result
    for (i = 0; i < k; i++) {
        printf("[%d, %d] ", result[i][0], result[i][1]);
    }
}

int main() {
    int arr[][2] = {{1, 3}, {6, 9}};
    int n = 2;
    int newInt[2] = {2, 5};

    insertInterval(arr, n, newInt);

    return 0;
}
