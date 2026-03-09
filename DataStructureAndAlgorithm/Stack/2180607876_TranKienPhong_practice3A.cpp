//
// Created by jianf on 3/9/2026.
//

#include "2180607876_TranKienPhong_practice3A.h"
#include "iostream"

using namespace std;

#define MAX_STACK 10

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
// ==================== STACK VOI LINKEDLIST  ================
struct Node {
    int data;
    Node *next;
};

struct StackLinkedList {
    int size;
    Node *top;
};

void initStackLinkedList(StackLinkedList *&s) {
    s->top = NULL;
    s->size = 0;
}

bool isEmptyStackLinkedList(StackLinkedList* s) {
    return s->top == NULL;
}

Node *createNewNode(int data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void pushStackLinkedList(StackLinkedList *&s, Node *newNode) {
    if (newNode == NULL) {
        cout << "The Stack is full!" << endl;
        return;
    }
    newNode->next = s->top;
    s->top = newNode;
    s->size++;

    cout << "Push : " << newNode->data << endl;
}

int popUpStackLinkedList(StackLinkedList *&s) {
    if (isEmptyStackLinkedList(s)) {
        cout << " The Stack is empty !" << endl;
        return -1;
    }
    Node *temp = s->top;
    int value = temp->data;
    s->top = s->top->next;
    delete(temp);
    s->size--;
    return value;
}


void printStackLinkedList(StackLinkedList* s) {
    if (isEmptyStackLinkedList(s)) {
        cout << "The Stack is empty! " << endl;
        return;
    }
    cout << "Stack top to bottom : "  << endl;
    Node *curr = s->top;
    while (curr != NULL) {
        cout << curr->data << " --> " ;
        curr = curr->next;
    }
    cout << " Null " << endl;
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

    cout << " \n ============== Stack with Linkedlist ========= \n" ;

    StackLinkedList *stack;
    initStackLinkedList(stack);
    pushStackLinkedList(stack, createNewNode(10));
    pushStackLinkedList(stack, createNewNode(20));
    pushStackLinkedList(stack, createNewNode(30));
    pushStackLinkedList(stack, createNewNode(40));
    pushStackLinkedList(stack, createNewNode(50));
    pushStackLinkedList(stack, createNewNode(60));

    printStackLinkedList(stack);

    cout << "\nPopUp linkedlist: " << popUpStackLinkedList(stack) << endl;
    cout << "\nPopUp linkedlist: " << popUpStackLinkedList(stack) << endl;

    printStackLinkedList(stack);

}