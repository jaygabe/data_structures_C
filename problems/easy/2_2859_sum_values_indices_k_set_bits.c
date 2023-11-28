#include <stdio.h>

int countSetBits(int num)
{
    // Initialize the number of set bits to 0
    int count = 0;
    // Iterate over the binary representation of the num
    // number passed into the function
    while (num) {
        // If the least significant bit is a 1
        // Add 1 to our count
        count += num & 1;
        // Shift binary representation to the right by 1
        num = num >> 1;
    }

    return count;
}

int sumIndicesWithKSetBits(int* nums, int numsSize, int k)
{
    // Initialize our total
    int total = 0;
    // Iterate through the indices of nums
    for (int i = 0; i < numsSize; i++)
    {
        // CHECK: If the number of set bits equals k
        if (countSetBits(i) == k)
        {
            // Add the value of the current element to the total
            total += nums[i];
        }       
    } 

    return total;  
}

int main() 
{
    // Test Case 1
    int nums1[] = {5, 10, 1, 5, 2};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int k1 = 1;
    printf("Sum for Test Case 1: %d\n", sumIndicesWithKSetBits(nums1, size1, k1));

    // Test Case 2
    int nums2[] = {4, 3, 2, 1};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    int k2 = 2;
    printf("Sum for Test Case 2: %d\n", sumIndicesWithKSetBits(nums2, size2, k2));

    return 0;
}