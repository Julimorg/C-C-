#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iostream>

using namespace std;

// ============ QUESTION 3 ===========

typedef struct StackNode {
    char data;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
} StackChar;

void initStackChar(StackChar* s) { s->top = NULL; }

int isEmptyChar(StackChar* s) { return s->top == NULL; }

void pushChar(StackChar* s, char c) {
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->data = c;
    node->next = s->top;
    s->top = node;
}

char popChar(StackChar* s) {
    if (isEmptyChar(s)) return '\0';

    StackNode* temp = s->top;
    char val = temp->data;

    s->top = s->top->next;
    free(temp);

    return val;
}

char peekChar(StackChar* s) {
    if (isEmptyChar(s)) return '\0';
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

    StackChar s;
    initStackChar(&s);

    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {

        char token = infix[i];

        if (token == ' ') continue;

        if (isalpha(token) || isdigit(token)) {
            postfix[j++] = token;
        }

        else if (token == '(') {
            pushChar(&s, token);
        }

        else if (token == ')') {

            while (!isEmptyChar(&s) && peekChar(&s) != '(') {
                postfix[j++] = popChar(&s);
            }

            popChar(&s);
        }

        else if (isOperator(token)) {

            while (!isEmptyChar(&s) &&
                   isOperator(peekChar(&s)) &&
                   precedence(peekChar(&s)) >= precedence(token)) {

                postfix[j++] = popChar(&s);
            }

            pushChar(&s, token);
        }
    }

    while (!isEmptyChar(&s)) {
        postfix[j++] = popChar(&s);
    }

    postfix[j] = '\0';
}


// ============ QUESTION 4 ===========

struct Node {
    int data;
    Node *next;
};

struct StackInt {
    Node *top;
};

void initStackInt(StackInt *s) {
    s->top = NULL;
}

int isEmptyInt(StackInt *s) {
    return s->top == NULL;
}

void pushInt(StackInt *s, int c) {
    Node *newNode = new Node;
    newNode->data = c;
    newNode->next = s->top;
    s->top = newNode;
}

int popInt(StackInt* s) {

    if (isEmptyInt(s)) return 0;

    Node* temp = s->top;
    int val = temp->data;

    s->top = s->top->next;

    delete temp;

    return val;
}

int calculatePostFix(char *c) {

    StackInt s;

    initStackInt(&s);

    char buffer[256];

    strcpy(buffer, c);

    char* token = strtok(buffer, " ");

    while (token != NULL) {

        if (isdigit(token[0])) {

            pushInt(&s, atoi(token));
        }
        else {

            int first = popInt(&s);
            int second = popInt(&s);

            int result = 0;

            switch (token[0]) {

                case '+': result = second + first; break;
                case '-': result = second - first; break;
                case '*': result = second * first; break;
                case '/': result = second / first; break;

                default:
                    cout << "Error !" << endl;
                    break;
            }

            cout << "second: " << second
                 << " -> token : " << token[0]
                 << " -> first: " << first
                 << " = " << result << endl;

            pushInt(&s, result);
        }

        token = strtok(NULL, " ");
    }

    return popInt(&s);
}



int main() {

    /* ---- TEST INFIX -> POSTFIX ---- */

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
    printf("Expected: ABC*+\n\n");


    /* ---- TEST POSTFIX CALCULATE ---- */

    char* expr =zz (char*)"40 6 2 - / 3 * 4 +";

    cout << "Postfix: " << expr << endl;
    cout << "Step calculate:\n";

    int result = calculatePostFix(expr);

    cout << "the result = " << result << endl;

    return 0;
}