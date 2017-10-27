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

struct car {
    int number;
    car *next;
};
//停车场栈
class ParkStack {
public:
    int size;
    int top;
    car  *element;
    //索引从0开始
    ParkStack(int s) {
        size = s ;
        element = new car[size];
        top = -1;
    }
    ~ParkStack() {
        delete []element;
    }

    bool push(car item) {
        if(top >= (size - 1))
            return false;
        top++;
        element[top] = item;
        return true;
    }

    bool pop(car &item) {
        if(top == -1)
            return false;
        item = element[top];
        top--;
        return true;
    }
    // 内含另外栈来暂时移走汽车
    bool delByIndex(int index) {
        ParkStack S(size);
        if(index < 0 || index > top)
            return false;
        car temp;
        if(index == top)
            this->pop(temp);
        else {
            int p = top;
            cout << p << index << endl;
            for(; index < p; index++) {
                this->pop(temp);
                S.push(temp);
            }
            this->pop(temp);
        }
        while(S.pop(temp)) {
            this->push(temp);
        }
        return false;
    }
    void show() {
        for(int i = 0; i <= top; i++) {
            cout << " | " << element[i].number << " | " << endl;
        }
    }

    bool isFull() {
        if(top >= (size - 1))
            return true;
        else return false;
    }
};

class Queue {
public:
    int size;
    car *head;
    car *tail;
    Queue() {
        size = 0;
        head = NULL;
        tail = NULL;
    }

    void enqueue(car *item) {
        item->next = NULL;
        if(head == NULL && tail == NULL) {
            head = tail = item;
            return;
        }
        tail->next = item;
        tail = tail->next;
        // cout << tail->number << endl;
    }
    bool dequeue(car &item) {

        if(head == tail && head == NULL) {
            return false;
        }
        if(head ==  tail ) {
            item = *head;
            head = tail = NULL;
            return true;
        } else {
            car *temp;
            temp = head;
            item = *(head);
            head = head->next;
            return true;
        }

    }
    bool isEmpty() {
        if(head == tail && head == NULL)
            return true;
        else return false;
    }
    void show() {
        if(isEmpty())
            return;
        car *temp;
        for(temp = head; temp != tail; temp = temp->next)
            cout << temp->number << " | ";
        cout << temp->number << endl;
    }
};



int main() {

    // ParkStack Park(50);
    // car t;
    // for(int i = 0; i < 40; i++) {
    //     t.number = i;
    //     Park.push(t);
    // }
    // // Park.delByIndex(2);
    // // Park.delByIndex(21);
    // Park.delByIndex(29);
    // // Park.show();
    // Queue queue;
    // for(int i = 0; i < 2; i++) {
    //     car *q = new car;
    //     q -> number = i;
    //     queue.enqueue(q);
    // }
    // queue.dequeue(t);
    // queue.dequeue(t);
    // queue.dequeue(t);
    // queue.show();
    cout << "请输入停车场的车辆限制" << endl;
    int size, number;
    cin >> size;
    ParkStack Park(size);
    Queue queue;
    cout << "请输入停入停车场的车辆号码，小于0停止输入" << endl;
    cin >> number;
    car c;
    while(number > 0) {
        c.number = number;
        if(!Park.push(c)) {
            car *temp = new car;
            temp->number = number;
            queue.enqueue(temp);
        }
        cin >> number;
    }
    int i, index;
    while(true) {
        cout << "按0可增加来车" << endl;
        cout << "按1可移除在停车的车辆" << endl;
        cout << "按2可显示当前状态" << endl;
        cin >> i;
        switch(i) {
        case 0:
            cout << "请输入车牌号码" << endl;
            cin >> c.number;
            if(Park.isFull()) {
                car * t = new car;
                t->number = c.number;
                queue.enqueue(t);
            } else Park.push(c);
            break;
        case  1 :
            cout << "请输入移除车辆的索引（从0开始）：" << endl;
            cin >> index;
            if(index < 0 || index > Park.size - 1) {
                cout << "请输入正确的索引" << endl;
                continue;
            }
            if(!Park.delByIndex(index)) {
                if(!queue.isEmpty()) {
                    queue.dequeue(c);
                    Park.push(c);
                }
                cout << "移除成功" << endl;
            } else cout << "请输入正确索引" << endl;
            break;
        case  2 :
            cout << "停车场：" << endl;
            Park.show();
            cout << "等待队列" << endl;
            queue.show();
            break;
        default:
            cout << "请输入0或者1或者2" << endl;
            break;
        }
    }
}
