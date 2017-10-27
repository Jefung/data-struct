#include <iostream>
#include <iomanip>
using namespace std;
//十字链表节点
template <class T>
class CrossNode {
public:
    int row, col;
    union {
        T val;
        CrossNode *next;
    };

    CrossNode *rHead, *cHead;
    void operator==(CrossNode node) {
        return (node.row == row && node.col == col && node.val == val);
    };
    CrossNode& operator=(CrossNode &node) {
        this->row = node.row;
        this->col = node.col;
        this->val = node.val;
        return node;
    }

};
template <class T>
class CrossLink {
private:

    CrossNode<T> *head;
    // int rows, cols;
    T theZero;
    void releaseAll();
    CrossNode<T> *insert(CrossNode<T> *p) {};
public:
    CrossLink() {}
    void init(int r, int c) {
        if(r <= 0 || c <= 0)
            throw "the row or column can't less than 0";
        int maxSize = r >= c ? r + 1 : c + 1;
        head = new CrossNode<T>[maxSize];

        // heads[0] = new CrossNode<T> {
        //     var = theZero;
        //     next = NULL;
        // };
        head[0].row = r;
        head[0].col = c;
        head[0].next = &head[0];
        head[0].rHead = &head[0];
        head[0].cHead = &head[0];
        for(int i = 0; i <= maxSize ; i++) {
            head[i].row = 0;
            head[i].col = 0;
            head[i].rHead = &head[i];
            head[i].cHead = &head[i];
        }
    }

    void show() {
        for(int i = 1; i <= head[0].row; i++) {
            if(head[i].rHead == &head[i]) {
                for(int j = 1; j <= head[0].row; j++)
                    cout << setw(6) << theZero ;
                cout << endl;

            } else {
                CrossNode<T> *temp;
                temp = head[i].rHead;
                for(int j = 1; j <= head[0].col; j++) {
                    if(temp->col == j && temp != &head[i]) {
                        cout << setw(6) << temp->val;
                        temp =  temp->rHead;
                    } else {
                        cout << setw(6) << theZero;
                    }

                }
                cout << endl;
            }
        }

    }

};
