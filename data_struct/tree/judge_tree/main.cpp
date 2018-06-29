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

char compare(int a, int b) {
    if(a > b)
        return '>';
    if(a < b)
        return '<';
    else
        return '=';
}

void comp(int x, int y, int z) {
    if(x > z)
        cout << x << "较重" << endl;
    else cout << y << "较轻" << endl;
}
int main() {
    cout << "请输入假币重量: ";
    int fake;
    cin >> fake;
    cout << "请输入真币重量: ";
    int real;
    cin >> real;
    //初始化
    int a[8] = {real, real, fake, real, real, real, real, real};
    switch (compare(a[0] + a[1] + a[2], a[3] + a[4] + a[5])) {
    case '=':
        if(a[6] > a[7])
            comp(a[6], a[7], a[0]);
        else
            comp(a[7], a[6], a[0]);
        break;
    case '>':
        switch (compare(a[0] + a[3], a[1] + a[4])) {
        case '=':
            comp(a[2], a[5], a[0]);
            break;
        case '>':
            comp(a[0], a[4], a[0]);
        case '<':
            comp(a[1], a[3], a[0]);
            break;
        default:
            break;

        }
    case '<':
		switch (compare(a[0]+a[3],a[1]+a[4])) {
			case '=':
				comp(a[5],a[2],a[0]);
				break;
				comp(a[3],a[1],a[0]);
				break;
				comp(a[4],a[0],a[1]);	
				break;
			default:
				break;
				
		}
    default:
        break;

    }

}
