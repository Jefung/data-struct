/**
moving table problem: 移动桌子问题
-----
参考博客:https://www.jianshu.com/p/50f1d4e0555c
		 https://blog.csdn.net/sdz20172133/article/details/79233193
-----
问题:
这层楼沿着走廊南北向的两边各有200个房间。最近，公司要做一次装修，需要在各个办公室之间搬运办公桌。
由于走廊狭窄，办公桌都很大，走廊里一次只能通过一张办公桌。必须制定计划提高搬运效率。
经理制定如下计划：一张办公桌从一个房间移到另一个房间最多用十分钟。当从房间i移动一张办公桌到房间j，两个办公室之间的走廊都会被占用。所以，每10分钟内，只要不是同一段走廊，都可以在房间之间移动办公

		移动办公桌 						理由
可行的 （房间30到50）和（房间60到90） 	走廊不重叠 
可行的 （房间11到12）和（房间14到13） 	走廊不重叠 
不可行的 （房间20到40）和（房间31到80） 房间31到房间40的走廊重叠 
不可行的 (房间1到4）和（房间3到6） 		房间3前面的走廊重叠 
不可行的 ()房间2到8）和（房间7到10） 	房间7前面的走廊重叠

数据:不手动输入了,麻烦
10 20,30 40,50 60,70 80  -->10
1 3, 2 200 				 --> 20
10 100, 20 80, 30 50     --> 30
------
分析: 这题使用贪心法,但是感觉算法不贪心...
要最短时间内移动完全部桌子,故我每一次尽可能的同时移动多张桌子(一次性越多越好,最好一次性10分钟全部移动完,这够贪心)
这题有点类似活动安排问题,可是只要求最长时间,所以用数组表示房间,移动过程中,有经过的房间计数便加一,最后取数组中最大
的那个数,就是最长时间(注意乘以10),为什么?想想就明白了,有3次经过那个房间,所以最少就要30分钟,不然会在走廊里相遇

注意:
1.可能出发位置比目的地房间大,无论大小，我们都可以看做从小的房间移动到大的房间
2.出发房间为偶数则减一，结束房间为奇数则加一

奇想(copy from internet):
可以把房间转化为线,比如1到3就是(1-1)/2,(3-1)/2即0-1,2到4就是(2-1)/2,(4-1)/2即0-1,以此类推
 * */
#include <iostream>
#include <string>
using namespace std;

int MovingTableMinTime(int room_num, int table_num, int start[], int end[]) {
    int room_arr[room_num / 2];
    int max_time = 0;
    for (int i = 0; i < room_num / 2; i++) {
        room_arr[i] = 0;
    }
    for (int i = 0; i < table_num; i++) {
        int start_point = (start[i] - 1) / 2;
        int end_point = (end[i] - 1) / 2;

        // 如果开始房间号大,则交换
        if (start_point > end_point) {
            int temp = start_point;
            start_point = end_point;
            end_point = temp;
        }
        for (int j = start_point; j <= end_point; j++)
            room_arr[j]++;
        for (int j = 0; j < room_num / 2; j++)
            if (room_arr[j] > max_time)
                max_time = room_arr[j];
    }
    return max_time;
}
int main(int argc, char *argv[]) {
    int room_num = 400;
	int table_num1 = 4;
	int start1[] = {10,30,50,70};
	int end1[] = {20,40,60,80};
	std::cout << 10 * MovingTableMinTime(room_num,table_num1,start1,end1) << std::endl;

	int table_num2 = 2;
	int start2[] = {1,2};
	int end2[] = {3,200};
	std::cout << 10 * MovingTableMinTime(room_num,table_num2,start2,end2) << std::endl;

	int table_num3 = 3;
	int start3[] = {10,20,30};
	int end3[] = {100,80,50};
	std::cout << 10 * MovingTableMinTime(room_num,table_num3,start3,end3) << std::endl;
}
