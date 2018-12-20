/**
diskfile store: 磁盘文件存储最优问题
参考链接:https://blog.csdn.net/pengluer/article/details/3455626 
------
问题:
设磁盘上有n个文件f1,f2,…,fn,每个文件占用磁盘上的1个磁道。这n个文件的检索概率分别是p1,p2,…,pn,且 =1。
磁头从当前磁道移到被检信息磁道所需的时间可用这2个磁道之间的径向距离来度量。如果文件fi存放在第i道上，
1≦i≦n，则检索这n个文件的期望时间是对于所有的i<j,time+=pi*pj*d(i,j) 。其中d(i,j)是第i道与第j道之间的
径向距离|i-j|。 磁盘文件的最优存储问题要求确定这n个文件在磁盘上的存储位置,使期望检索时间达到最小。

要求：
输入：第1行是正整数n,表示文件个数。第2行有n个正整数ai，表示文件的检索概率。
输出：计算出的最小期望检索时间。
-------

分析:
要求检索时间最短,最好的情况就是最大检索概率的在中间,两边是文件检索概率大小依次减小的顺序
这样,经常用到的就在中间,无论从哪里移动都能保持较小的径向距离.这是贪心,好像没法证明(maybe too 
young too simple!)
 * */
#include <iostream>
#include <string>
using namespace std;
// 根据下标交换元素
void Swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
// 从小到大排序,这里使用选择排序:O(n^2)
void Sort(int arr_len, int arr[]) {
    int j;
    for (int len = arr_len; len > 0; len--) {
        j = 0;
        for (int i = 0; i < len; i++) {
            j = arr[i] > arr[j] ? i : j;
        }
        if (j != len - 1) {
            Swap(arr, j, len - 1);
        }
    }
}
float DiskFileStore(int file_num, int search_probability[]) {
    Sort(file_num, search_probability);
    int store[file_num];
    int offset = 0;
    for (int i = 0; i < file_num; i++) {
        if (i % 2 == 0) {
            *(store + offset) = search_probability[i];
            offset++;
        }
    }
    for (int i = file_num-1; i >= 0; i--) {
        if (i % 2 != 0) {
            *(store + offset) = search_probability[i];
            offset++;
        }
    }
	int sum_probablity = 0;
    for (int i = 0; i < file_num; i++) {
		sum_probablity += store[i];
        std::cout << store[i] << std::endl;
    }
	int min_search_time = 0;
	for (int i = 0; i < file_num; i++) {
		for (int j = i+1; j < file_num; j++) {
			std::cout << i << "--" << j << std::endl;
			min_search_time += store[i]*store[j]*(j-i);	
			cout << min_search_time << endl;
		}
	}
    return float(min_search_time) / (sum_probablity * sum_probablity);
}
int main(int argc, char *argv[]) {
    int file_num = 5;
    int search_probability[] = {9, 55, 11, 22, 33};
    std::cout << DiskFileStore(file_num, search_probability) << std::endl;
}
