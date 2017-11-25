/*
* auth        : Jefung
* version     : v1.0
* description :
*
* analyse     :
*
*/

#include <iostream>
using namespace std;
struct node {
    double wt; //权值
    node *parent, *lchild, *rchild;
    int min, max; // 存范围
};

class HuffmanTree {
private:
    node *root;
public:
    HuffmanTree() {
        root = NULL;
    }
    //傻瓜做法
    node* createTree(node *&p1, node *&p2) {
        // p1 或 p2 有一个是上次构造的新节点
        if(p1 == root || p2 == root) {
            //如果p2是上次构造的新节点，则交换和p1交换
            if(p2 == root) {
                node *temp = p2;
                p2 = p1;
                p1 = temp;
            }
            root = new node;
            root->rchild = p1;
            root->lchild = p2;
            root->parent = NULL;
            root->wt = p1->wt + p2->wt;
            p1->parent = root;
            p2->parent = root;
            return root;
        } else {
            //为2个节点构建一颗树，和原先的根节点同层次
            if(root == NULL) {
                root = new node;
                root->lchild = p2;
                root->rchild = p1;
                root->wt = p1->wt + p2->wt;
                return root;
            }
            node *p = new node;
            p->rchild = p1;
            p->lchild = p2;
            p->parent = NULL;
            p->wt = p1->wt + p2->wt;
            p1->parent = p;
            p2->parent = p;
            return p;
        }
    }
    //简单做法(与静态链表做法一样)
    node* createTreeV2(node *&p1, node *&p2) {
        root = new node;
        root->lchild = p1;
        root->rchild = p2;
        root->wt = p1->wt + p2->wt;
        root->parent = NULL;
		root->min = 0;
		root->max = 0;
        p1->parent = root;
        p2->parent = root;
        return root;
    }

    void showTree(node *p = NULL) {
        if(root == NULL) {
            cout << "please create HuffmanTree first!" << endl;
            return;
        }
        if(p == NULL) {
            p = root;
        }
        if(p->lchild == NULL && p->rchild == NULL) {
            cout << p->wt << " " << endl;
            return;
        }
        if(p->lchild != NULL) {
            showTree(p->lchild);
        }
        if(p->rchild != NULL) {
            showTree(p->rchild);
        }
        cout << p->wt << " " << endl;
    }
};

void sort(node **&arr, int start, int end) {
    for (int i = start; i <= end; ++i) {
        for (int j = i + 1; j <= end; ++j) {
            if(arr[i]->wt > arr[j]->wt) {
                node *temp;
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}
int main() {
    cout << "please enter the number leaf node that you want: " << endl;
    int leafnum;
    cin >> leafnum;
    while(leafnum <= 0) {
        cout << "please enter the right number: " << endl;
        cin >> leafnum;
    }

    node **arr = new node*[leafnum * 2 - 1];
    cout << "please enter the node weight and the minimum, miximum: (like 0.6  0 60)";
    //构造节点数组
    for (int i = 0; i < leafnum; ++i) {
        arr[i] = new node;
        double temp = 0 ;
        int min = 0;
        int max = 0;
        cin >> temp >> min >> max;
        arr[i]->wt = temp;
        arr[i]->rchild = NULL;
        arr[i]->lchild = NULL;
        arr[i]->parent = NULL;
        arr[i]->min = min;
        arr[i]->max = max;
    }
    sort(arr, 0, leafnum - 1);

    int i;
    int j;
	//构建哈夫曼树
    HuffmanTree huffman = HuffmanTree();
    for ( j = leafnum, i = 0; i < leafnum * 2 - 2; i = i + 2, j++) {
        sort(arr, i, j - 1);
        arr[j] = huffman.createTreeV2(arr[i], arr[i + 1]);
    }
    huffman.showTree();
}
