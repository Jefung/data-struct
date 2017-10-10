#include <iostream>
#include "List.h"
using namespace std;

template <typename E> class LList:public List<E>{
		public:
void test(){
	cin << this->data << endl;
}
};
