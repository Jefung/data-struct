#include <iostream>
using namespace std;
template<Class T>
class SeqQueue {
private:
    int front;
    int rear;
    int MaxSize;
    T *queue;
public:
    bool isEmpty() {
        return rear == front ? 1 : 0;
    }
    bool isFull() {
        return (rear + 1) % MaxSize == front ? 1 : 0;
    }
    void enqueue(const T item) {
        if(isFull())
            throw OutOfBounds();
        T

    }
}
