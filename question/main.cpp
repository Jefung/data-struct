/*
* auth        : Jefung
* version     : v1.0
* description :
*
* analyse     :
*
*/

#include<iostream>
#include<string.h>
using namespace std;
int main() {
    char p[] = "123456";
    // char s[10];     //  正常复制: 123456  -- 123456
    char s[2];     //  栈溢出(目标栈空间不够大), output: 56  -- 123456

    char *ptr = p + 3;

    // cout << &p << endl;
    // cout << &(*ptr) << endl;
    strcpy(s, p);
    // cout << p << "  --  " << s << "  ---  " << ptr << endl;
    cout << p << "  --  " << s << endl;
    cout << &p << "|" << &s << endl;
    cout << ptr << endl;
    return 0;
}
