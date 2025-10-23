#include "../include/advanced_array_function.h"

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
    int counter = 1;
    int temp = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i-1]) {
            counter += 1;
        } else {
            if (counter>temp){
                temp=counter;
            }
            counter = 1;
        }
    }
    
    printf("%d ", temp); 
    return 0;
}

int* merge(int* intervals, int intervalsSize, int* returnSize) {
    static int result[100];
    if (intervalsSize == 0) {
        *returnSize = 0;
        return result;
    }
    for (int i = 0; i < intervalsSize - 2; i += 2) {
        for (int j = 0; j < intervalsSize - 2 - i; j += 2) {
            if (intervals[j] > intervals[j + 2]) {
                int temp_start = intervals[j];
                int temp_end = intervals[j + 1];
                intervals[j] = intervals[j + 2];
                intervals[j + 1] = intervals[j + 3];
                intervals[j + 2] = temp_start;
                intervals[j + 3] = temp_end;
            }
        }
    }
    
    int count = 0;
    int start = intervals[0];
    int end = intervals[1];
    
    for (int i = 2; i < intervalsSize; i += 2) {
        if (intervals[i] <= end) {
            if (intervals[i + 1] > end) {
                end = intervals[i + 1];
            }
        } else {
            result[count * 2] = start;
            result[count * 2 + 1] = end;
            count++;
            start = intervals[i];
            end = intervals[i + 1];
        }
    }
    
    result[count * 2] = start;
    result[count * 2 + 1] = end;
    count++;
    
    *returnSize = count * 2;
    
    return result; 
}


