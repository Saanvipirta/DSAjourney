//Given an array arr[] of non-negative integers, where each element arr[i] represents the height of the vertical lines, find the maximum amount of water that can be contained between any two lines, together with the x-axis.
#include <stdio.h>

int maxWater(int arr[], int n) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          
            // calculate the amount of water
            int amount = 
                (arr[i] < arr[j] ? arr[i] : arr[j]) * (j - i);
          
            // Keep track of maximum amount of water
            res = (amount > res ? amount : res);
        }
    }
    return res;
}

int main() {
    int arr[] = {2, 1, 8, 6, 4, 6, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d", maxWater(arr, n));
    return 0;
}
