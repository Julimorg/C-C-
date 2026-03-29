#include "iostream"
#include "stdlib.h"

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;
};
struct QueueNode {
    Node* data;
    QueueNode* next;
};

struct Queue {
    QueueNode* front;
    QueueNode* rear;
};
void initQueue(Queue *&q){
    q->front = NULL;
    q->rear = NULL;
}

bool isEmpty(Queue *q) {
    return q->front == NULL;
}

Queue* createQueue() {
    Queue* q = new Queue;
    q->front = NULL;
    q->rear  = NULL;
    return q;
}


// Thêm vào cuối
void enqueue(Queue* q, Node* treeNode) {
    QueueNode* newNode = new QueueNode;
    newNode->data = treeNode;
    newNode->next = NULL;

    if (isEmpty(q)) {

        q->front = newNode;
        q->rear  = newNode;
    } else {

        q->rear->next = newNode;
        q->rear       = newNode;
    }
}

// Lấy ra từ đầu
Node* dequeue(Queue* q) {
    if (isEmpty(q)) return NULL;

    QueueNode* temp = q->front;
    Node* treeNode  = temp->data;

    q->front = q->front->next;

    // Nếu sau khi dequeue, queue rỗng → rear cũng phải NULL
    if (q->front == NULL) {
        q->rear = NULL;
    }

    delete temp;
    return treeNode;
}

Node *createNewNode(int data) {
    Node *newNode = new Node;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
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

    if ( root->data < data) {
        root->right = insertNode(root->right, data);
    }else if ( root->data > data) {
        root->left = insertNode(root->left, data);
    }

    return root;
}

Node *deleteNode(Node *root, int data) {
    if (root == NULL ) return NULL;
    if ( root->data > data) {
        root->left = deleteNode(root->left, data);
    }else if ( root->data < data ) {
        root->right = deleteNode(root->right, data);
    }else {
        if ( root->right == NULL) {
            Node *temp = root;
            root = root->left;
            delete(temp);
            return root;
        }else if ( root->left == NULL) {
            Node *temp = root;
            root = root->right;
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
Node* front(Queue* q) {
    if (isEmpty(q)) return NULL;
    return q->front->data;
}

void levelOrder(Node* root) {
    if (root == NULL) return;

    Queue* q = createQueue();
    enqueue(q, root);

    while (!isEmpty(q)) {
        Node* current = dequeue(q);
        cout << current->data << " ";
        if (current->left  != NULL) enqueue(q, current->left);
        if (current->right != NULL) enqueue(q, current->right);
    }

    delete q;
}

int main() {
    Node *root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 15);
    root = insertNode(root, 8);
    root = insertNode(root, 3);

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