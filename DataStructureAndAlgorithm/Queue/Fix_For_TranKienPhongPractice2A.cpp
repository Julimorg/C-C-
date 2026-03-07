//
// Created by jianf on 3/5/2026.
//

#include "Fix_For_TranKienPhongPractice2A.h"
#include "iostream"

using namespace std;
#define MAX_QUEUE 10

struct Queue {
    int A[MAX_QUEUE];
    int front;
    int rear;
};

void initQueue(Queue *&q) {
    q->front = -1;
    q->rear = -1;
}

bool isFull(Queue *q) {
    return (q->rear + 1) % MAX_QUEUE == q->front;
}

bool isEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *&q, int data) {
    if (isFull(q)) {
        cout << "The Queue is full!" << endl;
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear =  ( q->rear + 1 ) % MAX_QUEUE;
    q->A[q->rear] = data;
    cout << "\nEnqueue: " << data << " at rear :" << q->rear << endl;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        cout << "The Queue is empty!" << endl;
    }
    int data = q->A[q->front];
    if (q->front ==  q->rear) {
        q->rear = -1;
        q->front = -1;
    }else {
        q->front = ( q->front + 1 ) % MAX_QUEUE;
    }
    return data;
}
void printQueue(Queue *q) {
    cout << "Queue: " << endl;
    for (int i = q->front ;  i <= q->rear ; i++) {
        cout << q->A[i] << " --> " ;
    }
}

int main() {
    Queue *q = new Queue;
    initQueue(q);
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,5);
    enqueue(q,6);
    enqueue(q,7);
    enqueue(q,8);
    enqueue(q,9);
    enqueue(q,10);

    printQueue(q);

    cout << "\nDequeue :" << dequeue(q) << endl;
    cout << "\nDequeue :" << dequeue(q) << endl;
    cout << "\nDequeue :" << dequeue(q) << endl;
    cout << "\nDequeue :" << dequeue(q) << endl;
    cout << "\nDequeue :" << dequeue(q) << endl;
    cout << "\nDequeue :" << dequeue(q) << endl;
    cout << "\nDequeue :" << dequeue(q) << endl;
    cout << "\nDequeue :" << dequeue(q) << endl;

    printQueue(q);

    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,5);
    enqueue(q,6);
    enqueue(q,7);
    enqueue(q,8);

    printQueue(q);


}