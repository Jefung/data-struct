#ifndef MAIN
#define MAIN
#include "../../ADT/Stack.h"
// #include <iostream>
// using namespace std;
template<class T>
class SeqStack: public Stack<T> {
private:
    int top;
    int MaxSize;
    T *stack;
public:
    SeqStack(int size) {
        top = -1;
        MaxSize = size;
        stack = new T[MaxSize];

    }
    ~SeqStack() {
        if(stack)
            delete []stack;
    }

    bool isEmpty()const {
        if(top == -1)
            return 1;
        return 0;
    }

    virtual bool isFull()const {
        if(top == MaxSize)
            return 1;
        return 0;
    }

    virtual T& getTop() const {
        if(isEmpty())
            throw "the stack is empty，can‘t get element";
        return stack[top];
    }

    virtual bool push(const T &item) {
        if(isFull())
            throw "the stack is full, can't push";
        stack[++top] =  item;
        return true;
    }

    virtual bool pop(T &x) {
        if(isEmpty())
            throw "the stack is empty, can't pop element";
        x = stack[top--];
        return true;
    }

    virtual bool pop() {
        if(isEmpty())
            throw "the stack is empty, can't pop element";
        top--;
        return true;
    }

    virtual void clearStack() {
        if(isEmpty())
            return;
        delete []stack;
        return;
    }

    virtual void show(ostream &out)const {
        for (int i = 0; i <= top; i++)
            out << stack[i] << " ";
        cout << endl;
    }

    friend ostream& operator<<(ostream& out , const SeqStack<T>& x) {
        x.show(out);
        return out;
    }



};
#endif
