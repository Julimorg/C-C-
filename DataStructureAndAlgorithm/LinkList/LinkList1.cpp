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

void insertTail(Node *&head, Node *newNode) {
    Node *p = head;

    if (head == NULL) {
        head = newNode;
        return;
    }

    while ( p->next != NULL) {
        p = p->next;
    }
    p->next = newNode;

}

void insetIntoPos(Node *&head,  Node *newNode, int index) {

    if ( head == NULL) {
        head = newNode;
        return;
    }

    Node *p = head;

    for ( int i = 0 ; i < index - 1; i++) {
        p = p->next;
    }

    newNode->next = p->next;

    p->next = newNode;
}

void deleteHead (Node* &head) {
    Node *p = head;
    head = head->next;
    delete p;
}

void deleteTail(Node *&head) {

    if (head == NULL) {
        cout << "Empty List" << endl;
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node *p = head;

    while ( p->next->next != NULL) {
        p = p->next;
    }
    Node *nodeToDelete = p->next;

    p->next = NULL;

    delete nodeToDelete;
}
void deleteNodeAtIndex( Node* &head, int index) {

    if (head == NULL ) {
        cout << "List is empty" << endl;
        return;
    }

    Node *p = head;
    for ( int i = 0 ; i < index - 1 ; i++) {
        p = p->next;
    }

    Node *nodeToDelete = p->next;

    p->next = nodeToDelete->next;

    delete nodeToDelete;
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
    while ( node != NULL) {
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
    insertTail(head, createNewNode(100));
    insetIntoPos(head, createNewNode(200), 3);
    printList(head);
    countNode(head);

    deleteHead(head);

    cout << "\n ================== " << endl;
    cout << " List after delete head : " << endl ;
    printList(head);

    deleteTail(head);
    cout << "\n ================== " << endl;
    cout << " List after delete tail : " << endl ;
    printList(head);

    deleteNodeAtIndex(head, 2);
    cout << "\n ================== " << endl;
    cout << " List after delete at position : " << endl ;
    printList(head);


    return 0;
}