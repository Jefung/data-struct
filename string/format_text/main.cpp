/*
* auth        : Jefung
* version     : v1.0
* description :
*
* analyse     :
*
*/

#include <iostream>
#include <string>
using namespace std;
const int maxworklength = 12;
const int maxlinelength = 60;
struct word {
    int length;
    char content[maxworklength + 2];
};

class TextFormat {
private:
    char line[maxlinelength];
    int lpos;
public:
    TextFormat() {
        lpos = 0;
    }
    void getInputText() {
        word  w;
        w = getWord();
        while(w.length != 0) {
            lineAppend(w);
            w = getWord();
        }
    }
    word getWord() {
        char c;
        word w;
        w.length = 0;
        cin >> c;
        //去除字符前的空格
        while( c == ' ' || c == '\n' ) {
            cin.get(c);
        }
        while(  c != ' ' && c != '\n') {
            w.content[w.length] = c;
            w.length++;
            // cin >> c;
            cin.get(c);
        }
        // for(int i = 0; i < w.length; i++) {
        //     cout << w.content[i];
        // }
        return w;
    }

    char* showWord(word w) {
        char *str;
        for(int i = 0; i < w.length; i++) {
            str[i] = w.content[i];
        }
        return str;

    }

    void lineAppend(word w) {
        if(strcmp(showWord(w), "/PAR/")) {
            cout << endl;
            lpos = 0;
            return;
        }

        if(maxlinelength - lpos >=  w.length) {
            cout << showWord(w) << " ";
            lpos = lpos + w.length + 1;
        } else {
            lpos = 0;
            cout << endl;
            cout << showWord(w) << " ";
            lpos = lpos + w.length + 1;
        }



    }
};

int main() {
    TextFormat text = TextFormat();
    text.getInputText();

}
