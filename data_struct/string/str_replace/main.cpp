#include <iostream>
using namespace std;
struct node {
    char data;
    node *next;
};
void strToList(const char *charp, node *head) {
    node *temp;
    for(int i = 0; charp[i] != '\0'; i++) {

        temp = new node;
        temp->data = charp[i];
        head->next = temp;
        temp->next = NULL;
        head = head->next;
    }
}
void showList(node *head) {
    for(head = head->next; head->next != NULL; head = head->next) {
        cout << head->data;
    }
    cout << head->data;
    cout << endl;
}

bool findStr(node *subTHead, node * subPHead, node *Phead, node *&head) {
    if(subPHead == NULL)
        return true;
    if(subTHead == NULL)
        return false;
    else {
        if(subTHead->data == subPHead->data) {
            if (head == NULL) {
                head = subTHead;
            }
            if (findStr(subTHead->next, subPHead->next, Phead, head)) {
                return true;
            } else return false;
        } else {
            head = NULL;
            if(findStr(subTHead->next, Phead, Phead, head))
                return true;
            else return false;
        }
    }
}

void StrReplace(const char *T, const char *P, const char *S) {
    //转化字符指针为链表
    node *Thead = new node;
    node *Phead = new node;
    node *Shead = new node;
    strToList(T, Thead);
    strToList(P, Phead);
    strToList(S, Shead);

    cout << "目标字符串：";
    showList(Thead);
    cout << "替换的字符串（仅替换出现的第一个）： ";
    showList(Phead);
    cout << "待替换的字符串";
    showList(Shead);

    int Psize = 1;
    for(node *temp = Phead->next; temp->next != NULL; temp = temp->next, Psize++);
    node *head = NULL;

    if(findStr(Thead->next, Phead->next, Phead->next, head) == false) {
        cout << "没有找到可以替换的字符串" << endl;
        return;
    }
    node *temp;
    for(temp = Thead; temp->next != head; temp = temp->next);
    for(int i = 1; i <= Psize; head = head->next, i++);
    node *temp2;
    temp2 = Shead;
    for(; temp2->next != NULL; temp2 = temp2->next);
    temp2->next = head;
    temp->next = Shead->next;
    cout << "最终字符串: " << endl;
    showList(Thead);

}
int main() {
    const char *T = "test1234352323Phead";
    const char *P = "tes";
    const char *S = "head";
    StrReplace(T, P, S);




}
