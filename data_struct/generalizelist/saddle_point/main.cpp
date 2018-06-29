/*
* auth        : Jefung
* version     : v1.0
* description : find a point which is minimum in  the row and is maxinum in the column in two-demension array
*
* analyse     :
*
*/

#include <iostream>
using namespace std;
void findSaddle( int**arr, int width, int length) {
    int flag;
    int minR;
    int minC;
    int noOutput = 0;
    // first iterate rows
    for(int i = 0; i < width; i++) {
        minR = arr[i][0];
        flag = 0;
        minC = 0;
        // find the row's mininum
        for (int j = 0; j < length; j++) {
            minR = arr[i][j] < minR ? arr[i][j] : minR;
            minC = arr[i][j] < minR ? j : minC;
        }
        // judge the row's mininum is the column's maxinum
        for(int s = 0; s < width; s++) {
            if(s == i)
                continue;
            if(minR <= arr[s][minC]) {
                flag = 1;
                break;
            }
        }
        if(!flag) {
            noOutput = 1;
            cout << minR << endl;
        }
    }
    if(!noOutput) {
        cout << "there is no saddle!" << endl;
    }
    return;

}
int main() {
    int l, w;
    cout << "please enter the length and width:(for array): " << endl;
    cin >> l >> w;

    int **arr = new int*[w];
    for(int i = 0; i < w; i++)
        arr[i] = new int[l];
    for(int i = 0; i < w; i++) {
        cout << "enter the " << i + 1 << " row data ";
        for(int j = 0; j < l; j++)
            cin >> arr[i][j];
    }
    findSaddle(arr, w, l);

}
