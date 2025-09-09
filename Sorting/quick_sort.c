#include <stdio.h>
#include <stdlib.h>

int A[] = {64, 34, 25, 12, 22, 11, 90};

// Quick Sort Implementation in array

int partition(int A[], int lb, int ub){
    int pivot = A[lb]; // Taking first element as pivot
    int start = lb;
    int end = ub;

    while (start < end ){
        while (A[start] <= pivot){
            start++;
        }
        while (A[end] > pivot){
            end--;
        }
        if (start < end){
            // Swap A[start] and A[end]
            int temp = A[start];
            A[start] = A[end];
            A[end] = temp;
        }
    }
    // Swap pivot with A[end]
    int temp = A[lb];
    A[lb] = A[end];
    A[end] = temp;
    return end;
}

void quick_sort(int A[], int lb, int ub){
    if (lb < ub){
        int loc = partition(A, lb, ub); // Partitioning index
        quick_sort(A, lb, loc - 1); // Recursively sort elements before partition
        quick_sort(A, loc + 1, ub); // Recursively sort elements after partition
    }
}

// ========== LEETCODE 912: SORT AN ARRAY ==========

// Partition function for LeetCode (with boundary checks)
int partition_leetcode(int result[], int lb, int ub) {
    int pivot = result[lb];
    int start = lb;
    int end = ub;
    
    while (start < end) {
        // Find element greater than pivot from left
        while (start <= ub && result[start] <= pivot) {
            start++;
        }
        // Find element smaller than or equal to pivot from right
        while (end >= lb && result[end] > pivot) {
            end--;
        }
        // Swap if start < end
        if (start < end) {
            int temp = result[start];
            result[start] = result[end];
            result[end] = temp;
        }
    }
    // Place pivot in correct position
    int temp = result[lb];
    result[lb] = result[end];
    result[end] = temp;
    
    return end;  // Return pivot position
}

// Quick sort function for LeetCode
void quick_sort_leetcode(int result[], int lb, int ub) {
    if (lb < ub) {
        int loc = partition_leetcode(result, lb, ub);
        quick_sort_leetcode(result, lb, loc - 1);     // Sort left side
        quick_sort_leetcode(result, loc + 1, ub);     // Sort right side
    }
}

// LEETCODE 912: Sort an Array
int* sortArray(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    
    // Copy input array to result array
    for (int i = 0; i < numsSize; i++) {
        result[i] = nums[i];
    }
    
    // Sort the result array using quick sort
    quick_sort_leetcode(result, 0, numsSize - 1);
    
    return result;
}

int main(){
    int n = sizeof(A)/sizeof(A[0]);
    printf("===ORIGINAL ARRAY===\n");
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");

    quick_sort(A, 0, n-1);

    printf("===ARRAY QUICK SORT===\n");
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    
    // ========== LEETCODE 912: SORT AN ARRAY ==========
    printf("\n=== LEETCODE 912: SORT AN ARRAY ===\n");
    
    // Test case 1: nums = [5,2,3,1]
    // Expected output: [1,2,3,5]
    int nums1[] = {5, 2, 3, 1};
    int nums1_size = sizeof(nums1)/sizeof(nums1[0]);
    int returnSize1;
    
    printf("Test Case 1:\n");
    printf("Input: [");
    for (int i = 0; i < nums1_size; i++) {
        printf("%d", nums1[i]);
        if (i < nums1_size - 1) printf(",");
    }
    printf("]\n");
    
    int* result1 = sortArray(nums1, nums1_size, &returnSize1);
    printf("Output: [");
    for (int i = 0; i < returnSize1; i++) {
        printf("%d", result1[i]);
        if (i < returnSize1 - 1) printf(",");
    }
    printf("]\n\n");
    
    // Test case 2: nums = [5,1,1,2,0,0]
    // Expected output: [0,0,1,1,2,5]
    int nums2[] = {5, 1, 1, 2, 0, 0};
    int nums2_size = sizeof(nums2)/sizeof(nums2[0]);
    int returnSize2;
    
    printf("Test Case 2:\n");
    printf("Input: [");
    for (int i = 0; i < nums2_size; i++) {
        printf("%d", nums2[i]);
        if (i < nums2_size - 1) printf(",");
    }
    printf("]\n");
    
    int* result2 = sortArray(nums2, nums2_size, &returnSize2);
    printf("Output: [");
    for (int i = 0; i < returnSize2; i++) {
        printf("%d", result2[i]);
        if (i < returnSize2 - 1) printf(",");
    }
    printf("]\n");
    
    // Free allocated memory
    free(result1);
    free(result2);
    
    return 0;
}