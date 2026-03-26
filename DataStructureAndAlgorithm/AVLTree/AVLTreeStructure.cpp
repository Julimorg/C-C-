//
// Created by jianf on 3/25/2026.
//

#include "AVLTreeStructure.h"
#include "iostream"

using namespace  std;

struct Node {
    int data;
    Node *right;
    Node *left;
    Node *parent;

    int height;
    int offset;
    int level;
};

Node *createNode(int data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->right = NULL;
    newNode->left = NULL;
    newNode->height = 1;
    newNode->level = 0;
    newNode->offset = 0 ;
    newNode->parent = NULL;
    return newNode;
}

// Height of Node
int height(Node *node) {
    if (node == NULL) return 0;
    return node->height;
}

int max(int a, int b) {
    return ( a > b ) ? a : b;
}

void updateHeight(Node *node) {
    if (node != NULL) {
        node->height = 1 + max(height(node->left), height(node->right));
    }
}

int getBalanceFactor(Node *node) {
    if (node == NULL) return 0;
    return height(node->left) - height(node->right);
}

Node *rightRotation(Node *root) {
    Node * Q = root;
    Node * P = root->left;
    Q->left = P->right;
    P->right = Q;
    return P;
}

Node *leftRotation(Node *root) {
    Node * P = root;
    Node * Q = root->right;
    P->right = Q->left;
    Q->left =  P ;
    return Q;
}
// Cong thuc tinh balance
//  L - R > 1 ( 3 - 1 > 1 ) -> Lech L
// L - R <  1 ( 1 - 3 < -1 ) -> Lech R
Node * balanceTree(Node *root) {
    if (!root) return NULL;

    int balance = getBalanceFactor(root);

    // Lech L
    if (balance > 1) {
        printf("Unbalance at %d Left - ", root->data);

        balance = getBalanceFactor(root->left);

        // Check theo kieu A ( 0 , 0 )
        // neu la 1 chuoi thang trai  C (0,0) - B(1,0) - A ( 2, 0)
        // check toi thang B ma L - R = 1 > 0 thi 100% la LL
        // con nếu bị cong là B ( 0, 1 ) L - R = -1 < 0 thì là LR
        if (balance < 0) {
            // Left-Right Case
            printf("Right");
            root->left = leftRotation(root->left);
        }else if (balance > 0) {
            // LL Case
            printf ("Left\n");
        }
        printf ("\n");
        root = rightRotation(root);
    }
    // Lech R
    else if (balance < -1) {
        printf("Unbalance at %d Right - ", root->data);

        balance = getBalanceFactor(root->right);

        // check RR hay RL thì nhìn thằng trên
        if (balance > 0) {
            // Right-Left case
            printf("Left");
            root->right = rightRotation(root->right);
        } else if (balance < 0) {
            // Right-Right case
            printf("Right\n");
        }
        printf("\n");
        root = leftRotation(root);
    }

    return root;
}

Node *insertNode(Node *root,Node *newNode) {
    if (root == NULL ) {
        return newNode;
    }else if (root->data > newNode->data) {
        root->left = insertNode(root->left, newNode);
    }else if (root->data < newNode->data) {
        root->right = insertNode(root->right , newNode);
    }
    root = balanceTree(root);
    return root;

}

Node *deleteNode(Node *root, int key) {
    if (root == NULL) return NULL;

    if (root->data == key) {

        Node *temp = root;

        if (root->left == NULL) {

            root = root->right;

        }else if ( root->right == NULL) {

            root = root->left;

        }else {
            // Chỗ này tìm inOrder successor
            Node *s = root->right;
            Node *sparent = root;
            while (s->left != NULL) {
                sparent = s;
                s = s->left;
            }
            Node *sright = s->right;
            s->left = root->left;
            if (root->right->data != s->data) {
                s->right = root->right;
            }
            sparent->left = sright;
            root = s;
        }
        delete(temp);
    }else if (root->data > key) {
        root->left = deleteNode(root->left, key);
    }else {
        root->right = deleteNode(root->right, key);
    }

    root = balanceTree(root);
    return root;
}

