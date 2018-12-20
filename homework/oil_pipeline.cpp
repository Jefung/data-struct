#include <iostream>
#include <string>
using namespace std;

// 根据下标交换元素
void Swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void QuickSort(int arr[],int start, int end) {
    int left = start;
    int right = end;
    while (left != right) {
        while (right > left && arr[right] >= arr[start])
            right--;
        while (left < right && arr[left] <= arr[start])
            left++;
		if(left!=right)
			Swap(arr,left,right);
    }
	if(start != left)
		Swap(arr,start,left);
	if(start < left)
		QuickSort(arr,start,left-1);
	if(right < end)
		QuickSort(arr,right+1,end);
}

int main(int argc, char *argv[]) {
	int len;
	int temp;
	cin >> len;
	int arr[len];
	for (int i = 0; i < len; ++i) {
		cin >> temp >> arr[i];
	}
	QuickSort(arr,0,len-1);
	for (int i = 0; i < len; ++i) {
		std::cout << arr[i] << std::endl;	
	}
	int midiant = arr[len/2];
	int sum = 0;
	for (int i = 0; i < len; ++i) {
		if(arr[i] > midiant)
			sum += arr[i] - midiant;
		else sum += midiant - arr[i];
	}
	std::cout << sum << std::endl;
}
