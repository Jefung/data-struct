#include <iostream>
using namespace std;
class CircleList {
protected:
    int data;
    int size;
    CircleList* next;

public:
    CircleList* tail;
    CircleList(CircleList* head = NULL, int item = 0) {
        data = item;
        tail = NULL;
        if (head == NULL) {
            next = this;
        } else
            next = head;
    }

    void append(int item) {
        size += 1;
        if (tail == NULL) {
            next = new CircleList(this, item);
            tail = next;
            return;
        } else {
            tail->next = new CircleList(this, item);
            tail = tail->next;
            return;
        }
    }

    void show() {
        if (tail == NULL) {
            cout << "该链表没有数据" << endl;
            return;
        }
        CircleList* head = tail->next->next;
        for (; head->next != tail->next; head = head->next)
            cout << head->data << " ";
        cout << head->data;
        cout << endl;
        cout << "输出完毕" << endl;
        return;
    }

    void del(int pos) {
        if( pos <= 0 || pos > size ) {
            cout << "输入位置不正确" << endl;
            return;
        }
        CircleList *temp = tail->next->next;
        if( pos == size) {
            for(; temp->next != tail; temp = temp->next);

            temp->next = tail->next;
            delete tail;
            tail = temp;
            size -= 1;
            return;
        }
        for(int i = 1; i < pos   ; i++, temp = temp->next);
        CircleList *p = temp->next;
        temp->next = temp->next->next;
        delete p;
        size -= 1;

    }
};
