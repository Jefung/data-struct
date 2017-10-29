#ifndef SHELL_SORT
#define SHELL_SORT

//插入排序之希尔排序(直接插入法)
void ShellSortV1(int arr[], int size) {
	//设置增量，每次变为长度的一半
    for(int incre = size / 2; incre >= 1; incre /= 2) {
		//遍历0-incre之间的元素
        for(int i = 0; i < incre; i ++) {
			//循环各组的元素，同时使用直接插入法排序	
            for(int j = i + incre; j < size; j += incre) {
                int temp = arr[j];
                int x = j;
                while(x >= incre && temp < arr[x - incre]) {
                    arr[x] = arr[x - incre ];
                    x = x - incre;
                }
                arr[x] = temp;
            }
        }
    }
}

//插入排序之希尔排序(直接插入法2)
void ShellSortV2(int arr[], int size) {
	//设置增量，每次变为长度的一半
    for(int incre = size / 2; incre >= 1; incre /= 2) {
		//从arr[incre]开始遍历 
        for(int i = incre; i < size; i ++) {
			//比较同组之前的元素，大与前一个则不处理，小于则采用直接插入
            if (arr[i] < arr[i - incre]) { 
                int temp = arr[i];
                int k = i - incre;
                while (k >= 0 && arr[k] > temp) {

                    arr[k + incre] = arr[k];
                    k -= incre;
                }
                arr[k + incre] = temp;
            }
        }
    }
}

#endif
