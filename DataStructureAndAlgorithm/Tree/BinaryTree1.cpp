//
// Created by jianf on 3/18/2026.
//

#include "BinaryTree1.h"
#include "iostream"

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data   = value;
    newNode->left   = nullptr;
    newNode->right  = nullptr;
    return newNode;
}

Node *insertNode(Node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }else if ( data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

Node *findMin(Node *node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}
Node *deleteNode(Node *root, int key) {
    if (root == NULL) return NULL;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }else {

        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp; // Trả về con phải (hoặc nullptr nếu là lá)
        }
        if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp; // Trả về con trái
        }

        Node *successor = findMin(root->right);

        root->data = successor->data;

        root->right = deleteNode(root->right, successor->data);
    }
    return root;
}
void preOrder(Node *root) {
    if (root == NULL) return;

    cout << root->data << " " ;
    preOrder(root->left);
    preOrder(root->right);
}

void infixOrder(Node * root) {
    if ( root == NULL) return;
    infixOrder(root->left);
    cout << root->data << " " ;
    infixOrder(root->right);
}

void postOrder(Node *root) {
    if (root == NULL ) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int getHeight(Node* root) {
    if (!root) return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

void printLevel(Node* root, int level) {
    if (!root) return;

    if (level == 1) {
        cout << root->data << " ";
    } else {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

void levelOrder(Node* root) {
    int h = getHeight(root);

    for (int i = 1; i <= h; i++) {
        printLevel(root, i);
        cout << endl;
    }
}
int main() {
    Node *root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 7);
    root = insertNode(root, 3);
    root = insertNode(root, 15);

    cout << "PreOrder:  " << endl;
    preOrder(root);

    cout << "\nInfixOrder:  " << endl;
    infixOrder(root);

    cout << "\nPostOrder:  " << endl;
    postOrder(root);

    cout << "\nLevelOrder: " << endl;
    levelOrder(root);

    cout << "\n------------------\n";
    cout << "Min of tree: " << findMin(root) << endl;;

    cout << "\nTree after insert : " << " \n";
    root = insertNode(root, 6);

    cout << "PreOrder:  " << endl;
    preOrder(root);

    cout << "\nInfixOrder:  " << endl;
    infixOrder(root);

    cout << "\nPostOrder:  " << endl;
    postOrder(root);
    cout << "\nLevelOrder: " << endl;
    levelOrder(root);

    cout << "\nTree after delete : " << " \n";
    root = deleteNode(root, 10);

    cout << "PreOrder:  " << endl;
    preOrder(root);

    cout << "\nInfixOrder:  " << endl;
    infixOrder(root);

    cout << "\nPostOrder:  " << endl;
    postOrder(root);
    cout << "\nLevelOrder: " << endl;
    levelOrder(root);
    return 0;
}