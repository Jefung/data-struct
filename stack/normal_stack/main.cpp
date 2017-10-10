#include "main.h"
int main() {
    Stack<int> *stack  = new SeqStack<int>(10);
    stack->push(1);
    stack->push(2);
    stack->push(3);
    int x;
    stack->pop(x);
    stack->show(cout);
    cout << x << endl;
}
