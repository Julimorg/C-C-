//
// Created by jianf on 2/24/2026.
//

#include "LinkList1.h"
#include "iostream"

using namespace  std;

struct Node {
    int data;
    Node *next;
};

Node *createNewNode(int data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insertHead(Node *&head, Node *newNode) {
    newNode->next = head;
    head =  newNode;
}

void countNode( Node *head) {
    int count = 0;
    cout << "the number of node in linklist is: " ;
    while (head->next != NULL) {
        count++;
        head = head->next;
    }
    cout << count ;
}

void printList(Node *head) {
    cout << "LINK LIST: " << endl;
    Node *node = head;
    while ( node->next != NULL) {
        cout << node->data << " -> " ;

        node = node->next;

    }
    cout << " NULL " << endl;
}

int main() {
    Node *head = NULL;
    insertHead(head, createNewNode(10));
    insertHead(head, createNewNode(20));
    insertHead(head, createNewNode(30));
    insertHead(head, createNewNode(40));
    insertHead(head, createNewNode(50));

    printList(head);
    countNode(head);

    return 0;
}