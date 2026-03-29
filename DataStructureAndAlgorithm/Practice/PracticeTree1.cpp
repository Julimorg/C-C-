#include "stdlib.h"
#include "iostream"

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;
};

Node *createNewNode(int data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

Node *findMin(Node *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node *insertNode(Node *root, int data) {
    if ( root == NULL) {
        return createNewNode(data);
    }

    if ( root->data > data) {
        root->left = insertNode(root->left, data);
    }else if ( root->data < data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

Node *deleteNode (Node *root, int data) {
    if (root == NULL) return NULL;

    if (root->data > data) {
        root->left = deleteNode(root->left, data);
    }else if (root->data < data) {
        root->right = deleteNode (root->right , data);
    }else {
        if ( root->right == NULL) {
            Node *temp = root;
            root = root->left;
            delete(temp);
            return root;
        }else if ( root->left == NULL) {
            Node *temp = root;
            root = root->right ;
            delete(temp);
            return root;
        }
        Node *successor = findMin(root->right);
        root->data = successor->data;
        root->right = deleteNode(root->right, successor->data);
    }
    return root;
}

void preOrder(Node *root) {
    if ( root == NULL) return ;
    cout << root->data << " --> ";
    preOrder(root->left);
    preOrder(root->right);
}

void infixOrder(Node *root) {
    if ( root == NULL) return ;
    infixOrder(root->left);
    cout << root->data << " --> ";
    infixOrder(root->right);
}

void postOrder(Node *root) {
    if ( root == NULL) return ;
    infixOrder(root->left);
    infixOrder(root->right);
    cout << root->data << " --> ";
}

int main() {
    Node *root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 20);
    root = insertNode(root, 3);
    root = insertNode(root, 8);
    root = insertNode(root, 15);
    root = insertNode(root, 25);
    root = insertNode(root, 16);

    printf ("\n------\n");

    printf ("Pre Order : \n" );
    preOrder(root);


    printf ("\n------\n");

    printf ("Infix Order : \n" );
    infixOrder(root);


    printf ("\n------\n");

    printf ("Post Order : \n" );
    postOrder(root);


    printf ("\n ---------- DELTE NODE ---------- \n");
    root = deleteNode(root, 10);


    printf ("Pre Order : \n" );
    preOrder(root);


    printf ("\n------\n");

    printf ("Infix Order : \n" );
    infixOrder(root);


    printf ("\n------\n");

    printf ("Post Order : \n" );
    postOrder(root);




}