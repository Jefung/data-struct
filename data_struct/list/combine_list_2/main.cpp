#include <iostream>
using namespace std;
struct node {
    int data;
    node* next;
};
void createList(node* &head) {



    node *p, *s;
    p = NULL;
    s = new node;
    cout << "请输入链表元素，0结束输入: ";
    cin >> s->data;
    while (s->data == 0) {
        cout << "请输入元素： " << endl;
        cin >> s->data;
    }
    while (s->data != 0) {
        if (head == NULL)
            head = s;
        else p->next = s;
        p = s;
        s = new node;
        cin >> s->data;
    }
    p->next = NULL;
    // delete s;
    return;

}

void showList(node* head) {
    node* p = head;
    for (; p->next != NULL; p = p->next) {
        cout << p->data << " ";
    }
    cout << p->data;
    cout << endl;
}

int countList(node* head) {
    node* headSave = head;
    int i = 1;
    for (; headSave->next != NULL; headSave = headSave->next, i++);
    return i;
}
node* combineList(node* Lhead, node* Shead) {
    node *tail = new node;
    node * combListHead = tail;
    node *temp;


    for(; Shead->next != NULL; Lhead = Lhead->next, Shead = Shead->next) {
        temp = new node;
        temp->data = Lhead->data;
        tail->next = temp;
        tail = tail->next;
        temp = new node;
        temp->data = Shead->data;
        tail->next = temp;
        tail = tail->next;
    }
    temp = new node;
    temp->data = Lhead->data;
    tail->next = temp;
    tail = tail->next;
    temp = new node;
    temp->data = Shead->data;
    tail->next = temp;
    tail = tail->next;
    tail->next = Lhead->next;
    return combListHead->next;
}
int main() {
    node* head1 = NULL;
    node* head2 = NULL;
    //¿¿¿¿

    createList(head1);
    createList(head2);
    // showList(head1);
    // showList(head2);
    cout << head2->data << endl;
    //¿¿¿¿
    node *combHead = countList(head1) >= countList(head2) ? combineList(head1, head2) : combineList(head2, head1);
    showList(combHead);
}
