#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;
#define maxm 23 //订单最大23
#define maxn 8  //最大的站为8
int cap, n, m;  //cap表示容量，n表示站数，m表示订单数
int ans;        //最后结果
int ocount;
int down[maxn]; //表示在i站下车的人数
struct Order {
    int s, e, p;
} order[maxm];

int max(int a, int b) {
    return a > b ? a : b;
}
bool operator<(const Order &a, const Order &b) {
    if(a.s == b.s)
        return a.e < b.e;
    return a.s < b.s;
}

void dfs(int i, int p, int money) {
    if(i == m) {
        ans = max(ans, money);
        return;
    }
    if(i > 0) //前一个订单下车的减掉
        for(int j = order[i - 1].s + 1; j <= order[i].s; j++)
            p -= down[j];
    if(p + order[i].p <= cap) {         //如果加上第i个订单后没有超过火车的容量就可以接受i个订单
        down[order[i].e] += order[i].p; //down[i]表示i号车站有多少人下车
        dfs(i + 1, p + order[i].p, money + order[i].p * (order[i].e - order[i].s));
        down[order[i].e] -= order[i].p; //恢复现场，以便后面的回溯
    }
    dfs(i + 1, p, money); //没有接受第i个订单
}

int main() {
    int i;
    while(cin >> cap >> n >> m, cap || n || m) {
        for(i = 0; i < m; i++) {
            scanf("%d%d%d", &order[i].s, &order[i].e, &order[i].p);
        }
        sort(order, order + m);
        ans = 0;
        dfs(0, 0, 0);
        printf("%d\n", ans);
    }
    return 0;
}
