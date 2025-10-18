#include "../include/array_function.h"

void bubble(int* array, int size){
    for (int i=0; i<size;i++){
        for (int j=0; j<size-1;j++){
            if (array[j]>array[j+1]){
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void join_int_arrays(int* src1, size_t size_src1, int* src2, size_t size_src2, int* dest){
    int size1 = (int)size_src1;
    int size2 = (int)size_src2;
    int count = 0;
    for (int i=0;i<size1;i++){
        dest[count] = src1[i];
        count++;
    }
    for (int i=0;i<size2;i++){
        dest[count] = src2[i];
        count++;
    }
}

void join_and_sort_int_arrays(int* src1, size_t size_src1, int* src2, size_t size_src2, int* dest){
    int size1 = (int)size_src1;
    int size2 = (int)size_src2;
    int count = 0;
    int mega_size = size1+size2;
    int newArray[mega_size];
    
    for (int i=0;i<size1;i++){
        newArray[count] = src1[i];
        count++;
    }
    for (int i=0;i<size2;i++){
        newArray[count] = src2[i];
        count++;
    }
    
    bubble(newArray, mega_size);
    
    for (int i = 0; i < mega_size; i++) {
        dest[i] = newArray[i];
    }
}


void get_min_and_max_from_int_array(int* src, size_t size, int* min, int* max){
    int size1 = (int)size;
    int newArray[size1];
    for (int i=0; i<size1; i++){
        newArray[i]=src[i];
    }
    bubble(newArray, size1);
    *min = newArray[0];
    *max = newArray[size1-1];
}





