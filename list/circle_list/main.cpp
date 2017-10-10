#include "main.h"
int main() {
    CircleList* head = new CircleList();
    head->append(11);
    head->append(22);
    head->append(33);
    head->append(44);
    head->append(55);
    head->show();
    head->del(2);
    head->show();
    head->del(4);
    head->show();
}
