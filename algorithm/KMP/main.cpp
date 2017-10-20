/*
* auth        : Jefung
* version     : v1.0
* description :
*		KMP模式匹配算法（字符串匹配不回溯）
* analyse     :
*
*/

#include <iostream>
#include <cstring>
using namespace std;
void getNext(const char *chars, int next[]) {
    int l = strlen(chars);
    int i = 0;
    int j = -1;
    next[0] = -1;
    while(i < l) {
        if(j == -1 || chars[i] == chars[j]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
    return;

}

int main() {
    const char *str = "testtest1";

    int next[strlen(str)];
    getNext(str, next);
    cout << next[strlen(str)] << "te" << endl;


}
