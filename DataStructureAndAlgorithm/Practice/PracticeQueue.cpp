//
// Created by jianf on 3/27/2026.
//

#include "PracticeQueue.h"
#include "iostream"

using namespace std;

#define MAX_SIZE 10

struct Queue {
    int data[MAX_SIZE];
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
    return q->rear == MAX_SIZE;
}

void enqueue(Queue *&q, int data) {
    if (isFull(q)) {
        cout << " The queue is Full!" << endl;
        return;
    }

    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->data[q->rear] = data;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        cout << " The queue is already empty! " << endl;
        return -1;
    }

    int data = q->data[q->front];

    q->front++;

    return data;
}

int count (Queue *q) {
    return q->rear - q->front;
}
void printQueue(Queue *q) {
    cout << "Queue:\n front = " << q->front << " <<<<< rear = " << q->rear << endl ;
    for (int i = q->front ; i <= q->rear ; i++) {
        cout << q->data[i] <<  " -> " ;
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

    printQueue(q);

    cout << " \n\nDequeue " << dequeue(q) << endl << endl;

    printQueue(q);

    cout << " \n\nDequeue " << dequeue(q) << endl << endl;

    printQueue(q);
}