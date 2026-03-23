//
// Created by jianf on 3/23/2026.
//

#include "iostream"
#include "stdio.h"

using namespace std;

struct Node {
    int key;
    Node *right;
    Node *left;
    Node *parent;
    int offset;
    int level;
};


Node *createNode(int key) {
    Node *newNode  = new Node;
    newNode->key    = key;
    newNode->right  = NULL;
    newNode->left   = NULL;
    newNode->level  = 0;
    newNode->offset = 0;
    newNode->parent = NULL;
    return newNode;
}

Node *search(Node *root, int key) {
    if (root == NULL) return NULL;
    if (root->key == key) {

        return root;

    }else if (root->key > key) {

        return search(root->left , key);

    }else {

        return search(root->right, key);

    }
}

int myMax(int a, int b) { return (a > b) ? a : b; }

int getHeight(Node *root) {
    if (root == NULL) return -1;
    return 1 + myMax(getHeight(root->left), getHeight(root->right));
}

int getBalance(Node *root) {
    if (root == NULL) return 0;
    return getHeight(root->left) - getHeight(root->right);
}


Node *rightRotation(Node *root) {
    Node *Q  = root;
    Node *P  = root->left;
    Q->left  = P->right;
    P->right = Q;
    return P;
}

Node *leftRotation(Node *root) {
    Node *P  = root;
    Node *Q  = root->right;
    P->right = Q->left;
    Q->left  = P;
    return Q;
}


Node * balanceTree(Node *root) {
    if (!root) return NULL;

    int balance = getBalance(root);

    // Lech L
    if (balance > 1) {
        printf("Unbalance at %d Left - ", root->key);

        balance = getBalance(root->left);

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
        //TODO
        //Question 1: based on the code to handle the case of unbalance Left-Left/Right
        //Please implement the code to handle the case of unbalance Right-Left/Right here
        printf("Unbalance at %d Right - ", root->key);

        balance = getBalance(root->right);

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


Node *rebuildBalance(Node *root) {
    if (root == NULL) return NULL;
    root->left  = rebuildBalance(root->left);
    root->right = rebuildBalance(root->right);
    root = balanceTree(root);
    return root;
}


Node *insert(Node *root, Node *newNode) {
    if (root == NULL) {
        root = newNode;
    }else if (root->key > newNode->key) {
        root->left = insert(root->left, newNode);
    }else {
        root->right = insert(root->right, newNode);
    }

    //TODO:
    //Question 20: Modify the code of this function to assure that the tree would always be balance
    root = balanceTree(root);
    return root;
}



Node *deleteNode(Node *root, int key) {
    if (root == NULL) return NULL;

    if (root->key == key) {
        if (root->left == NULL) {
            Node *temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == NULL) {
            Node *temp = root;
            root = root->left;
            delete temp;
        } else {
            Node *s = root->right;
            while (s->left != NULL) s = s->left;
            root->key   = s->key;
            root->right = deleteNode(root->right, s->key);

        }
    } else if (root->key > key) {
        root->left  = deleteNode(root->left,  key);
    } else {
        root->right = deleteNode(root->right, key);
    }

    return balanceTree(root);
}
// Dau tien la search toi Key can tim
// xong tach ra 1 cho subtree L, 1 cho subtree Phai
void splitTree(Node *root, int key, Node *&treeA, Node *&treeB) {
    // Bước 1: Tìm node
    Node *target = search(root, key);

    if (target == NULL) {
        printf("Key %d not found in tree!\n", key);
        treeA = NULL;
        treeB = NULL;
        return;
    }


    treeA = target->left;
    treeB = target->right;


    target->left  = NULL;
    target->right = NULL;
    delete target;

    treeA = rebuildBalance(treeA);
    treeB = rebuildBalance(treeB);
}


int getNumLen(int num) {
    int len = 0;
    do {
        len++;
        num /= 10;
    } while (num > 0);
    return len;
}

int getNodeLen(Node *node) {
    return (node == NULL) ? 0 : getNumLen(node->key) + 1;
}

int getRightMostOffset(Node *root) {
    if (root == NULL)        return 0;
    if (root->right == NULL) return root->offset + getNumLen(root->key);
    return getRightMostOffset(root->right);
}

void updateOffset(Node *&root, int offset) {
    if (root == NULL) return;
    if (root->left == NULL) {
        root->offset = offset;
    } else {
        updateOffset(root->left, offset);
        root->offset = getRightMostOffset(root->left) + 2;
    }
    updateOffset(root->right, root->offset + getNodeLen(root) + 1);
}

void printTreeH(Node *root) {
    if (root == NULL) { printf("(empty tree)\n\n"); return; }

    Node *qu[100];
    int front = 0, rear = 1;

    qu[0] = root;
    qu[0]->offset = 0;
    qu[0]->level  = 0;
    qu[0]->parent = NULL;

    updateOffset(root, 0);

    while (front != rear && qu[front] != NULL) {
        if (qu[front]->left != NULL) {
            qu[rear] = qu[front]->left;
            qu[rear]->parent = qu[front];
            qu[rear]->level  = qu[front]->level + 1;
            rear++;
        }
        if (qu[front]->right != NULL) {
            qu[rear] = qu[front]->right;
            qu[rear]->parent = qu[front];
            qu[rear]->level  = qu[front]->level + 1;
            rear++;
        }
        front++;
    }

    int line_offset = 0;
    for (int i = 0; i < rear; i++) {
        if (i > 0) {
            if (qu[i]->offset > qu[i]->parent->offset) {
                for (; line_offset < qu[i]->parent->offset; line_offset++) printf(" ");
                printf(qu[i]->parent->left != NULL ? "-" : "+");
                line_offset++;
                for (; line_offset < qu[i]->offset; line_offset++) printf("-");
                printf("%d", qu[i]->key);
                line_offset += getNumLen(qu[i]->key);
            }
            if (qu[i]->offset < qu[i]->parent->offset) {
                for (; line_offset < qu[i]->offset; line_offset++) printf(" ");
                printf("%d", qu[i]->key);
                line_offset += getNumLen(qu[i]->key);
                for (; line_offset < qu[i]->parent->offset; line_offset++) printf("-");
                printf("+");
                line_offset++;
            }
        } else {
            for (; line_offset < qu[i]->offset; line_offset++) printf(" ");
            printf("%d", qu[i]->key);
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
    for (int i = 0; i < n; i++)
        root = insert(root, createNode(arr[i]));
    return root;
}


int main() {
    int keySet1[] = {8, 4, 12, 1, 3, 5, 9, 15, 6, 11, 0, 7, 14, 13};
    int n = sizeof(keySet1) / sizeof(int);

    Node *mainTree = insertKeySet(keySet1, n);

    printf("=== Original tree ===\n");
    printTreeH(mainTree);

    // Split tại key = 9
    Node *treeA = NULL;
    Node *treeB = NULL;

    splitTree(mainTree, 4, treeA, treeB);

    printf("Tree A (keys < 9):\n");
    printTreeH(treeA);

    printf("Tree B (keys > 9):\n");
    printTreeH(treeB);

    return 0;
}