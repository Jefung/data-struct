#ifndef INSERT_SORT
#define INSERT_SORT

//插入排序之直接插入: 时间复杂度 o(n^2) <-- n(n-1)/2
void InsertSort(int arr[], int size) {
    //将原有数组从第二个开始插入
    for (int i = 1; i < size; ++i) {
        //如果前面的元素大于后面的，则互换位置
        if(arr[i] < arr[i - 1]) {
            int y = arr[i];
            int x = i - 1;
            arr[i] = arr[i - 1];
            //将前面的位置与插入元素比较，前面元素大则向后偏移一个单位
            while(y < arr[x - 1] && x >= 1) {
                arr[x] = arr[x - 1];
                x--;
            }
            arr[x] = y;
        }
    }
}


#endif
