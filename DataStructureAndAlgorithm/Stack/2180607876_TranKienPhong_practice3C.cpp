#include <iostream>
using namespace std;

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


int main() {
    Node *list1 = nullptr;
    int a[] = {4, 5, 6, 7, 8, 7, 6, 5, 4};
    for (int x : a) addLast(list1, x);
    cout << "Danh sach 1: "; printList(list1);
    cout << (isPalindrome(list1) ? "=> Is palindrome\n" : "=> Is NOT palindrome\n");

    Node *list2 = nullptr;
    int b[] = {4, 5, 6, 7, 4, 5, 6, 7};
    for (int x : b) addLast(list2, x);
    cout << "\nDanh sach 2: "; printList(list2);
    cout << (isPalindrome(list2) ? "=> Is palindrome\n" : "=> Is NOT palindrome\n");

    Node *list3 = nullptr;
    int c[] = {1,2,3,4,5,6,7,8,9,10,9,8,7,6,5,4,3,2,1};
    for (int x : c) addLast(list3, x);
    cout << "\nDanh sach 3: "; printList(list3);
    cout << (isPalindrome(list3) ? "=> Is palindrome\n" : "=> Is NOT palindrome\n");
}