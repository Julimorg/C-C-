//
// Created by jianf on 3/18/2026.
//

#include "2180607876_TranKienPhong_Practice4_A.h"
#include "iostream"
#include "stdlib.h"

#define _OFFSET_ 4

using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
};
struct QNode {
    Node* data;
    QNode* next;
};

struct Queue {
    QNode* front;
    QNode* rear;
};

void initQueue(Queue &q) {
    q.front = q.rear = NULL;
}

bool isEmpty(Queue q) {
    return q.front == NULL;
}

void enqueue(Queue &q, Node* x) {
    QNode* temp = new QNode;
    temp->data = x;
    temp->next = NULL;

    if (q.rear == NULL) {
        q.front = q.rear = temp;
        return;
    }

    q.rear->next = temp;
    q.rear = temp;
}

Node* dequeue(Queue &q) {
    if (isEmpty(q)) return NULL;

    QNode* temp = q.front;
    Node* result = temp->data;

    q.front = q.front->next;
    if (q.front == NULL)
        q.rear = NULL;

    delete temp;
    return result;
}
Node *createNode(int key) {
    Node *node = new Node;
    node->key = key;
    node->right = NULL;
    node->left = NULL;

    return node;
}

Node *insert(Node *root, Node *newNode) {
    if (root == NULL) {
        root = newNode;
    }else if (root->key > newNode ->key) {
        root->left = insert(root->left, newNode);
    }else if (root->key < newNode->key) {
        root->right = insert(root->right, newNode);
    }
    return root;
}

Node *search(Node *root, int key) {
    if (root == NULL) return NULL;

    if (root->key == key) return root;
    else if (root->key > key) return search(root->left, key);
    else return search(root->right, key);
}

void inOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    int vl = root->left != NULL ? root->left->key : -1;
    int vr = root->right != NULL ? root->right->key : -1;

    cout << root->key << " - " << vl << " - " << vr << endl;
    inOrder(root->right);
}
void preOrder(Node *root) {
    if (root == NULL) return;
    int vl = root->left != NULL ? root->left->key : -1;
    int vr = root->right != NULL ? root->right->key : -1;
    cout << root->key << " - " << vl << " - " << vr << endl;
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root) {
    if (root == NULL ) return;
    postOrder(root->left);
    postOrder(root->right);
    int vl = root->left != NULL ? root->left->key : -1;
    int vr = root->right != NULL ? root->right->key : -1;
    cout << root->key << " - " << vl << " - " << vr << endl;
}
void printBFS(Node* root) {
    if (root == NULL) return;

    Queue q;
    initQueue(q);

    enqueue(q, root);

    while (!isEmpty(q)) {
        Node* curr = dequeue(q);

        int vl = curr->left ? curr->left->key : -1;
        int vr = curr->right ? curr->right->key : -1;

        cout << curr->key << " - " << vl << " - " << vr << endl;

        if (curr->left) enqueue(q, curr->left);
        if (curr->right) enqueue(q, curr->right);
    }
}
Node *deleteNode(Node *root, int key) {
    if (root == NULL) return NULL;
    if (root->key == key) {
        Node *temp = root;
        if (root->left == NULL) root = root->right;
        else if (root->right == NULL) root = root->left;
        else {
            Node *smallest = root->right;
            Node *sparent = root;
            while (smallest->left != NULL) {
                sparent = smallest;
                smallest = smallest->left;
            }
            Node *sright = smallest->right;
            smallest->left = root->left;
            if (root->right->key != smallest->key) {
                smallest->right = root->right;
            }
            sparent->left = sright;
            root = smallest;
        }
        delete temp;
    }else if (root->key > key) {
        root->left = deleteNode(root->left,key);
    }else if (root->key < key) {
        root->right = deleteNode(root->right, key);
    }
    return root;
}

void print2D(Node* root, int space = 0, int indent = 6) {
    if (root == NULL) return;

    space += indent;

    print2D(root->right, space);

    cout << endl;
    for (int i = indent; i < space; i++) cout << " ";
    cout << root->key << endl;


    print2D(root->left, space);
}
int main() {
    int keySet1[] = {8,4,12,1,3,5,9,15,6,11};
    int n = 10;
    Node *root = NULL;
    for ( int i = 0 ; i < n ;i++ ) {
        root = insert(root, createNode(keySet1[i]));
    }
    cout << "InOrder:  " << endl;
    inOrder(root);
    cout << " --- "  << endl;
    cout << "\npreOrder:  " << endl;
    preOrder(root);
    cout << " --- " << endl;
    cout << "\npostOrder:  " << endl;
    postOrder(root);
    cout << " --- "  << endl;

    root = deleteNode(root,1);
    cout << "\n -- Tree after delete : " << endl;
    cout << "InOrder:  " << endl;
    inOrder(root);
    cout << " --- "  << endl;
    cout << "\npreOrder:  " << endl;
    preOrder(root);
    cout << " --- " << endl;
    cout << "\npostOrder:  " << endl;
    postOrder(root);
    cout << " --- "  << endl;


    root = deleteNode(root,8);
    cout << "\n -- Tree after delete : " << endl;
    cout << "InOrder:  " << endl;
    inOrder(root);
    cout << " --- "  << endl;
    cout << "\npreOrder:  " << endl;
    preOrder(root);
    cout << " --- " << endl;
    cout << "\npostOrder:  " << endl;
    postOrder(root);
    cout << " --- "  << endl;



    printBFS(root);
    print2D(root);
    return 0;
}