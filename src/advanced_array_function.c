#include "../include/advanced_array_function.h"
#include <stdlib.h>

int max_subarray_sum(int* nums, int size) {
    if (size == 0) return 0;
    
    int max_sum = nums[0];
    int current_sum = nums[0];
    
    for (int i = 1; i < size; i++) {
        if (current_sum < 0) {
            current_sum = nums[i];
        } else {
            current_sum += nums[i];
        }
        
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }
    
    return max_sum;
}

int length_of_lis(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    
    int max_length = 1;
    int current_length = 1;
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i - 1]) {
            current_length++;
            if (current_length > max_length) {
                max_length = current_length;
            }
        } else {
            current_length = 1;
        }
    }
    
    return max_length;
}

int compare_intervals(const void* a, const void* b) {
    return ((int*)a)[0] - ((int*)b)[0];
}

int* merge(int* intervals, int intervalsSize, int* returnSize) {
    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    int* result = (int*)malloc(intervalsSize * 2 * sizeof(int));
    int result_count = 0;
    
    qsort(intervals, intervalsSize, 2 * sizeof(int), compare_intervals);
    
    result[0] = intervals[0];
    result[1] = intervals[1];
    result_count = 1;
    
    for (int i = 1; i < intervalsSize; i++) {
        int last_end = result[result_count * 2 - 1];
        int current_start = intervals[i * 2];
        int current_end = intervals[i * 2 + 1];
        
        if (current_start <= last_end) {
            if (current_end > last_end) {
                result[result_count * 2 - 1] = current_end;
            }
        } else {
            result_count++;
            result[result_count * 2 - 2] = current_start;
            result[result_count * 2 - 1] = current_end;
        }
    }
    
    *returnSize = result_count;  
    return result;
}