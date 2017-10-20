#include <iostream>
using namespace std;
struct node {
    char data;
    node *next;
};
class String {
protected:
    node *head;
public:
    int size;
    String() {

    }
    String(const char* chars) {
        node *temp;
        head = new node;
        node *p = head;
        size = 0;
        for(int i = 0; chars[i] != '\0'; i++) {
            temp = new node;
            temp->data = chars[i];
            p->next = temp;
            temp->next = NULL;
            p = p->next;
            size++;
        }
    }

    void show() {
        for(head = head->next; head->next != NULL; head = head->next) {
            cout << head->data;
        }
        cout << head->data;
        cout << endl;
    }

    // bool replace() {
    //
    // }

    char operator [](int index) {
        if(index < 0 || index >= size) {
            throw("please input the right index");
        }
        node *p;
        p = head->next;
        for( int i = 0; i < index; i ++, p = p->next);
        return p->data;
    }


// private:
    // void getNext(String *str, int  *next) {
    //     int i = 0; //控制子串长度
    //     int j = -1; // 最大相等的前缀后缀长度
    //     while(i < str->size) {
    //         if( j == -1 &&  )
    //
    //     }



// }


};

int main() {
    const char *a = "tesoi";
    String *s = new String("sssss");
    cout << s->size;
    char c = s[2];
    s->show();
}
