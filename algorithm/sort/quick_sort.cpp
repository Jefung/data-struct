// comment: 快速排序
// 思路参考链接: https://blog.csdn.net/MoreWindows/article/details/6684558
#include <iostream>
#include <vector>

using namespace std;

void quick_sort(std::vector<int> &arr, int l, int r){
    if(l >= r)
        return;
    int i = l, j = r;
    int mid = arr[l];
    while(i < j){
        while(j > i && arr[j] > mid)
            j--;
        if(i < j){
            arr[i] = arr[j];
            i++;
        }

        while(i < j && arr[i] < mid)
            i++;
        if(i < j){
            arr[j] = arr[i];
            j--;
        }
    }
    arr[i] = mid;
    quick_sort(arr, l, i - 1);
    quick_sort(arr, i + 1, r);
   
}

int main(){
    std::cout << "快排: " << std::endl;
    std::vector<int> arr({1, 2, 3, 5, 4, 6, 7, 8, 0, -1, 100});
    quick_sort(arr, 0, arr.size() - 1);
    for(auto it : arr){
        cout << it << endl;
    }
}