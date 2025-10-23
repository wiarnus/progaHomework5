#include "../include/advanced_array_function.h"
#include <stdlib.h>

int max_subarray_sum(int* nums, int size) {
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
    
    int dp[numsSize];
    int max_len = 1;
    
    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] > max_len) {
            max_len = dp[i];
        }
    }
    
    return max_len;
}

int* merge(int* intervals, int intervalsSize, int* returnSize) {
    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    int pairCount = intervalsSize / 2;
    
    for (int i = 0; i < pairCount - 1; i++) {
        for (int j = 0; j < pairCount - i - 1; j++) {
            if (intervals[j * 2] > intervals[(j + 1) * 2]) {
                int temp_start = intervals[j * 2];
                int temp_end = intervals[j * 2 + 1];
                intervals[j * 2] = intervals[(j + 1) * 2];
                intervals[j * 2 + 1] = intervals[(j + 1) * 2 + 1];
                intervals[(j + 1) * 2] = temp_start;
                intervals[(j + 1) * 2 + 1] = temp_end;
            }
        }
    }
    
    int* result = (int*)malloc(intervalsSize * sizeof(int));
    int count = 0;
    int start = intervals[0];
    int end = intervals[1];
    
    for (int i = 1; i < pairCount; i++) {
        int current_start = intervals[i * 2];
        int current_end = intervals[i * 2 + 1];
        
        if (current_start <= end) {
            if (current_end > end) {
                end = current_end;
            }
        } else {
            result[count * 2] = start;
            result[count * 2 + 1] = end;
            count++;
            start = current_start;
            end = current_end;
        }
    }
    
    result[count * 2] = start;
    result[count * 2 + 1] = end;
    count++;
    
    *returnSize = count * 2;
    return result;
}
