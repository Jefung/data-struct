/**
完全背包问题,物体可以切割放进去背包,保证背包可以完全装满.
 用贪心法求解如下背包问题的最优解：有7个物品，
 重量分别为（2，3，5，7，1，4，1），
 价值分别为（10，5，15，7，6，18，3），
 背包容量W=15
求:装满背包时最大价值

分析: 贪心,那个价值高优先装那个, 注意背包问题与0-1背包问题的不同，虽然这两个问题极为相似，但背包问题可以用贪心算法求解，而对于0-1背包问题，贪心选择算法不能得到最优解。因为在0-1背包问题的这种情况下，它无法保证最后能将背包装满，部分闲置的背包空间，使每公斤背包的价值降低了。动态规划算法可以有效的解0-1背包问题。
故只需要计算单位价值,并从高到低排序,优先从高的选,直至背包满为止
 * */
#include <iostream>
#include <vector>
using namespace std;

// 根据下标交换元素
template<typename T>
void Swap(T arr[], int i, int j) {
    T temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// 按照单位价值依次降低排序,这里使用选择排序:O(n^2)
void Sort(int backpage_num, int weight[], int value[], float unit_value[]) {
    int j;
    for (int len = backpage_num; len > 0; len--) {
        j = 0;
        for (int i = 0; i < len; i++) {
            j = unit_value[i] < unit_value[j] ? i : j;
        }
        if (j != len - 1) {
            Swap(weight, j, len - 1);
            Swap(value, j, len - 1);
            Swap(unit_value, j, len - 1);
        }
    }
}

int main(){
	int backpage_num = 7;
	int backage_max_weight = 15;
	int weight[] = {1,2,4,5,1,3,7};
	int value[]  = {6,10,18,15,3,5,7};

	//计算出单位价值
	float unit_value[backpage_num];
	for(int i = 0; i < backpage_num; i++){
		unit_value[i] = float(value[i])/float(weight[i]);
	}
	Sort(backpage_num,weight,value,unit_value);
	for(int i = 0; i < backpage_num; i++){
		cout << unit_value[i] << " " << value[i] << endl;
	}
	float rest_weight = backage_max_weight;
	// 3个vector用来存储存进背包物品的价值,重量,单价,可用于其他计算
	vector<float> value_order;
	vector<float> weight_order;
	vector<float> unit_value_order;
	int i = 0;
	while(rest_weight > 0){
		if(value[i] < rest_weight){
			value_order.push_back(value[i]);
			weight_order.push_back(weight[i]);
			unit_value_order.push_back(unit_value[i]);
			rest_weight -= value[i];
		}else{
			value_order.push_back(value[i]);
			weight_order.push_back(rest_weight);
			unit_value_order.push_back(unit_value[i]);
			rest_weight = 0;
		}
		i++;
	}

	int count = value_order.size();
	float max_value = 0;
    for (int j = 0; j < count; j++) {
              max_value += unit_value_order.at(j) * weight_order.at(j); 
    }
	cout << max_value << endl;
}
