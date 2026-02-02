//
// Created by acer on 2/2/2026.
//

#include "Tran_Kien_Phong_Practice1_B.h"
#include "iostream"
#include "stdio.h"
#include "stdlib.h"

using namespace std;

struct Node{
    string viet;
    string eng;

    Node *next;
};

Node *createNewNode(string viet, string eng){
    Node *newNode = new Node;
    newNode->viet = viet;
    newNode->eng = eng;
    newNode->next = NULL;

    return newNode;
}

void insertNodeHead(Node* &head, Node* newNode){

    newNode->next = head;

    head = newNode;

}
void searchKeyNode(Node* &head, string &key){

    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node *p = head;
    bool found = false;
    cout << "keyword:  " << key << endl;

    while( p != NULL) {
        cout << "the value :  " << p->eng << endl;
        if ( key == p->eng){
            cout << "Translated Viet is:  " << p->viet << endl;
            found = true;
            break;
        }
        p = p->next;
    }
    if (!found) {
        cout << "cant find your key !" << endl;
    }
}

void removeKeyWord(Node* &head, string keyword){
    if (head == NULL) return;

    Node* p = head;
    Node* prev = NULL;

    while (p != NULL){
        if (p->eng == keyword){

            if (prev == NULL){
                head = p->next;
            } else {
                prev->next = p->next;
            }
            free (p);
            return;
        }
        prev = p;
        p = p->next;
    }

    cout << "Keyword not found!" << endl;
}



void printList(Node *head){
    cout << ("List: \n");
    Node *p = head;
    while ( p!= NULL) {
        cout << "Viet: " << p->viet << " - Eng: " << p->eng << endl;
        p = p->next;
    }
    if ( head == NULL) cout << "LinkList is empty!!" << endl;
    cout << endl;
}



int main(){

    Node *head = NULL;
    insertNodeHead(head, createNewNode("tao", "apple"));

    insertNodeHead(head, createNewNode("so thu", "zoo"));
    insertNodeHead(head, createNewNode("xin chao", "Hello"));
    insertNodeHead(head, createNewNode("Tam Biet", "Bye"));
    insertNodeHead(head, createNewNode("so ba", "number 3"));

    printList(head);

    cout << endl;

    cout << "Search the Keyword: " ;
    string keyword;
    cin >> keyword;

    searchKeyNode(head, keyword);

    cout << endl;

    cout << "Delete the Keyword: " ;
    removeKeyWord(head, keyword);

    printList(head);

    cout << "Search the Keyword again : " ;
    searchKeyNode(head, keyword);


    return 0;
}