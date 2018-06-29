#include <iostream>
using namespace std;
class Triple {
public:
    Triple *next;
    int length;  //线性表长
    int width;	//线性表宽
    int row;    //元素行号
    int col;    //元素列号
    int val; 	//元素值
    int white;

    // 初始化插入数据
    Triple(int r, int c, int v) {
        row = r;
        col = c;
        val = v;
        length = width = 0;
        white = 0;
        next = NULL;

    }
    // 初始化三元组表头
    Triple(int l, int w) {
        length = l;
        width = w;
        white = 0;
        val = 0;
        row = col = val = 0;
        next = NULL;
    }

    //设置稀疏矩阵的值
    bool set(int r, int c, int v) {
        if( r <= 0 || r > width || c <= 0 || c > length)
            return false;
        Triple *tempHead = this;
        // 如果存在，则替换
        if(this->get(r, c) != 0) {
            for(; tempHead->next != NULL; tempHead = tempHead->next) {
                if(tempHead->row == r && tempHead->col == c) {
                    tempHead->val = v;
                    return true;
                }
            }
            tempHead->val = v;
            return true;
        }
        // 不存在则插入
        Triple *p = new Triple(r, c, v);
        for(; tempHead->next != NULL; tempHead = tempHead->next);
        tempHead->next = p;
        return true;
    }
    //获取对应的值，没有则返回white默认（0）
    int get(int r, int c) {
        Triple *tempHead = this;
        for(; tempHead->next != NULL; tempHead = tempHead->next) {
            if(tempHead->row == r && tempHead->col == c)
                return tempHead->val;
        }
        if(tempHead->row == r && tempHead->col == c)
            return tempHead->val;
        else return white;
    }

    void show() {
        Triple *tempHead = this;
        if(tempHead->next == NULL) {
            cout << "三元组为空" << endl;
            return;
        }
        cout << "行		" << "列	" << "值 	" << endl;
        for(tempHead = tempHead->next; tempHead->next != NULL; tempHead = tempHead->next) {
            cout << tempHead->row << tempHead->col << tempHead->val << endl;
        }
        cout << tempHead->row << tempHead->col << tempHead->val << endl;

    }

    Triple* add(Triple *head) {
        if(head->length != length || head->width != width) {
            cout << "只能进行相同行列的矩阵相加" << endl;
            return NULL;
        }

        Triple *temp = new Triple(length, width);
        Triple *p1 = this->next;
        for(; p1->next != NULL; p1 = p1->next ) {
            temp->set(p1->row, p1->col, p1->val + head->get(p1->row, p1->col));
        }
        head = head->next;
        for(; head->next != NULL; head = head->next) {
            if(temp->get(head->row, head->col) != 0)
                continue;
            else temp->set(head->row, head->col, head->val);
            temp->show();
        }
        if(temp->get(head->row, head->col) == 0)
            temp->set(head->row, head->col, head->val);
        return temp;
    }

};
int main() {
    Triple *head = new Triple(5, 5);
    head->set(3, 3, 3);
    head->set(1, 1, 1);
    head->set(2, 2, 2);
    head->set(3, 3, 999);
    head->show();
    Triple *head2 = new Triple(5, 5);
    head2->set(3, 3, 6);
    head2->set(31, 3, 6);
    head2->set(32, 3, 6);
    head2->set(32, 3, 6);
    head2->set(4, 5, 9999);
    head2->show();
    Triple *res = head->add(head2);

    res->show();
}
