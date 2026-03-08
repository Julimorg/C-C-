//
// Created by jianf on 3/7/2026.
//

#include "QueueByLinkedList.h"
#include "iostream"
using namespace std;

struct Node {
    int data;
    Node *next;
};

struct Queue {
    Node *head;
    Node *tail;
    int size;
};
Node *createNewNode(int data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
Queue *createQueue() {
    Queue *q = new Queue;
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}
bool isEmpty(Queue *q) {
    return q->head == NULL;
}

void enqueue(Queue *q, Node *newNode) {
    if (isEmpty(q)) {
        q->head = newNode;
        q->tail = newNode;
    }else {
        q->tail->next = newNode;
        q->tail = newNode;
    }
    q->size++;

    cout << "Enqueued: " << newNode->data << endl;
}
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        cout << "The Queue is already empty! " << endl;
        return -1;
    }
    Node *temp = q->head;
    int value = temp->data;

    q->head = q->head->next;

    if (q->head == NULL) {
        q->tail=  NULL;
    }

    free(temp);
    q->size--;
    return value;
}
void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("[EMPTY]\n");
        return;
    }
    cout << "head -> " ;
    Node *cur = q->head;
    while (cur != NULL ) {
        cout << cur->data << " --> " ;
        cur = cur->next;
    }
    cout << " NULL " ;
    cout << " <--- tail " << " size : " << q->size << endl;
}

int main() {
    Queue *q = createQueue();
    enqueue(q, createNewNode(10));
    enqueue(q, createNewNode(20));
    enqueue(q, createNewNode(30));
    enqueue(q, createNewNode(40));
    enqueue(q, createNewNode(50));
    enqueue(q, createNewNode(60));
    printQueue(q);
    cout << "Dequeue : " << dequeue(q) << endl;
    printQueue(q);
}