//
// Created by jianf on 3/27/2026.
//

#include "PracticeLinkedList.h"
#include "iostream"

using namespace  std;


struct Node {
    int data;
    Node *next;
};

Node *creatNewNode(int data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertHead(Node *&head, Node *newNode) {
    newNode->next = head;
    head = newNode;
}

void insertAtIndex(Node *&head, Node *newNode, int index) {
    if (head == NULL) {
        head = newNode;
        return;
    }

    Node *temp = head;
    for (int i = 0 ; i < index - 1 ; i++ ) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;

}

void insertTail(Node *&head, Node *newNode) {
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(Node *head) {
    if (head == NULL) {
        cout << "Link is empty !" << endl;
    }
    cout << " LinkList: " << endl;
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " --> " ;
        temp = temp->next;
    }

    cout << " NULL " << endl;
}

int main() {
    Node *head = NULL;

    cout << " Insert at Head \n" << endl;
    insertHead(head, creatNewNode(10));
    insertHead(head, creatNewNode(20));
    insertHead(head, creatNewNode(30));
    insertHead(head, creatNewNode(40));

    printList(head);

    cout << " Insert At Tail \n" << endl;
    insertTail(head, creatNewNode(50));
    printList(head);

    cout << " Insert at position \n" << endl;

    insertAtIndex(head, creatNewNode(100), 2);
    printList(head);
}