/*
* auth        : Jefung
* version     : v1.0
* description :
*		sort algorithm implement
* analyse     :
*
*/

#include <iostream>
#include "main.h"
using namespace std;
//交换元素位置
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
// 显示数组
void show(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

}

int main() {
    int arr[] = {37, 23, 200, 17, 12, 27, 31,
                 46, 100, 0, 54
                };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "default: " << endl;
    show(arr, n);
	cout << "-----------------------" << endl;
	// InsertSort(arr, n);
    // show(arr, n);
	// BinaryInsert(arr, n);
	// TwoWayInsert(arr,n);
	ShellSortV2(arr, n);
	// SimpleSelectSort(arr,n);
	show(arr, n);


}
