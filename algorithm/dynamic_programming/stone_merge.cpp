// Description
// 在一个圆形操场的四周摆放N堆石子(N≤100)，现要将石子有次序地合并成一堆。规定每次只能选相邻的两堆合并成新的一堆，并将新的一堆的石子数，记为该次合并的得分。编一程序，读入堆数N及每堆石子数(≤100)选择一种合并石子的方案，分别得到合并这N堆石子为一堆，可以得到的最大得分和最小得分
// Input
// 输入包含多个例子。第一行为N，即石子堆的数目，以下一行为N个整形，分别代表每堆石子的数目。当N=0时，输入结束。
// Output
// 对每个例子，输出其最小得分和最大得分，这两个数值以空格间隔开，每个例子占一行。
// Sample Input
// 6
// 30 35 15 5 10 20 
// 3
// 1 2 3333 
// 6
// 3 4 5 6 7 8 0
// Sample Output
// 275 475
// 3339 6671
// 84 125
// Hint
// 动态规划 石子堆是环状的
// 参考链接: https://blog.csdn.net/qq_36183935/article/details/70808356
#include <iostream>
using namespace std;

int sum(int stone_pos, int len, int w[], int stone_num) {
    int sum_w = 0;
    for(int i = stone_pos; i <= stone_pos + len; i++) {
        sum_w += w[i % stone_num];
    }
    return sum_w;
}

// 结果通过引用返回给调用函数
void get_cost(int w[], int stone_num, int &max_cost, int &min_cost) {

    int **min_dp = new int *[stone_num];
    int **max_dp = new int *[stone_num];

    for(int i = 0; i < stone_num; i++) {
        min_dp[i] = new int[stone_num];
        max_dp[i] = new int[stone_num];
    }

	// 初始化
	// i表示石头的位置,j表示长度.如dp[1][1]表示合并位置为1和位置为1+1=2的石头
	// dp[1][0]表示不合并
    for(int i = 0; i < stone_num; i++) {
        min_dp[i][0] = 0;
        min_dp[i][1] = sum(i, 1, w, stone_num);

        max_dp[i][0] = 0;
        max_dp[i][1] = sum(i, 1, w, stone_num);
    }

	// 核心,从第二列开始,由上往下,一列一列开始循环,直至把表循环完
    for(int i = 2; i < stone_num; i++) {
        for(int j = 0; j < stone_num; j++) {
            min_dp[j][i] = 0;
            max_dp[j][i] = 0;
            for(int k = 0; k < i; k++) {
				// 初始化第一个数
                if(min_dp[j][i] == 0)
                    min_dp[j][i] = min_dp[j][k] + min_dp[(j + k + 1) % stone_num][i - k - 1] + sum(j, i, w, stone_num);
                else
					// 取得每次迭代中最小的一个
                    min_dp[j][i] = min(min_dp[j][i], min_dp[j][k] + min_dp[(j + k + 1) % stone_num][i - k - 1] + sum(j, i, w, stone_num));

                if(max_dp[j][i] == 0)
                    max_dp[j][i] = max_dp[j][k] + max_dp[(j + k + 1) % stone_num][i - k - 1] + sum(j, i, w, stone_num);
                else
                    max_dp[j][i] = max(max_dp[j][i], max_dp[j][k] + max_dp[(j + k + 1) % stone_num][i - k - 1] + sum(j, i, w, stone_num));
            }
        }
    }
    max_cost = max_dp[0][stone_num - 1];
    min_cost = min_dp[0][stone_num - 1];

	// 取最后一列中最小/最大的数字
    for(int i = 1; i < stone_num; i++) {
        max_cost = max(max_cost, max_dp[i][stone_num - 1]);
        min_cost = min(min_cost, min_dp[i][stone_num - 1]);
    }
}

int main(int argc, char *argv[]) {
    int stone_num;
    while(1) {
        cin >> stone_num;
        if(stone_num == 0)
            break;

        int *w = new int[stone_num];
        for(int i = 0; i < stone_num; i++) {
            cin >> w[i];
        }
        int max_cost, min_cost;
        get_cost(w, stone_num, max_cost, min_cost);

        std::cout << "max cost: " << max_cost << std::endl;
        std::cout << "min cost: " << min_cost << std::endl;
    }
}
