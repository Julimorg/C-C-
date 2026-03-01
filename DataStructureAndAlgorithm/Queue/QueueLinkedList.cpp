//
// Created by jianf on 3/1/2026.
//

#include "QueueLinkedList.h"
#include "iostream"

using namespace std;

struct Node {
    int data;
    Node *next;
};

struct Queue {
    Node *front;
    Node *rear;
    int size;
};
