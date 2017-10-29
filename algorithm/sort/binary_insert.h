#ifndef BINARY_INSERT
#define BINARY_INSERT

//二分寻找插入位置
int BinaryFindPos(int arr[], int item, int start, int end) {
    // show(arr,10);
    if(start >= end)
        return item > arr[start] ? start + 1 : start;
    int middle = (start + end) / 2;
    if(item == arr[middle])
        return middle + 1;
    if(item < arr[middle])
        return BinaryFindPos(arr, item, start, middle - 1);
    return BinaryFindPos(arr, item, middle + 1, end);
}

//插入排序之二分插入: 时间复杂度：o( n*log(2)n )
void BinaryInsert(int arr[], int size) {
    int pos;
    for (int i = 1; i < size; i++) {
        int item = arr[i];
        pos = BinaryFindPos(arr, arr[i], 0, i - 1);
        for(int j = i; j > pos; j--)
            arr[j] = arr[j - 1];
        arr[pos] = item;
    }
}

#endif
