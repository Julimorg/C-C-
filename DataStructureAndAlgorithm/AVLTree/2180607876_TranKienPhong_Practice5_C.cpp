
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
    Node *newNode   = new Node;
    newNode->key    = key;
    newNode->right  = NULL;
    newNode->left   = NULL;
    newNode->level  = 0;
    newNode->offset = 0;
    newNode->parent = NULL;
    return newNode;
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

Node *balanceTree(Node *root) {
    if (!root) return NULL;
    int balance = getBalance(root);
    if (balance > 1) {
        if (getBalance(root->left) < 0)
            root->left = leftRotation(root->left);
        root = rightRotation(root);
    } else if (balance < -1) {
        if (getBalance(root->right) > 0)
            root->right = rightRotation(root->right);
        root = leftRotation(root);
    }
    return root;
}

Node *insert(Node *root, Node *newNode) {
    if (root == NULL)            return newNode;
    if (root->key > newNode->key)
        root->left  = insert(root->left,  newNode);
    else
        root->right = insert(root->right, newNode);
    return balanceTree(root);
}


int countNodes(Node *root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}


void inorder(Node *root, int arr[], int &idx) {
    if (root == NULL) return;
    inorder(root->left,  arr, idx);
    arr[idx++] = root->key;
    inorder(root->right, arr, idx);
}


Node *buildBalancedBST(int arr[], int lo, int hi) {
    if (lo > hi) return NULL;

    int mid    = lo + (hi - lo) / 2;
    Node *root = createNode(arr[mid]);

    root->left  = buildBalancedBST(arr, lo,      mid - 1);
    root->right = buildBalancedBST(arr, mid + 1, hi);

    return root;
}


void splitByCount(Node *root, int count, Node *&treeA, Node *&treeB) {
    int n = countNodes(root);

    if (count <= 0) {
        printf("Count must be > 0\n");
        treeA = NULL;
        treeB = root;
        return;
    }
    if (count >= n) {
        printf("Count >= total nodes (%d). Tree B will be empty.\n", n);
        treeA = root;
        treeB = NULL;
        return;
    }


    int *arr = new int[n];
    int idx  = 0;
    inorder(root, arr, idx);

    // Debug: in ra sorted array
    printf("Sorted keys: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    printf("Split at index %d: A=[0..%d], B=[%d..%d]\n",
           count, count-1, count, n-1);

    treeA = buildBalancedBST(arr, 0,     count - 1);
    treeB = buildBalancedBST(arr, count, n - 1);

    delete[] arr;
}

int getNumLen(int num) {
    int len = 0;
    do { len++; num /= 10; } while (num > 0);
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
    qu[0] = root; qu[0]->offset = 0; qu[0]->level = 0; qu[0]->parent = NULL;

    updateOffset(root, 0);

    while (front != rear && qu[front] != NULL) {
        if (qu[front]->left) {
            qu[rear] = qu[front]->left;
            qu[rear]->parent = qu[front];
            qu[rear]->level  = qu[front]->level + 1;
            rear++;
        }
        if (qu[front]->right) {
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
                printf(qu[i]->parent->left ? "-" : "+");
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

    printf("=== Original tree (%d nodes) ===\n", countNodes(mainTree));
    printTreeH(mainTree);


    Node *treeA = NULL;
    Node *treeB = NULL;
    int splitCount = 3;

    printf("=== Split by count = %d ===\n", splitCount);
    splitByCount(mainTree, splitCount, treeA, treeB);

    printf("\nTree A (%d nodes):\n", countNodes(treeA));
    printTreeH(treeA);

    printf("Tree B (%d nodes):\n", countNodes(treeB));
    printTreeH(treeB);

    return 0;
}