//
// Created by jianf on 3/5/2026.
//

#include "Tran_Kien_Phong_Practice2_A.h"

#include <deque>

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
    return q.rear == -1;
}

bool isFull(Queue q) {
    return q.rear == MAX_QUEUE;
}

void enqueue(Queue &q, int data) {

    if (isFull(q)) {
        cout << "The queue is full!" << endl;
        return;
    }
    // Question 2
    //? Phan check nay se sinh ra sai khi dung cirular queue
    if (isEmpty(q)) {
        q.front = 0;
        q.rear = 0;
    }

    cout << "Enqueue: " << data << " at rear = " << q.rear << " | "  << endl;

    // Question 2
    // Khi ma rear da dat toi rear = 10;
    // dung rear = rear % 10 -> 10 % 10 = 0;
    q.A[q.rear++] = data;

    // remove the line below
    // q.rear %= MAX_QUEUE;
}

int dequeue(Queue &q) {
    if (!isEmpty(q)) {
        return q.A[q.front++] ;
    }
    return -1;
}

int count(Queue q) {
    // Question 2
    // ma check count lai la 0 - 1 -->  count se bi sai la count = -1
  return q.rear - q.front;
}


void printQueue(Queue q) {
    if (isEmpty((q))) {
        cout << "The Queue is empty!";
        return;
    }
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

    cout << "Dequeue:  " << dequeue(q) << endl;

    enqueue(q, 5);
    enqueue(q, 6);
    enqueue(q, 7);
    enqueue(q, 8);
    enqueue(q, 9);
    enqueue(q, 1);
    cout << "The rear is:  " <<  q.rear << endl;
    cout << "Count: " << count(q) << endl;
    cout << "Dequeue: " << dequeue(q) << endl;
    cout << "Dequeue: " << dequeue(q) << endl;
    cout << "Count: " << count(q) << endl;
    enqueue(q, 2);
    enqueue(q, 3);
    printQueue(q);


    return 0;
}