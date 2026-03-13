//
// Created by jianf on 3/12/2026.
//

#include "Stack3.h"
#include "iostream"

#define  MAX_STACK 10

using namespace std;

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
    return s->top == MAX_STACK - 1;
}

bool isOpen(char c) {
    return c == '{' || c == '(' || c == '[';
}

bool isClose(char c ) {
    return c == '}' || c == ')' || c == ']';
}

bool isMatch(char open, char close) {
    return (open == '(' && close == ')')
        || (open == '[' && close == ']')
        || (open == '{' && close == '}');
}

void push(Stack *&s, int c) {
    if (isFull(s)) {
        cout << "Stack is full!" << endl;
        return ;
    }
    s->top++;
    s->A[s->top] = c;
    cout << c << " into Stack " << endl;
}

int pop(Stack *&s) {
    if (isEmpty(s)) {
        cout <<  "Stack is empty !" << endl;
        return -1;
    }
    int data = s->A[s->top];
    s->top--;
    return data;
}
int peek(Stack *s) {
    return s->A[s->top];
}
void isValid(char input[]) {
    Stack *s = new Stack;
    initStack(s);
    for ( int i = 0 ; input[i] != '\0' ; i++) {
        char c = input[i];
        if (isOpen(c)) {
           push(s,i);
        }else if (isClose(c)) {
            if (isEmpty(s)) {
                cout << "INVALID AT POSITION: " << i << endl;
                delete s;
                return;
            }
            int openPos = peek(s);
            if (!isMatch(input[openPos], c)) {
                cout << "The open: " << input[openPos] << endl;
                cout << "INVALID: " << c << " AT POSITION : " << i << " NOT MATCH TO : " << input[openPos] << endl;
                delete s;
                return;
            }
            pop(s);
        }
    }

    if (!isEmpty(s)) {
        int openPos = peek(s);
        cout << "INVALID " << input[openPos] << "AT POSITION : " << openPos << endl;
    }else {
        cout << "VALID!"<< endl;

    }
    delete s;
}
void printStack(Stack *s) {
    for (int i = s->top ; i >= 0 ; i--) {
        cout << s->A[i] << " --> " ;
    }
    cout << " End !" << endl;
}

int main() {
    Stack *s = new Stack;
    // initStack(s);
    // push(s,'{');
    // push(s,'}');
    // push(s,'{');
    // push(s,')');
    // push(s,']');
    //
    // printStack(s);


    char a[] = "{ ( [] ) }";
    char b[] = "{ ( [) }";
    char c[] = "( abc (";

    // printStack(s);

    isValid(a);
    isValid(b);
    isValid(c);

    return 0;
}