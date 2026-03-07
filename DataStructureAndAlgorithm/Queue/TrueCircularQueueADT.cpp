//
// Created by jianf on 3/7/2026.
//

#include "TrueCircularQueueADT.h"
#include "iostream"
using namespace std;
#define MAX_QUEUE 10
struct Queue {
    int A[MAX_QUEUE];
    int front;
    int rear;
    int count;
};
void initQueue(Queue *&q) {
    q->front = 0;
    q->rear = 0;
    q->count = 0;
}
bool isEmpty(Queue *q) {
    return q->count == 0;
}
bool isFull(Queue *q) {
    return q->count == MAX_QUEUE;
}

void enqueue(Queue *&q, int data) {
    if (isFull(q)) {
        cout << "The queue is full!" << endl;
        return;
    }


    q->A[q->rear] = data;
    cout << "\nEnqueue: " << data << " at rear : " << q->rear << endl;
    q->rear = ( q->rear + 1 ) % MAX_QUEUE;
    q->count++;
}
int dequeue(Queue *&q) {
    if (isEmpty(q)) {
        cout << "The Queue is empty!" << endl;
        return -1;
    }
    int data = q->A[q->front];
    q->front = ( q->front + 1 ) % MAX_QUEUE;
    q->count--;
   return data;
}
int count(Queue *q) {
    return q->count;
}

void printQueue(Queue *q) {
    cout << "The queue is: " << endl;
    int i = q->front;
    for ( int k = 0 ; k < q->count ; k++) {
        cout << q->A[i] << " --> " ;
        i =  ( i + 1 ) % MAX_QUEUE;
    }
    cout << "\n Queue has: " << count(q) << " items " << endl;
}

int main() {
    Queue *q = new Queue;
    initQueue(q);
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    cout << "\nDequeue: " << dequeue(q) << endl;
    enqueue(q,5);
    enqueue(q,6);
    enqueue(q,7);
    enqueue(q,8);
    enqueue(q,9);
    enqueue(q,10);
    printQueue(q);
    cout << "\nDequeue: " << dequeue(q) << endl;
    cout << "\nDequeue: " << dequeue(q) << endl;
    printQueue(q);

    enqueue(q,2);
    enqueue(q,3);
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

    enqueue(q,3);


    printQueue(q);
}
