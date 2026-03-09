//
// Created by jianf on 3/4/2026.
//

#include "Stack1.h"
#include "iostream"

#define MAX_STACK 10

using namespace  std;

struct Stack {
    int A[MAX_STACK];
    int top;
};

void initStack(Stack *&s) {
    s->top = -1;
}
bool isEmpty(Stack *s) {
    return s->top == -1;
}
bool isFull(Stack *s) {
    return s->top == MAX_STACK;
}

void push(Stack *&s, int data) {
    if (isFull(s)) {
        cout << "The stack is overflow!" << endl;
        return;
    }

    s->top++;
    s->A[s->top] = data;
    cout << "The data: " << data << " is push in stack with top : " << s->top << endl;
}

int popUp(Stack *s) {
    if (isEmpty(s)) {
        cout << " The stack is empty! " << endl;
        return -1;
    }

    int data = s->A[s->top];
    s->top--;
    return data;

}

void printStack(Stack *s) {
    if (isEmpty(s)) {
        cout << " The Stack is empty! " << endl;
    }
    cout << "Stack: \n";
    for (int i = s->top ; i >= 0 ; i--) {
        cout << s->A[i] <<  " -> " ;
    }
}
int main() {
    Stack *s = new Stack;
    initStack(s);
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    push(s,5);
    push(s,6);

    printStack(s);

    cout << "\nPop up : " << popUp(s) << endl;
    cout << "\nPop up : " << popUp(s) << endl;

    printStack(s);

}