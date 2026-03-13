#include <iostream>
using namespace std;


// ================ QUESTION 1 ===========

namespace ArrayStack {

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
        } else if (isClose(c)) {
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

}

// ================ QUESTION 2 ===========

namespace LinkedStack {

struct Node {
    int data;
    Node *next;
};

struct Stack {
    Node *top;
};

void initStack(Stack *&s) {
    s->top = NULL;
}

bool isEmpty(Stack *s) {
    return s->top == NULL;
}

void push(Stack *&s, int data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}

int popUp(Stack *&s) {
    if (isEmpty(s)) {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    int data = s->top->data;
    Node *temp = s->top;
    s->top = s->top->next;
    delete temp;
    return data;
}

int peek(Stack *s) {
    return s->top->data;
}

void addLast(Node *&head, int data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) { head = newNode; return; }

    Node *cur = head;
    while (cur->next != nullptr) cur = cur->next;
    cur->next = newNode;
}

bool isPalindrome(Node *head) {
    Stack *s = new Stack;
    initStack(s);

    Node *cur = head;
    while (cur != nullptr) {
        push(s, cur->data);
        cur = cur->next;
    }

    cur = head;
    while (cur != nullptr) {
        if (popUp(s) != cur->data) {
            delete s;
            return false;
        }
        cur = cur->next;
    }

    delete s;
    return true;
}

void printList(Node *head) {
    Node *cur = head;
    while (cur != nullptr) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

}
int main() {

    cout << "========== BAI 1: KIEM TRA NGOAC ==========\n";
    char a[] = "{ ( [] ) }";
    char b[] = "{ ( [) }";
    char c[] = "( abc (";
    char d[] = "( ) ( ( ) )";

    ArrayStack::checkBrackets(a);
    ArrayStack::checkBrackets(b);
    ArrayStack::checkBrackets(c);
    ArrayStack::checkBrackets(d);


    cout << "\n========== BAI 2: KIEM TRA PALINDROME ==========\n";

    LinkedStack::Node *list1 = nullptr;
    int arr1[] = {4, 5, 6, 7, 8, 7, 6, 5, 4};
    for (int x : arr1) LinkedStack::addLast(list1, x);
    cout << "Danh sach 1: "; LinkedStack::printList(list1);
    cout << (LinkedStack::isPalindrome(list1) ? "=> Is palindrome\n" : "=> Is NOT palindrome\n");

    LinkedStack::Node *list2 = nullptr;
    int arr2[] = {4, 5, 6, 7, 4, 5, 6, 7};
    for (int x : arr2) LinkedStack::addLast(list2, x);
    cout << "\nDanh sach 2: "; LinkedStack::printList(list2);
    cout << (LinkedStack::isPalindrome(list2) ? "=> Is palindrome\n" : "=> Is NOT palindrome\n");

    LinkedStack::Node *list3 = nullptr;
    int arr3[] = {1,2,3,4,5,6,7,8,9,10,9,8,7,6,5,4,3,2,1};
    for (int x : arr3) LinkedStack::addLast(list3, x);
    cout << "\nDanh sach 3: "; LinkedStack::printList(list3);
    cout << (LinkedStack::isPalindrome(list3) ? "=> Is palindrome\n" : "=> Is NOT palindrome\n");

    return 0;
}