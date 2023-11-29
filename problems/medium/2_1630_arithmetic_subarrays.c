#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool checkRangeValidity(int* arr, int arrSize, int l, int r)
{
  // Find the difference
  int diff = abs(arr[1] - arr[0]);
  // Iterate over range
  for (int i = l + 1; i < r; i++)
  {
    if (abs(arr[i] - arr[i - 1]) == diff) continue;
    else return false;
  }

  return true;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* checkArithmeticSubarrays(int* nums, int numsSize, int* l, int lSize, int* r, int rSize, int* returnSize) 
{
  // Create output array
  bool* output = (bool*)malloc(lSize * sizeof(bool));
  int current = 0;
  // Iterate over l and r arrays to determine which range needs to be checked
  for (int i = 0; i < lSize; i++)
  {
    bool valid = checkRangeValidity(nums, numsSize, l[i], r[i]);
    if (valid) output[current] = true;
    else output[current] = false;
    current++;
  }

  return output;
}

int main() {
    // Test case 1
    int nums1[] = {4, 6, 5, 9, 3, 7};
    int l1[] = {0, 0, 2};
    int r1[] = {2, 3, 5};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    int lSize1 = sizeof(l1) / sizeof(l1[0]);
    int rSize1 = sizeof(r1) / sizeof(r1[0]);

    int returnSize1; // Store the actual return size
    bool* results1 = checkArithmeticSubarrays(nums1, numsSize1, l1, lSize1, r1, rSize1, &returnSize1);

    // Check for memory allocation error
    if (results1 == NULL) {
        fprintf(stderr, "Memory allocation failed for test case 1.\n");
        return 1; // Exit with an error code
    }

    // Print results for test case 1
    printf("Results for Test Case 1:\n");
    for (int i = 0; i < returnSize1; i++) {
        printf("%s ", results1[i] ? "true" : "false");
    }
    printf("\n");

    // Free dynamically allocated memory for test case 1
    free(results1);

    // // Test case 2
    // int nums2[] = {-12, -9, -3, -12, -6, 15, 20, -25, -20, -15, -10};
    // int l2[] = {0, 1, 6, 4, 8, 7};
    // int r2[] = {4, 4, 9, 7, 9, 10};
    // int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    // int lSize2 = sizeof(l2) / sizeof(l2[0]);
    // int rSize2 = sizeof(r2) / sizeof(r2[0]);

    // int returnSize2; // Store the actual return size
    // bool* results2 = checkArithmeticSubarrays(nums2, numsSize2, l2, lSize2, r2, rSize2, &returnSize2);

    // // Check for memory allocation error
    // if (results2 == NULL) {
    //     fprintf(stderr, "Memory allocation failed for test case 2.\n");
    //     return 1; // Exit with an error code
    // }

    // // Print results for test case 2
    // printf("Results for Test Case 2:\n");
    // for (int i = 0; i < returnSize2; i++) {
    //     printf("%s ", results2[i] ? "true" : "false");
    // }
    // printf("\n");

    // // Free dynamically allocated memory for test case 2
    // free(results2);

    return 0;
}