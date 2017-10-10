#include <iostream>
using namespace std;
template<class T>
class Queue {
private:
    Queue *front;
    Queue *rear;
    Queue *next;
    T data;
public:
    Queue() {
        next = front = rear = NULL;
    }
    Queue(T item) {
        data = item;
    }

    bool isEmpty() {
        if(rear == front && rear == NULL)
            return 1;
        else return 0;
    }
    void enqueue(const T item) {
        if(rear == front && rear == NULL ) {
            rear = front = new Queue(item);
            return;
        };
        Queue *q = new Queue(item);
        rear->next = q;
        rear = q;
    }

    void dequeue() {
        if(isEmpty())
            throw "queue is empty";
        if(rear == front && rear != NULL) {
            delete rear;
            rear = front = NULL;
            return;
        }
        Queue *temp = front;
        front = front->next;
        delete temp;
        temp = NULL;
    }

    void show() {
        if(isEmpty())
            throw "queue is empty";
        Queue *temp = front;
        for(; temp->next != NULL; temp = temp->next)
            showData(temp->data);
        showData(temp->data);
        cout << endl;
    }

    void showData(T item) {
        cout << item << " ";
    }
};
