/**
参考博客: https://blog.csdn.net/cyp331203/article/details/43199963 
假设我们存在这样一个活动集合S=a1,a2,a3,a4,...,an,其中每一个活动ai都有一个开始时间si和结束时间fi保证(0<=si<fi),活动ai进行时，那么它占用的时间为[si,fi).现在这些活动占用一个共同的资源，就是这些活动会在某一时间段里面进行安排，如果两个活动ai和aj的占用时间[si,fi),[sj,fj)不重叠，那么就说明这两个活动是兼容的，也就是说当si<=fj或者sj<=fi,那么活动ai,aj是兼容的。(copy from internal) 
现在要求尽可能安排多的活动,就是在某个时间段里面,兼容活动越多越好
已知: 
	index[] = {1,2,3,4,5,6,......}   //为a的下标
	start[] = {2,4,5,7,8,........}	 //开始时间
	end[]   = {6,8,7,10,20.......}	 //结束时间
求能够举办最多活动的活动下标

分析:
* 使用贪心法:这种当然是越贪心越好了,哈哈哈
问:怎么使用贪心法呢?
答:从开始就选最早结束的活动,给其他活动腾出更多时间.这样其他活动的选择余地就更多了
证明: 
	假设最大兼容子集R中有最早结束的活动是an,当前给出的活动集合最早结束的是a1,
	此时要证明an是在所有活动集合中最早结束的
   	1) an == a1, 证明成立
	2) an != a1, 那么end[n] > end[1](即n结束时间比活动1结束时间晚,活动1是最早的),
   故在最大兼容子集中,除了活动n的其他活动的开始时间都比活动1结束晚(因为他们都比活动n结束晚),	
   则a1可以替换an,组成新的最大兼容子集R'.使得证明可以成立.ps:重点是明白即时最早结束的活动
   不在最大兼容子集中,也可以替换进去.
 **/
#include <iostream>
#include <vector>
using namespace std;
// 根据下标交换元素
void Swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
// 按照结束时间(end)排序,这里使用选择排序:O(n^2)
void Sort(int activity_len, int index[], int start[], int end[]) {
    int j;
    for (int len = activity_len; len > 0; len--) {
        j = 0;
        for (int i = 0; i < len; i++) {
            j = end[i] > end[j] ? i : j;
        }
        if (j != len - 1) {
            Swap(index, j, len - 1);
            Swap(start, j, len - 1);
            Swap(end, j, len - 1);
        }
    }
}

// 递归版本
void RecrusiveActivitySelector(int activity_len, int activity_num, int start[], int end[], vector<int> *selected_activity) {
    selected_activity->push_back(activity_num);
    int i;
    for (i = activity_num + 1; i < activity_len && start[i] < end[activity_num]; i++)
        ;
    if (i >= activity_len)
        return;
    activity_num = i;
    RecrusiveActivitySelector(activity_len, activity_num, start, end, selected_activity);
}

// 迭代版本
void IterateActivitySelector(int activity_len, int activity_num, int start[], int end[], vector<int> *selected_activity) {

    for (int cur_num = activity_num; cur_num < activity_len;) {
        selected_activity->push_back(cur_num);
        int i;
        for (i = cur_num + 1; i < activity_len && start[i] < end[cur_num]; i++)
            ;
        if (i >= activity_len)
            return;
        cur_num = i;
    }
}

int main() {
    int activity_len = 11;
    int index[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int start[] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 5};
    int end[] = {5, 4, 6, 16, 9, 9, 10, 11, 12, 14, 7};
    Sort(activity_len, index, start, end);
    for (int i = 0; i < activity_len; i++) {
        cout << index[i] << " " << start[i] << " " << end[i] << endl;
    }

    vector<int> selected_activity;
    RecrusiveActivitySelector(activity_len, 0, start, end, &selected_activity);
    cout << "Recursice Version: " << endl;
    int count = selected_activity.size();
    for (int i = 0; i < count; i++) {
        cout << index[selected_activity.at(i)] << ":" << start[selected_activity.at(i)]
             << "->" << end[selected_activity.at(i)] << endl;
    }
    selected_activity.clear();


    IterateActivitySelector(activity_len, 0, start, end, &selected_activity);
    cout << "Iterate Version: " << endl;
    count = selected_activity.size();
    for (int i = 0; i < count; i++) {
        cout << index[selected_activity.at(i)] << ":" << start[selected_activity.at(i)]
             << "->" << end[selected_activity.at(i)] << endl;
    }
}
