#include <stdio.h>
#include <assert.h>

int unequalTriplets(int* nums, int numsSize) {
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            for (int k = j + 1; k < numsSize; k++) {
                if (nums[i] != nums[j] && nums[i] != nums[k] && nums[j] != nums[k]) {
                    count++;
                }
            }
        }
    }

    return count;
}

void main() {
    // Test Case 1
    int nums1[] = {4, 4, 2, 4, 3};
    int result1 = unequalTriplets(nums1, 5);
    assert(result1 == 3);  // Expected output is 3

    // Test Case 2
    int nums2[] = {1, 1, 1, 1, 1};
    int result2 = unequalTriplets(nums2, 5);
    assert(result2 == 0);  // Expected output is 0

    // Test Case 3
    int nums3[] = {5, 6, 7, 8, 9};
    int result3 = unequalTriplets(nums3, 5);
    assert(result3 == 10);  // Expected output is 10

    // Test Case 4
    int nums4[] = {1, 2, 3, 4};
    int result4 = unequalTriplets(nums4, 4);
    assert(result4 == 4);  // Expected output is 1

    // Test Case 5
    int nums5[] = {10, 20, 30};
    int result5 = unequalTriplets(nums5, 3);
    assert(result5 == 1);  // Expected output is 1

    printf("All test cases passed.\n");
}