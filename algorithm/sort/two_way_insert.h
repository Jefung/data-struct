#ifndef TWO_WAY_INSERT
#define TWO_WAY_INSERT

//二分寻找插入位置(在binary_insert.h 已经有定义了，在这里注释掉)
// int BinaryFindPos(int arr[], int item, int start, int end) {
//     // show(arr,10);
//     if(start >= end)
//         return item > arr[start] ? start + 1 : start;
//     int middle = (start + end) / 2;
//     if(item == arr[middle])
//         return middle + 1;
//     if(item < arr[middle])
//         return BinaryFindPos(arr, item, start, middle - 1);
//     return BinaryFindPos(arr, item, middle + 1, end);
// }

//二分插入进阶之二路排序(分路后也可用其他插入法): 时间复杂度 o(n*log(2)n) <--当第一个元素为最小时，变成二分插入
void TwoWayInsert(int arr[], int size) {
	int first, end; //二路的首，尾元素的下标
	int arr2[size];
	// for (int i = 0; i < size; ++i) {
	//     arr2[i] = arr[i];
	// }
	arr2[0] = arr[0];
	first = end = 0;


	for (int i = 1; i < size; ++i) {
		if(arr2[first] > arr[i]) {
			first = (first - 1 + size) % size;
			arr2[first] = arr[i];
			continue;
		}
		if(arr2[end] < arr[i]) {
			end = (end + 1) % size;
			arr2[end] = arr[i];
			continue;
		}
		if(arr[i] >= arr2[0] ) {
			int j;
			j = BinaryFindPos(arr2, arr[i], 0, end);
			end = end + 1;
			for(int x = end; x > j; x--)
				arr2[x] = arr2[x - 1];
			arr2[j] = arr[i];
		}
		if(arr[i] < arr2[0]) {
			int j;
			j = BinaryFindPos(arr2, arr[i], first, size - 1);
			j = j - 1;
			first = (first - 1 + size) % size;
			for(int x = first - 1; x < j; x++)
				arr2[x] = arr2[x + 1];
			arr2[j] =  arr[i];
		}
	}
	int i, j;
	for( i = first, j = 0; i != end; i++, j++) {
		i = i % size;
		// cout << arr2[i] << endl;
		arr[j] = arr2[i];
	}
	arr[j] = arr2[i];

}

#endif
