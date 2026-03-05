//
// Created by jianf on 3/1/2026.
//

#include "QueueADT.h"
#include "iostream"
#define MAX_QUEUE 10

using namespace  std;

struct Queue {
    int arrSize[MAX_QUEUE];
    int front;
    int rear;
};

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(Queue *q) {
    return q->front == -1;
}

bool isFull(Queue *q) {
    return q->rear == MAX_QUEUE;
}

void enqueue(Queue *&q, int data ) {
    if (isEmpty(q)) {
        q->front = 0;
    }
    if (isFull(q)) {
        cout << "The queue is full ! Cannot enqueued anymore " << endl;
        return;
    }

    q->rear++;
    q->arrSize[q->rear] = data;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        cout << "The queue is empy!" ;
        return -1;
    }

    int data = q->arrSize[q->front];

    q->front++;

    if ( q->front > q->rear ) {
        q->front = q->rear = -1;
    }

    return data;
}
int count (Queue *q) {
    return q->rear - q->front;
}
void printQueue(Queue *q) {
    cout << "Queue:\n front = " << q->front << " <<<<< rear = " << q->rear << endl ;
    for (int i = q->front ; i <= q->rear ; i++) {
        cout << "A[ " << i << " ] : " << q->arrSize[i] <<  " -> " ;
    }
    cout << "\nItems : " << count(q);
}



int main() {
    Queue *q = new Queue;
    initQueue(q);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    enqueue(q, 60);
    enqueue(q, 70);
    printQueue(q);

    printf("\nDequeue: %d\n", dequeue(q));

    printQueue(q);
    return 0;
}