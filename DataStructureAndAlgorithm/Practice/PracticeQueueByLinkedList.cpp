//
// Created by jianf on 3/27/2026.
//

#include "PracticeQueueByLinkedList.h"

#include "iostream"

using namespace  std;

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
    Node *newNode = new Node ;
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

Queue *initQueue() {
    Queue *newQueue = new Queue;
    newQueue->head = NULL;
    newQueue->tail = NULL;
    newQueue->size = 0;

    return newQueue;
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
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        cout << " The queue is already empty !" << endl;
        return -1;
    }

    Node *temp = q->head;

    int data = q->head->data;

    q->head = q->head->next;

    q->size--;
    delete(temp);

    return data;

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
    Queue *q = initQueue();
    enqueue(q, createNewNode(10));
    enqueue(q, createNewNode(20));
    enqueue(q, createNewNode(30));
    enqueue(q, createNewNode(40));

    printQueue(q);

    cout << " \nDequeue : " << dequeue(q) << endl;

    printQueue(q);

    cout << " \nDequeue : " << dequeue(q) << endl;

    printQueue(q);


}

