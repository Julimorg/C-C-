//
// Created by jianf on 3/27/2026.
//

#include "TestStructure.h"
#include "iostream"
#include "stdlib.h"

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;
    Node *parent;

    int offset;
    int level;
};

struct QNode {
    Node *data;
    QNode *next;
};

struct Queue {
    QNode *front;
    QNode *rear;
};

int max(int a, int b) {
    return ( a > b  ) ? a : b;
}



void initQueue (Queue *&q) {
    q->front = NULL;
    q->rear = NULL;
}

Node *findMind(Node *root) {
    if (root == NULL) return NULL;
    while ( root->left != NULL) {
        root = root->left;
    }
    return root;
}

int getHeight (Node *root) {
    if (root == NULL) {
        return -1;
    }
	cout << "================ QUESTION 1 - A" << endl;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

int getBalanace( Node *root) {
    if (root == NULL ) return 0;
    return getHeight(root->left) - getHeight(root->right);
}

Node *rightRotaion(Node *root) {
    Node *Q = root;
    Node *P = root->left;
    Q->left= P->right;
    P->right = Q;
    return P;
}

Node *leftRotation(Node * root) {
    Node *Q = root;
    Node *P = root->right;
    Q->right = P->left;
    P->left= Q;
    return P;
}

Node *balanceTree(Node *root) {
    if (!root)  return NULL;

    int balance = getBalanace(root);

    // Lech L
    if ( balance > 1 ) {

        printf("Unbalance at %d Left - ", root->data);

        int balance = getBalanace(root->left);
        // LR case
        if (balance < 0) {
            printf("Right");
            root->left = leftRotation(root->left);
        }else  if ( balance > 0) {
            printf (" Left");
        }
        // LL case
        printf ("\n");
        root = rightRotaion(root);
    }else if ( balance < -1 ) {

        printf("Unbalance at %d Right - ", root->data);

        int balance = getBalanace(root->right);
        // RL
        if ( balance > 0) {
            printf ("Left");
            root->right = rightRotaion(root->right);
        }
        // RR
        else if ( balance  < 0) {
            printf (" Right ");
        }
        printf ("\n");
        root = leftRotation(root);
    }
    return root;
}

bool isEmpty(Queue  *q) {
    return q->front == NULL;
}
Node *createNewNode(int data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->right = NULL ;
    newNode->left = NULL;
    newNode->level = 0;
    newNode->offset = 0 ;
    newNode->parent = NULL;
    return newNode;
}
void enqueue(Queue *&q, Node *node) {
    QNode *newNode = new QNode;
    newNode->data = node;
    newNode->next = NULL;

    if ( isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    }else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

Node *insertNode(Node *root, Node * newNode) {
    if (root == NULL) {
        return root = newNode;
    }
    if (root->data > newNode->data) {
        root->left = insertNode(root->left, newNode);
    }else if ( root->data < newNode->data) {
        root->right = insertNode(root->right , newNode);
    }
    root = balanceTree(root);

    return root;
}

Node *dequeue(Queue *&q ) {
    if (isEmpty(q)) return NULL;

    QNode *temp = q->front;
    Node* treeNode  = temp->data;

    q->front = temp->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    delete(temp);

    return treeNode;
}

Node *deleteNode (Node *root, int data) {
    if (root == NULL) return NULL;
    if ( root->data < data) {
        root->right = deleteNode(root->right, data);
    }else if ( root->data > data) {
        root->left = deleteNode(root->left , data);
    }else {
        if (root->right == NULL) {
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

        Node *successor = findMind(root->right);

        root->data = successor->data;

        root->right = deleteNode(root->right, successor->data);
    }
    root = balanceTree(root);
    return root;
}
void preOrder(Node *root) {
    if (root == NULL) return ;

    cout << root->data << " --> ";
    preOrder(root->left);
    preOrder(root->right);
}
void infixOrder(Node *root) {
    if (root == NULL) return ;

    infixOrder(root->left);
    cout << root->data << " --> ";
    infixOrder(root->right);
}

void postOrder(Node *root) {
    if (root == NULL) return ;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " --> ";
}


void levelOrder(Node *root) {
    Queue *q = new Queue;
    initQueue(q);

    enqueue(q, root);

    while (!isEmpty(q)) {
        Node *current = dequeue(q);

        cout << current->data << " -->  ";

        if (current->left != NULL) enqueue(q, current->left);
        if ( current->right != NULL) enqueue(q, current->right);
    }
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
        root = insertNode(root, createNewNode(arr[i]));
        printf("After insert %d:\n", arr[i]);
        printTreeH(root);
    }
    return root;
}



// ========================== QUESTION 1 - A ==========================
int sumLeftBranches(Node *root) {
    if ( root == NULL ) return 0;
    int leftSum = sumLeftBranches(root->left);
    int rightSum = sumLeftBranches(root->right);

    if (root->data == leftSum) cout << root->data << " ";

    return leftSum + rightSum + root->data;
}

// ========================== QUESTION 1 - B ==========================

int sumTree(Node *root) {
    if ( root == NULL ) return 0;
    int leftSum = sumTree(root->left);
    int rightSum = sumTree(root->right);

    return leftSum + rightSum + root->data;
}
int countTree(Node *root) {
    if (root == NULL) return 0;
    return 1 + countTree(root->left) + countTree(root->right);
}
void printAvgBothBranches(Node *root) {
    if (root == NULL) return;

    int sum   = sumTree(root->left) + sumTree(root->right);
    int count = countTree(root->left) + countTree(root->right);

    if (count > 0 && root->data * count == sum)
        cout << root->data << " ";

    printAvgBothBranches(root->left);
    printAvgBothBranches(root->right);
}

void checkAvgNode(Node *root, int key) {
    if (root == NULL) return;

    if (key < root->data) {
        checkAvgNode(root->left, key);
    } else if (key > root->data) {
        checkAvgNode(root->right, key);
    } else {
        // Tìm thấy node key=X
        int sum   = sumTree(root->left) + sumTree(root->right);
        int count = countTree(root->left) + countTree(root->right);

        if (count > 0 && root->data * count == sum)
            cout << root->data << " thoa man AVG\n";
        else
            cout << root->data << " KHONG thoa man AVG\n";
    }
}

// ========================== QUESTION 2 ==========================
struct SNode {
    Node *a;
    Node *b;
    SNode *next;
};

struct Stack {
    SNode *top;
};
void initStack (Stack *&s) {
    s = new Stack;
    s->top = NULL;
}
bool isEmptyStack(Stack *s) {
    return s->top == NULL;
}
void push (Stack *&s, Node *a, Node *b) {
    SNode *temp = new SNode;
    temp->a = a;
    temp->b = b;
    temp->next = s->top;
    s->top = temp;
}

void pop(Stack *&s, Node *&a, Node *&b) {
    if (isEmptyStack(s)) return;
    SNode *temp = s->top;
    a = temp->a;
    b = temp->b;
    s->top = temp->next;
    delete temp;
}

// -------------------------------------------------------
// CASE 1: Chỉ check CẤU TRÚC
// -------------------------------------------------------

// Recursive
bool isMirrorStructure(Node *left, Node *right) {
    if (left == NULL && right == NULL) return true;
    if (left == NULL || right == NULL) return false;
    return isMirrorStructure(left->left,  right->right) &&
           isMirrorStructure(left->right, right->left);
}

bool isSymmetricStructure_Recursive(Node *root) {
    if (root == NULL) return true;
    return isMirrorStructure(root->left, root->right);
}

// Stack
bool isSymmetricStructure_Stack(Node *root) {
    if (root == NULL) return true;

    Stack *s;
    initStack(s);
    push(s, root->left, root->right);

    while (!isEmptyStack(s)) {
        Node *L, *R;
        pop(s, L, R);

        if (L == NULL && R == NULL) continue;
        if (L == NULL || R == NULL) return false;

        push(s, L->left,  R->right);
        push(s, L->right, R->left);
    }
    return true;
}

// -------------------------------------------------------
// CASE 2: Check CẤU TRÚC + GIÁ TRỊ
// -------------------------------------------------------

// Recursive
bool isMirrorFull(Node *left, Node *right) {
    if (left == NULL && right == NULL) return true;
    if (left == NULL || right == NULL) return false;
    return (left->data == right->data) &&
           isMirrorFull(left->left,  right->right) &&
           isMirrorFull(left->right, right->left);
}

bool isSymmetricFull_Recursive(Node *root) {
    if (root == NULL) return true;
    return isMirrorFull(root->left, root->right);
}

// Stack
bool isSymmetricFull_Stack(Node *root) {
    if (root == NULL) return true;

    Stack *s;
    initStack(s);
    push(s, root->left, root->right);

    while (!isEmptyStack(s)) {
        Node *L, *R;
        pop(s, L, R);

        if (L == NULL && R == NULL) continue;
        if (L == NULL || R == NULL) return false;
        if (L->data != R->data)     return false; // <-- thêm check giá trị

        push(s, L->left,  R->right);
        push(s, L->right, R->left);
    }
    return true;
}

int main() {
    int keySet1[] = {8,1,9,2,3,6,5,4};
    int keySet2[] = {10,5, 3,8, 15,11,16};

    Node *root = NULL;
    Node *root2= NULL;
    root = insertKeySet(keySet1, sizeof(keySet1)/sizeof(int));
    root2 = insertKeySet(keySet2, sizeof(keySet2)/sizeof(int));
    printTreeH(root);
    printTreeH(root2);

    printf ("\n---------\n");
    printf ("PreOrder : ");
    preOrder(root);


    printf ("\n---------\n");
    printf ("InfixOrder : ");
    infixOrder(root);

    printf ("\n---------\n");
    printf ("PostOrder : ");
    postOrder(root);

    printf ("\n---------\n");
    printf ("Level Order : ");
    levelOrder(root);

    printf ("\n---------\n");
    cout << "Sum at left branches: " << sumLeftBranches(root->left);

    printf ("\n---------\n");
    cout << "Sum at right branches: " << sumLeftBranches(root->right);

    printf ("\n---------\n");
    cout << "Sum at all branches: " << sumTree(root);


    printf ("\n---------\n");

    cout << " Avg Value : ";
    printAvgBothBranches(root);

    printf("\n========== QUESTION 2 ==========\n");
    printf("  [Structure only - Recursive]    : %s\n", isSymmetricStructure_Recursive(root2) ? "YES" : "NO");
    printf("  [Structure only - Stack]        : %s\n", isSymmetricStructure_Stack(root2)     ? "YES" : "NO");
    printf("  [Structure + Value - Recursive] : %s\n", isSymmetricFull_Recursive(root2)      ? "YES" : "NO");
    printf("  [Structure + Value - Stack]     : %s\n", isSymmetricFull_Stack(root2 )           ? "YES" : "NO");

    printf ("\n-------- DELETE NODE -------\n" );
    root =  deleteNode(root, 10);
    printf ("\n---------\n");
    printf ("PreOrder : ");
    preOrder(root);


    printf ("\n---------\n");
    printf ("InfixOrder : ");
    infixOrder(root);

    printf ("\n---------\n");
    printf ("PostOrder : ");
    postOrder(root);






    return 0;
}