//
// Created by jianf on 3/5/2026.
//

#include "Tran_Kien_Phong_Practice2_A.h"
#include "iostream"

using namespace  std;

#define  MAX_QUEUE 10

struct Queue {
    int A[MAX_QUEUE];
    int front;
    int rear;
};

void initQueue(Queue &q) {
    q.front = -1;
    q.rear = -1;
}

bool isEmpty(Queue q) {
    return q.front == -1;
}

bool isFull(Queue q) {
    return q.rear == MAX_QUEUE;
}

void enqueue(Queue &q, int data) {

    if (isFull(q)) {
        cout << "The queue is full!" << endl;
        return;
    }
    if (isEmpty(q)) {
        q.front = 0;
        q.rear = 0;
    }

    cout << "Enqueue: " << data << " at rear = " << q.rear << " | "  << endl;

    q.A[q.rear++] = data;

}

int dequeue(Queue &q) {
    if (!isEmpty(q)) {
        return q.A[q.front++] ;
    }
    return -1;
}

int count(Queue q) {
  return q.rear - q.front;
}


void printQueue(Queue q) {
    cout << "Queue: \n" << " front : " << q.front << " <<<< rear = " << q.rear << endl;
    for ( int i = q.front ; i < q.rear ; i++ ) {
        cout << "A: " << q.A[i] << " " << endl;
    }
    cout << "\n<<<<< " << count(q) << " items <<< \n\n" ;
}

int main() {

    Queue q;
    initQueue(q);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);
    enqueue(q, 7);
    enqueue(q, 8);
    enqueue(q, 9);
    enqueue(q, 1);

    printQueue(q);

    return 0;
}