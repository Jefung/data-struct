/**
 * kruskal: 克鲁斯卡算法,应用与最小生成树()
 * 参考链接: https://blog.csdn.net/zenail501129/article/details/23551909 (数据来源)
 * */

#include <iostream>
#include <vector>
using namespace std;

class Node;
void InitUnionFind(int node_num, Node *node_arr[]);
int Find(int node_name, Node *node_arr[]);
void Union(int p, int q, int node_num, Node *node_arr[]);
bool Connected(int p, int q, Node *node_arr[]);
int count(int node_num, Node *node_arr[]);

// 根据下标交换元素
void Swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// 由weight升序对start,end,weight排序
void Sort(int node_num, int start[], int end[], int weight[]) {
    int j;
    for (int len = node_num; len > 0; len--) {
        j = 0;
        for (int i = 0; i < len; i++) {
            j = weight[i] > weight[j] ? i : j;
        }
        if (j != len - 1) {
            Swap(start, j, len - 1);
            Swap(end, j, len - 1);
            Swap(weight, j, len - 1);
        }
    }
}

int Kruskal(int node_num, int start[], int end[], int weight[], vector<pair<int, int>> *sides) {
    // 按照weight从小到大排序
    Sort(node_num, start, end, weight);
    // 生成并查集
    Node *node_arr[node_num];
    InitUnionFind(node_num, node_arr);
	int all_weight = 0;
    for (int i = 0; i < node_num; i++) {
        if (Connected(start[i], end[i], node_arr))
            continue;
        Union(start[i], end[i], node_num, node_arr);
        pair<int, int> p(start[i], end[i]);
		all_weight += weight[i];
        sides->push_back(p);
        if (count(node_num, node_arr) == 1)
            break;
    }
	return all_weight;
}

int main() {
    int node_num = 9;
    // 边的节点由start和end成,weight对应相应的权重
    int start[] = {1, 1, 2, 2, 3, 4, 4, 5, 5};
    int end[] = {2, 6, 3, 7, 4, 5, 7, 6, 7};
    int weight[] = {28, 10, 16, 14, 12, 22, 18, 25, 24};
    vector<pair<int, int>> sides;
    int all_weight = Kruskal(node_num, start, end, weight, &sides);
	cout << "all weight: " << all_weight << endl;
    for (int i = 0; i < sides.size(); i++) {
        cout << sides[i].first << " " << sides[i].second << endl;
    }
    // for (auto side : sides) {
    //     cout << side << endl;
    // }
}
class Node {
  public:
    Node *p_;
    int group_id_;
    int layer_;
    Node(int group_id) {
        group_id_ = group_id;
        p_ = this;
        layer_ = 1;
    }

    //获取root的group id
    int GetGroupId() {
        if (p_ == this)
            return group_id_;
        else
            return p_->GetGroupId();
    }

    Node *GetRoot() {
        if (p_ == this)
            return this;
        else
            return p_->GetRoot();
    }
};
void InitUnionFind(int node_num, Node *node_arr[]) {
    for (int i = 0; i < node_num; i++) {
        Node *node = new Node(i);
        node_arr[i] = node;
    }
}

int Find(int node_name, Node *node_arr[]) {
    return node_arr[node_name]->GetGroupId();
}
// Union复杂度为树的高度 lg(n)
void Union(int p, int q, int node_num, Node *node_arr[]) {
    int p_group = Find(p, node_arr);
    int q_group = Find(q, node_arr);
    if (p_group == q_group)
        return;
    Node *q_root = node_arr[q]->GetRoot();
    Node *p_root = node_arr[p]->GetRoot();
    // 通过判断layer即树的层数(保存在树的根节点)来决定哪个节点作为子树
    // layer小的作为子树,防止树畸形(某个子树过长)
    if (q_root->layer_ > p_root->layer_) {
        p_root->p_ = q_root;
    } else {
        q_root->p_ = p_root;
        if (q_root->layer_ == p_root->layer_)
            p_root->layer_++;
    }
}

bool Connected(int p, int q, Node *node_arr[]) {
    if (Find(p, node_arr) == Find(q, node_arr))
        return true;
    else
        return false;
}
int count(int node_num, Node *node_arr[]) {
    int groups[node_num];
    for (int i = 0; i < node_num; ++i) {
        groups[i] = -1;
    }
    for (int i = 0; i < node_num; ++i) {
        int j = 0;
        for (; groups[j] != -1; j++) {
            if (groups[j] == node_arr[i]->GetGroupId())
                break;
        }
        if (groups[j] == -1)
            groups[j] = node_arr[i]->GetGroupId();
    }
    int group_num = 0;
    for (; groups[group_num] != -1 && group_num < node_num; ++group_num)
        ;
    return group_num++;
}
