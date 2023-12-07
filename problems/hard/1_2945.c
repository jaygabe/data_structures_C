#include <stdio.h>
#include <stdlib.h>

/*
    This solution transform the problem from one of knowing the elements of the array
    to MANAGING SUMS AND LENGTHS OF SEQUENCES
*/

// Function to print the elements of an array
void printArray(int arr[], int size) {
    printf("Array elements are: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to find the lower bound
int lower_bound(long long *arr, int size, long long value) {
    int low = 0, high = size;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < value)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int findMaximumLength(int* A, int ASize) {
    // Create INTEGER array with the size of our input array + 2
    // BEST SUBARRAY STARTING POINTS
    int *pre = (int*)calloc(ASize + 2, sizeof(int));
    // Create INTEGER array with the size of our input array + 1
    // OPTIMAL SEQUENCE LENGTHS
    int *dp = (int*)calloc(ASize + 1, sizeof(int));
    // Create LONG LONG array with the size of out input arrya + 1
    // This array helps determine is a subarray should be replaced with its sum
    // CUMULATIVE SUMS
    long long *acc = (long long*)calloc(ASize + 1, sizeof(long long));
    // Handle memory allocation failure
    if (pre == NULL || dp == NULL || acc == NULL) {
        printf("Memory Allocation Failure.");
    }
    // Iterate over array
    // Accumulate the values of the input array
    for (int i = 1; i <= ASize; i++) {
        acc[i] = acc[i - 1] + A[i - 1];
    }

    for (int i = 0, j = 1; j <= ASize; j++) {
        // Determine i
        i = (i > pre[j]) ? i : pre[j];
        dp[j] = dp[i] + 1;
        // Be sure replacing the subarray does not break non-decreasing order requirement
        int k = lower_bound(acc, ASize + 1, 2 * acc[j] - acc[i]);      
        pre[k] = j;
    }

    int answer = dp[ASize];

    free(pre);
    free(acc);
    free(dp);

    return answer;
}

int main() {
    // // Test case 1
    // int nums1[] = {5, 2, 2};
    // int size1 = sizeof(nums1) / sizeof(nums1[0]);
    // printf("Test Case 1: %d\n", findMaximumLength(nums1, size1));

    // // Test case 2
    // int nums2[] = {1, 2, 3, 4};
    // int size2 = sizeof(nums2) / sizeof(nums2[0]);
    // printf("Test Case 2: %d\n", findMaximumLength(nums2, size2));

    // Test case 3
    int nums3[] = {4, 3, 2, 6};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Test Case 3: %d\n", findMaximumLength(nums3, size3));

    return 0;
}