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
int *p = new int;
void test(int i) {
    p = &i;
}
int main() {
    int i = 2;
    cout << p << endl;
    test(i);
    i = 3;
    // cout << p << endl;
    cout << *p << endl;

}
