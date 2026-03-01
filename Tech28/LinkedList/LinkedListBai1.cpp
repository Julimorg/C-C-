//
// Created by jianf on 2/28/2026.
//

#include "LinkedListBai1.h"
#include "iostream"
#include <iomanip>
#include <string>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    string mssv;
    string name;
    float gpa;
    Node *next;
};

int getSize(Node* head) {
    int cnt = 0;
    while (head != NULL) {
        cnt++;
        head = head->next;
    }
    return cnt;
}

Node *createNewNode(string mssv, string name, float gpa) {
    Node *newNode = new Node;
    newNode->mssv = mssv;
    newNode->name = name;
    newNode->gpa = gpa;
    newNode->next = NULL;
    return newNode;
}

void insertHead(Node* &head, Node *newNode) {
    newNode->next = head;
    head = newNode;
}

void insertTail(Node* &head, Node *newNode) {
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node *p = head;

    while (p->next != NULL) {
        p = p->next;
    }
    p->next = newNode;
}

void insertIntoPos(Node* &head, Node *newNode, int index) {
    Node *p = head;

    int size = getSize(head);

    if (index <= 1) {
        insertHead(head, newNode);
        return;
    }

    if (index > size) {
        insertTail(head, newNode);
        return;
    }

    if ( head == NULL) {
        cout << "Empty" ;
    }

    for ( int i = 1; i < index - 1; i++) {
        p = p->next;
    }
    newNode->next = p->next;
    p->next = newNode;
}

void printList(Node* head) {
    Node *p = head;
    while ( p != NULL) {
        cout << p->mssv << " "
             << p->name << " "
             << fixed << setprecision(2)
             << p->gpa << endl;
        p = p->next;

    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    Node* head = NULL;

    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;

        int k = 0;
        if (type == 3) {
            cin >> k;
        }

        string mssv;
        string name;
        float gpa;

        cin.ignore();
        getline(cin, mssv);
        getline(cin, name);
        cin >> gpa;


        if (type == 1) {
            insertHead(head, createNewNode(mssv,name,gpa));
        }
        else if (type == 2) {
            insertTail(head,  createNewNode(mssv,name,gpa));
        }
        else {
            insertIntoPos(head,  createNewNode(mssv,name,gpa), k);
        }
    }

    printList(head);

    return 0;
}