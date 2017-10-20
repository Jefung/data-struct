/*
* auth        : Jefung
* version     : v1.0
* description :
*		buid a class like one-dimensional array
* analyse     :
*
*/

#include <iostream>
using namespace std;
template<class T>
class Array {
private:
    T *element;
    int size;
public:
    Array(int s = 0 ) {
        if(s < 0 )
            throw("the size can't below 0");
        size = s;
        element = new T[size];
    }
    Array(const Array<T>&v) {

    }
    ~Array() {
        delete []element;
    }
    int getSize() const {
        return size;
    }
    bool getElement(int index, T &x) const {
        if(index < 0 || index >= size) {
            // throw("the index is error");
            return false;
        }
        x = element[index];
        return true;

    }
    bool setElement(int index, const T &x) {
        if(index < 0 || index >= size) {
            // throw("the index is error");
            return false;
        }
        element[index] = x;
        return true;
    }
    void show()const {
        for(int i = 0; i < size; i++)
            cout << element[i] << " ";
        cout << endl;

    }

    Array<T>& operator=(const Array<T>&v) {
        if(v.getSize() != size)
            throw("can't copy for two different size class instance");
        for(int i = 0; i < size; i++) {
            T x;
            v.getElement(i, x);
            this->setElement(i, x);
        }
        return *this;
    }
};

int main() {
    Array<int> arr =  Array<int>(5);
    arr.setElement(2, 4);
    arr.setElement(3, 5);
    arr.setElement(2, 6);
    int x;
    arr.getElement(3, x);
    cout << x << endl;
    arr.show();
    Array<int> arr2 =  Array<int>(5);
    arr2 = arr;
    arr2.show();
}
