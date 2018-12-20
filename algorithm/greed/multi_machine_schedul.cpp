/**
 * 多机调度问题
 * 参考博客:https://blog.csdn.net/chaoyuan899/article/details/8652479
-----------
问题:
设有n个独立的作业{1，2，…，n}，由m台相同的机器进行加工处理。作业i所需的处理时间为ti。现约定，每个作业均可在任何一台机器上加工处理，但未完工前不允许中断处理。作业不能拆分成更小的子作业。
现要求给出一种作业调度方案，使所给的n个作业在尽可能短的时间内由m台机器加工处理完成。
Input
输入的第一个为测试样例的个数T（ T <= 100 ），接下来有T个测试样例。每个测试样例的第一行是两个整数n和m（ n < 1000, m < 1000 ），接下来有n行，每行一个整数表示第i个作业所需的处理时间
Output
对应每个测试样例输出一行，格式为"Case #: t"，其中'#'表示第几个测试样例（从1开始计），t表示加工完所有任务所需的最短时间。

Sample Input
1
7 3
2
14
4
16
6
5
3

Sample Output
Case 1: 17
----------------
分析:
* 使用贪心算法,采用最长处理时间优先可以得出较好的近似值(非最优值),反例在下面说明	
将处理时间放进最大堆中,每次从最大堆中取出放到空闲机器内,直至机器全部为空且堆为空
ps: 本例子中只是直接排序最长处理时间,并为用堆处理
---------------
* 复杂度: 
1. 如果不计算最大花费时间,复杂度和最大堆的插入取出复杂度相关
则: 1) 任务数少于机器数: O(1). 2) 任务数大于机器数: O(n logn)
2. 待解: 如果要计算最大花费时间,复杂度????
---------------
问:为什么得到的是非最优解
答: 反例:
	假如有7个任务16,14,12,11,10,9,8要分配到三个队列A,B,C
	按照算法：
	A:16, B:14, C:12, C:11, B:10, A:9, C:8
	最长时间为C=12+11+8=31
	实际上存在更佳分配方法：
	A:11+14
	B:12+13
	C:8+9+10
	最长时间为8+9+10=27
 * */
#include <iostream>
#include <list>
using namespace std;
// 根据下标交换元素
void Swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void Sort(int job_num, int job_cost_time[]) {
    int j;
    for (int len = job_num; len > 0; len--) {
        j = 0;
        for (int i = 0; i < len; i++) {
            j = job_cost_time[i] < job_cost_time[j] ? i : j;
        }
        if (j != len - 1) {
            Swap(job_cost_time, j, len - 1);
        }
    }
}

// 返回最大花费时间
int MultiMachineSchedul(int machine_num, list<int> machine[], int job_num, int job_cost_time[]) {
    Sort(job_num, job_cost_time);
    int machine_all_time[machine_num];
    for (int i = 0; i < machine_num; i++) {
        machine_all_time[i] = 0;
    }
    int min_time_index = 0;
    int max_time_index = 0;
    for (int i = 0; i < job_num; ++i) {
        for (int j = 0; j < machine_num; j++) {
            min_time_index = machine_all_time[min_time_index] <= machine_all_time[j] ? min_time_index : j;
            max_time_index = machine_all_time[max_time_index] >= machine_all_time[j] ? max_time_index : j;
        }
        cout << min_time_index << endl;
        machine[min_time_index].push_back(job_cost_time[i]);
        machine_all_time[min_time_index] += job_cost_time[i];
    }
    int max_cost_time = 0;
    for (int i = 0; i < machine_num; ++i) {
        max_cost_time = max_cost_time > machine_all_time[i] ? max_cost_time : machine_all_time[i];
    }
    return max_cost_time;
}
int main() {
    int machine_num = 3;
    int job_num = 7;
    // int job_cost_time[] = {2, 14, 4, 15, 6, 5, 3}; //expect max cost: 17
    int job_cost_time[] = {16, 14, 12, 11, 10, 9, 8}; //expect max cost: 31
    list<int> machine[3];
    cout << "max cost time: " << MultiMachineSchedul(machine_num, machine, job_num, job_cost_time) << endl;
    list<int>::iterator itor;
    for (int i = 0; i < machine_num; i++) {
        cout << i << ": ";
        itor = machine[i].begin();
        while (itor != machine[i].end())
            cout << *itor++ << " ";
        cout << endl;
    }
}
