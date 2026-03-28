//
// Created by jianf on 3/28/2026.
//

#include "PracticeTree1.h"
#include "iostream"
using namespace  std;

struct Node {
    int data;
    Node *right;
    Node *left;
};

Node *createNewNode(int data) {
    Node *newNode = new Node;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
    return newNode;
}

Node * insertNode(Node *root, int data) {
    if (root == NULL) {
        return createNewNode(data);
    }

    if (root->data > data) {
        root->left = insertNode(root->left, data);
    }else if (root->data < data) {
         root->right = insertNode(root->right, data);
    }

    return root;
}
Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node *deleteNode(Node *root, int key) {
    if (root == NULL) return NULL;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {
        // Case 1 & 2: 0 hoặc 1 con
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: 2 con
        Node* temp = findMin(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}
void preOrder(Node *root) {
    if (root == NULL ) return ;

    cout << root->data << " --> ";
    preOrder(root->left);
    preOrder(root->right);
}

void infixOrder(Node *root) {

    if (root == NULL) return;

    infixOrder(root->left);

    cout << root->data << " --> ";

    infixOrder(root->right);

}

int main() {
    Node *root = NULL;

    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 7);
    root = insertNode(root, 3);
    root = insertNode(root, 15);

    cout << "\nInfix Order: " << endl;
    infixOrder(root);
    cout << " \n ---- \n" ;

    cout << "PreOrder: \n" << endl;
    preOrder(root);

    cout << " \n ---- \n" ;

    cout << "After delete\n " << endl;
    deleteNode(root, 10) ;

    cout << "\nInfix Order: " << endl;
    infixOrder(root);
    cout << " \n ---- \n" ;

    cout << "PreOrder: \n" << endl;
    preOrder(root);



    return 1;
}