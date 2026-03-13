//
// Created by jianf on 3/9/2026.
//

#include "2180607876_TranKienPhong_Practice3E.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iostream>

using namespace  std;
struct Node {
    char data;
    Node *next;
};
struct Stack {
    Node *top;
};
void initStack(Stack *s) {
    s->top = NULL;
}
int isEmpty(Stack *s) {
    return s->top == NULL;
}
void push(Stack *s, char c) {
    Node *newNode = new Node;
    newNode->data = c;
    newNode->next = s->top;
    s->top = newNode;
}
char pop(Stack* s) {
    if (isEmpty(s)) return '\0';
    Node* temp = s->top;
    char val = temp->data;
    s->top = s->top->next;
    free(temp);
    return val;
}
char peek(Stack* s) {
    if (isEmpty(s)) return '\0';
    return s->top->data;
}
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}
int calculatePostFix(char *c) {
    Stack s;
    initStack(&s);
    char buffer[256];
    strcpy(buffer, c);
    char* token = strtok(buffer, " ");
    while (token != NULL) {
        if (isdigit(token[0])) {
            push(&s,atoi(token));
        }else {
            int first = pop(&s);
            int second = pop(&s);
            int result = 0;
            switch (token[0]) {
                case '+': result = second + first; break;
                case '-': result = second - first; break;
                case '*': result = second * first; break;
                case '/': result = second / first; break;
                    default:
                    cout << "Error !" << endl; break;
            }
            cout << "second: " << second <<
                " -> token : " << token[0] <<
                    " -> first: "  << first <<
                        " = " << result << endl;

            push(&s, result);
        }
        token = strtok(NULL, " ");
    }
    return pop(&s);
}
int main() {
    char* expr = "40 6 2 - / 3 * 4 +";

    cout << "Postfix: " <<  expr << endl;
    cout <<  "Step calculate:\n";

    int result = calculatePostFix(expr);

    cout << "the result = " <<  result << endl;

    return 0;
}
