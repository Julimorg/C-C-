//
// Created by jianf on 3/12/2026.
//

#include "Stack2.h"
#include "iostream"

using namespace std;

struct Node {
    int data;
    Node *next;
};

struct Stack {
    int size;
    Node *top;
};
Node *createNewNode(int data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void initStack(Stack *&s) {
    s->top = NULL;
    s->size = 0;
}
bool isEmpty(Stack *s) {
    return s->top == NULL;
}

void push(Stack *&s, Node *newNode) {
    newNode->next = s->top;
    s->top = newNode;
    s->size++;
    cout << "\nPush : " << newNode->data << " into Stack !" << endl;
}

int pop(Stack *&s) {
    if (isEmpty(s)) {
        cout << "Stack is empty !" << endl;
        return -1;
    }
    Node *curr = s->top;

    int data = curr->data;

    s->top = curr->next;

    delete(curr);

    s->size--;

    return data;
}

int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Lỗi: Stack rỗng!\n");
        return -1;
    }
    return s->top->data;
}
void printStack(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("top -> ");
    Node *curr = s->top;
    while (curr != NULL) {
        cout << curr->data <<  " --> " ;
        curr = curr->next;
    }
    cout << " NULL " << endl;
}

int main() {
    Stack *s = new Stack;
    initStack(s);
    push(s, createNewNode(10));
    push(s, createNewNode(20));
    push(s, createNewNode(30));
    push(s, createNewNode(40));
    push(s, createNewNode(50));

    printStack(s);

    cout << "\nPop : " << pop(s) << endl;
    cout << "\nPop : " << pop(s) << endl;

    printStack(s);
}