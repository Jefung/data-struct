#ifndef SIMPLESELECT
#define SIMPLESELECT
#include "main.h"

//前置声明swap
void swap(int arr[], int i, int j);

//简单排序,每次将最小值排在前
void SimpleSelectSort(int arr[], int size) {
    int min;// 最大下标
    for (int i = 0; i < size - 1; ++i) {
        min = i;
        for (int j = i + 1;  j < size; j++) {
            min = arr[min] <= arr[j] ? min : j;
        }
        swap(arr, min, i);
    }
}

#endif /* ifndef SYMBOL */
