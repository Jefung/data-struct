#include "main.h"
int main() {
    Queue<int> *queue = new Queue<int>(10);
    queue->enqueue(22);
    queue->enqueue(32);
    queue->enqueue(42);
    queue->show();
    queue->dequeue();
    queue->show();
    queue->dequeue();
    queue->show();
}
