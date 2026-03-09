//
// Created by jianf on 3/9/2026.
//

#include "2180607876_TranKienPhong_practice3D.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct StackNode {
    char data;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
} Stack;

void initStack(Stack* s) { s->top = NULL; }

int isEmpty(Stack* s) { return s->top == NULL; }

void push(Stack* s, char c) {
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->data = c;
    node->next = s->top;
    s->top = node;
}

char pop(Stack* s) {
    if (isEmpty(s)) return '\0';
    StackNode* temp = s->top;
    char val = temp->data;
    s->top = s->top->next;
    free(temp);
    return val;
}

char peek(Stack* s) {

    if (isEmpty(s)) return '\0';
    return s->top->data;
}


int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}


void infixToPostfix(char* infix, char* postfix) {
    Stack s;
    initStack(&s);
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];

        if (token == ' ') continue;

        if (isalpha(token) || isdigit(token)) {
            postfix[j++] = token;
        }

        else if (token == '(') {
            push(&s, token);
        }


        else if (token == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s);
        }


        else if (isOperator(token)) {
            while (!isEmpty(&s) &&
                   isOperator(peek(&s)) &&
                   precedence(peek(&s)) >= precedence(token)) {
                postfix[j++] = pop(&s);
            }
            push(&s, token);
        }
    }


    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0';
}



int main() {
    char infix[100];
    char postfix[100];

    strcpy(infix, "(A/(B-C)*D+E)");
    infixToPostfix(infix, postfix);
    printf("Infix  : %s\n", infix);
    printf("Postfix: %s\n", postfix);
    printf("Expected: ABC-/D*E+\n\n");

    strcpy(infix, "A+B*C");
    infixToPostfix(infix, postfix);
    printf("Infix  : %s\n", infix);
    printf("Postfix: %s\n", postfix);
    printf("Expected: ABC*+\n");

    return 0;
}