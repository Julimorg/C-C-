#include <iostream>
using namespace std;

#define MAX_STACK 1000

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

void push(Stack *&s, int data) {
    if (isFull(s)) {
        cout << "The stack is overflow!" << endl;
        return;
    }
    s->top++;
    s->A[s->top] = data;
}

int popUp(Stack *&s) {
    if (isEmpty(s)) return -1;
    int data = s->A[s->top];
    s->top--;
    return data;
}

int peek(Stack *s) {
    return s->A[s->top];
}


bool isOpen(char c) {
    return c == '(' || c == '[' || c == '{';
}

bool isClose(char c) {
    return c == ')' || c == ']' || c == '}';
}

bool isMatch(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

void checkBrackets(char input[]) {
    Stack *s = new Stack;
    initStack(s);

    for (int i = 0; input[i] != '\0'; i++) {
        char c = input[i];

        if (isOpen(c)) {
            push(s, i);
        }
        else if (isClose(c)) {
            if (isEmpty(s)) {
                cout << "INVALID: '" << c << "' tai vi tri " << i
                     << " khong co cap mo!\n";
                delete s;
                return;
            }
            int openPos = peek(s);
            if (!isMatch(input[openPos], c)) {
                cout << "INVALID: '" << c << "' tai vi tri " << i
                     << " khong khop voi '" << input[openPos]
                     << "' tai vi tri " << openPos << "\n";
                delete s;
                return;
            }
            popUp(s);
        }
    }

    if (!isEmpty(s)) {
        int openPos = peek(s);
        cout << "INVALID: '" << input[openPos] << "' tai vi tri "
             << openPos << " khong duoc dong!\n";
    } else {
        cout << "VALID!\n";
    }

    delete s;
}

int main() {
    char a[] = "{ ( [] ) }";
    char b[] = "{ ( [) }";
    char c[] = "( abc (";
    char d[] = "( ) ( ( ) )";

    checkBrackets(a);
    checkBrackets(b);
    checkBrackets(c);
    checkBrackets(d);

    return 0;
}