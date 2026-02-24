//
// Created by acer on 2/2/2026.
//

#include "Tran_Kien_Phong_Practice1_A.h"
#include "iostream"
#include "stdio.h"
#include "stdlib.h"

using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *createNewNode(int data){
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL; // point to empty
    return newNode;
}

void insertToHead(Node* &head, Node* newNode){

    newNode->next = head;
    head = newNode;

}

void insertToTail(Node* &head, Node* newNode){

    if ( head == NULL) {
        head = newNode;
        return;
    }

    Node *p = head;

    // query toan bo tu firstNode den lastNode
    while( p->next != NULL){
        p = p->next;
    }

    p->next = newNode;
}

void insertAt(Node* &head, Node* newNode, int index){
    if ( head == NULL ) {
        head = newNode;
        return;
    }

    Node *p = head;
    Node *q = p;

    int i = 0;

    while( i < index && p->next != NULL){
        i++;
        q = p;
        p = p->next;
    }
    q->next = newNode;
    newNode->next = p;
}

void removeHead(Node* &head){
    if ( head == NULL) return;

    Node *p = head;
    head = head->next;

    free(p);
}

void removeFromTail(Node* &head){
    if ( head == NULL) return;
    Node *p = head;
    while ( p->next != NULL && p->next->next != NULL){
        p = p->next;
    }
    free(p->next);
    p->next = NULL;
}

void removeAt(Node* &head, int index){
    if ( head == NULL) return;
    Node *p = head;
    Node *q = p;
    int i = 0;
    while(i < index && p->next != NULL) {
        i++;
        q = p;
        p = p->next;
    }
    q->next = p->next;
    free(p);
}

void printLastNode(Node *head){
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node *p = head;
    while (p->next != NULL) {
        p = p->next;
    }

    cout << "Last node value: " << p->data << endl;
}

void printIndicesOfValue(Node *head, int x){
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    cout << "Indices of nodes with value " << x << ": ";
    Node *p = head;
    int index = 0;
    bool found = false;

    while (p != NULL) {
        if (p->data == x) {
            cout << index << " ";
            found = true;
        }
        p = p->next;
        index++;
    }

    if (!found) {
        cout << "None found";
    }
    cout << endl;
}

void clearList(Node* &head){
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    cout << "List cleared!" << endl;
}

int countNodesWithValue(Node *head, int x){
    int count = 0;
    Node *p = head;

    while (p != NULL) {
        if (p->data == x) {
            count++;
        }
        p = p->next;
    }

    return count;
}

void printList(Node *head){
    cout << ("List: \n");
    Node *p = head;
    while ( p!= NULL) {
        cout << "Value: " << p->data << endl;
        p = p->next;
    }
    if ( head == NULL) cout << "LinkList is empty!!" << endl;
    cout << endl;
}
int main() {
    Node *head = NULL;

    insertToHead(head, createNewNode(5));
    insertToHead(head, createNewNode(6));
    insertToHead(head, createNewNode(9));
    insertToTail(head, createNewNode(11));
    insertToTail(head, createNewNode(21));
    insertToTail(head, createNewNode(31));
    insertToTail(head, createNewNode(11));
    insertToTail(head, createNewNode(11));
    insertToTail(head, createNewNode(25));
    insertToTail(head, createNewNode(15));
    insertToTail(head, createNewNode(15));
    insertToTail(head, createNewNode(15));

    printList(head);

    cout << endl;

    cout << "insert at position: " << endl;
    insertAt(head, createNewNode(3), 2);
    insertAt(head, createNewNode(10), 1);
    printList(head);

    cout << endl;


    cout << "Remove At Head: " << endl;
    removeHead(head);
    printList(head);

    cout << endl;


    cout << "Remove Tail: " << endl;
    removeFromTail(head);
    printList(head);

    cout << endl;

    cout << "Remove At Position: " << endl;

    removeAt(head, 4);

    printList(head);

    cout << endl;

    cout << "Print Last Node : " << endl;

    printLastNode(head);

    cout << endl;

    cout << "Print Indices Of Node : " << endl;

    printIndicesOfValue(head, 15);

    cout << endl;

    cout << "Count Node : " << endl;

    int count = countNodesWithValue(head, 11);

    cout << "Count of nodes with value 11: " << count << endl;

    printList(head);

    cout << endl;

    cout << "Remove All Nodes : " << endl;

    clearList(head);

    printList(head);


    return 0;
}