#ifndef SIMPLESELECT
#define SIMPLESELECT
#include "main.h"

//前置声明swap
void swap(int arr[], int i, int j);

//简单排序,每次将最小值排在前: 时间负责度 o(n)
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

//简单排序改进版，一次同时将最大最小分别排在最前最后: 时间复杂度 o(n/2)
void SimpleTwoSelectSort(int arr[], int size){
	int min;
	int max;
	if(size <= 1)
		return;
	if(size == 2)
		if(arr[0] > arr[1])
			swap(arr,0,1);
	for(int i = 0; i < size - 2; i++,size--){
		min  = i;
		max = size -1;
		for(int j = i + 1; j < size; j++){
			min = arr[min] <= arr[j] ? min : j;
			max = arr[max] >= arr[j] ? max : j;
		}
		swap(arr,min,i);
		swap(arr,max,size-1);
	}
}
#endif /* ifndef SYMBOL */