int getNumLen(int num) {
    int len = 0;
    do {
        len++;
        num /= 10;
    }while (num > 0);
    return len;
}

int getNodeLen(Node *node) {
    if (node == NULL) {
        return 0;
    }else {
        return getNumLen(node->data) + 1;
    }
}

int getRightMostOffSet(Node *root) {
    if (root == NULL) {
        return 0;
    }
    if (root->right == NULL) {
        return root->offset + getNumLen(root->data);
    }
    return getRightMostOffSet(root->right);
}

void updateOffSet(Node *&root, int offset) {
    if (root == NULL) return;

    // cout << " checking " << root->key << " with offset " << offset << endl;

    if (root->left == NULL) {
        root->offset = offset;
        // printf( " !set offset of %d to %d \n", root->key, root->offset);
    }else {
        updateOffSet(root->left, offset);
        root->offset = getRightMostOffSet(root->left) + 2;
        // printf(" Update offset of %d to %d\n", root->key, root->offset);

    }

    updateOffSet(root->right, root->offset + getNodeLen(root) + 1);
}

void printTreeH(Node *root) {
    Node *qu[100];
    int front = 0;
    int rear  = 1;

    qu[0]          = root;
    qu[0]->offset  = 0;
    qu[0]->level   = 0;
    qu[0]->parent  = NULL;

    updateOffSet(root, 0);

    while (front != rear && qu[front] != NULL) {
        if (qu[front]->left != NULL) {
            qu[rear]          = qu[front]->left;
            qu[rear]->parent  = qu[front];
            qu[rear]->level   = qu[front]->level + 1;
            rear++;
        }
        if (qu[front]->right != NULL) {
            qu[rear]          = qu[front]->right;
            qu[rear]->parent  = qu[front];
            qu[rear]->level   = qu[front]->level + 1;
            rear++;
        }
        front++;
    }

    int line_offset = 0;
    for (int i = 0; i < rear; i++) {
        if (i > 0) {
            if (qu[i]->offset > qu[i]->parent->offset) {
                for (; line_offset < qu[i]->parent->offset; line_offset++)
                    printf(" ");
                if (qu[i]->parent->left != NULL) printf("-");
                else                             printf("+");
                line_offset++;
                for (; line_offset < qu[i]->offset; line_offset++)
                    printf("-");
                printf("%d", qu[i]->data);
                line_offset += getNumLen(qu[i]->data);
            }
            if (qu[i]->offset < qu[i]->parent->offset) {
                for (; line_offset < qu[i]->offset; line_offset++)
                    printf(" ");
                printf("%d", qu[i]->data);
                line_offset += getNumLen(qu[i]->data);
                for (; line_offset < qu[i]->parent->offset; line_offset++)
                    printf("-");
                printf("+");
                line_offset++;
            }
        } else {
            for (; line_offset < qu[i]->offset; line_offset++)
                printf(" ");
            printf("%d", qu[i]->data);
        }

        if ((i < rear - 1) && (qu[i]->level != qu[i + 1]->level)) {
            printf("\n");
            line_offset = 0;
        }
    }
    printf("\n\n");
}
Node *insertKeySet(int arr[], int n) {
    Node *root = NULL;
    for (int i = 0; i < n; i++) {
        root = insertNode(root, createNode(arr[i]));
        printf("After insert %d:\n", arr[i]);
        printTreeH(root);
    }
    return root;
}
int main() {
    int keySet1[] = {8, 4, 12, 1, 3, 5, 9, 15, 6, 11, 0, 7, 14, 13};
    Node *mainTree = NULL;
    mainTree = insertKeySet(keySet1, sizeof(keySet1)/sizeof(int));
    mainTree = deleteNode (mainTree, 8);
    printTreeH(mainTree);
    return 1;
}
