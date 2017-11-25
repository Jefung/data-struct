// #include <iostream.c>
#ifndef STACK
#define STACK
// 定义栈的抽象类
#include <iostream>
using namespace std;
template<class T>
class Stack {
public:
	// Stack();
	// virtual ~Stack();
	virtual bool isEmpty() const = 0;
	virtual bool isFull() const = 0;
	virtual T& getTop(void) const = 0;
	virtual bool push(const T &item) = 0; //入栈
	virtual bool pop(T &x) = 0; //出栈，并保存到x中；
	virtual bool pop() = 0;
	virtual void clearStack() = 0;
	virtual void show(ostream &out) const = 0;
};
// void test(){}

#endif
