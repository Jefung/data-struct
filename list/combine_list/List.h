#include <iostream>
using namespace std;
template <typename E> class List{
	public:
		E data;
		List* next;

	public:
		List(){}
		virtual void test() = 0;
};
