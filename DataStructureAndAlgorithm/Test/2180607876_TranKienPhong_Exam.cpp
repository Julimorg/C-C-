//
// Created by jianf on 3/30/2026.
//

#include "2180607876_TranKienPhong_Exam.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
struct _node
{
    int key;
    struct _node* left, * right, *parent;
    //variables that support tree drawing, should not remove them
    int offset;
    int level;
};

typedef struct _node Node;

void printTreeH(Node * root);
Node* balanceTree(Node* root);
Node* mainTree = NULL;
Node* mainTree2 = NULL;

Node* createNode(int key)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->level = 0;
    node->offset = 0;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

//AVL
int max(int a, int b)
{
	return (a > b) ? a : b;
}

int gh(Node* root)
{
	if (root == NULL) return -1;
	return 1 + max(gh(root->left), gh(root->right));
}
Node *findMind(Node *root) {
	if (root == NULL) return NULL;
	while ( root->left != NULL) {
		root = root->left;
	}
	return root;
}
int getBalance(Node* root)
{
	if (root == NULL)
		return 0;

	return gh(root->left) - gh(root->right);
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

Node* balanceTree(Node* root)
{
	if (!root)  return NULL;

	int balance = getBalance(root);

	// Lech L
	if ( balance > 1 ) {

		printf("Unbalance at %d Left - ", root->key);

		int balance = getBalance(root->left);
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

		printf("Unbalance at %d Right - ", root->key);

		int balance = getBalance(root->right);
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
Node *findMindBST(Node *root) {
	if (root == NULL) return NULL;
	while ( root->left != NULL) {
		root = root->left;
	}
	return root;
}

Node* insert(Node *root, Node * newNode) {
	if (root == NULL) {
		return root = newNode;
	}
	if (root->key > newNode->key) {
		root->left = insert(root->left, newNode);
	}else if ( root->key < newNode->key) {
		root->right = insert(root->right , newNode);
	}
	root = balanceTree(root);

	return root;
}

Node* deleteNode(Node* root, int key)
{
	if (root == NULL) return NULL;
	if ( root->key < key) {
		root->right = deleteNode(root->right, key);
	}else if ( root->key > key) {
		root->left = deleteNode(root->left , key);
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

		root->key = successor->key;

		root->right = deleteNode(root->right, successor->key);
	}
	root = balanceTree(root);
	return root;
}



//-----start of print functions - should not touch this code
int getNumLen(int num)
{
	int len = 0;
	int t= num;

	do
	{
		len++;
		num /= 10;
	}while (num > 0);

	return len;
}

int getRightMostOffset(Node *root)
{
	if (root == NULL)
		return 0;
	if (root->right == NULL)
		return root->offset + getNumLen(root->key);
	return getRightMostOffset(root->right);
}

int getNodeLen(Node *node)
{
	if (node == NULL)
		return 0;
	else
		return getNumLen(node->key) + 1;
}

void updateOffset(Node *&root, int offset)
{
	if (root == NULL)
		return;

	// printf("checking %d with offset %d \n", root->key, offset);

	if (root->left == NULL)
	{
		root->offset = offset;
		// printf("  !set offset of %d to %d\n", root->key, root->offset);
	}
	else
	{
		updateOffset(root->left, offset);

		root->offset = getRightMostOffset(root->left) + 2;
		// printf("  -update offset of %d to %d\n", root->key, root->offset);
	}

	updateOffset(root->right, root->offset + getNodeLen(root) + 1);
}

void printTreeH(Node * root)
{
	if (root == NULL) return;

	Node* qu[100];
	int front = 0;
	int rear = 1;
	qu[0] = root;
	qu[0]->offset = 0;
	qu[0]->level = 0;
	qu[0]->parent = NULL;
	updateOffset(root, 0);
	while (front != rear && qu[front]!=NULL)
	{
		// printf("checking front = %d at %d", qu[front]->key, qu[front]->offset);

		if (qu[front]->left != NULL)
		{

			qu[rear] = qu[front]->left;
			qu[rear]->parent = qu[front];
			qu[rear]->level = qu[front]->level + 1;
			rear++;
		}
		if (qu[front]->right != NULL)
		{
			qu[rear] = qu[front]->right;
			qu[rear]->parent = qu[front];
			qu[rear]->level = qu[front]->level + 1;
			rear++;
		}
//		printf("\n");
		front++;
	}
	int line_offset = 0;
	for (int i = 0; i < rear; i++)
	{
		if (i > 0)
		{
			//left child
			if (qu[i]->offset < qu[i]->parent->offset)
			{
				for (;line_offset < qu[i]->offset; line_offset++)
					printf(" ");

				printf("%d", qu[i]->key);
				line_offset += getNumLen(qu[i]->key);
				for (;line_offset < qu[i]->parent->offset;line_offset++)
					printf("-");
				printf("+");
				line_offset++;
			}
			//right child
			if (qu[i]->offset > qu[i]->parent->offset)
			{
				for (;line_offset < qu[i]->parent->offset;line_offset++)
					printf(" ");
				if(qu[i]->parent->left != NULL)
					printf("-");
				else printf("+");

				line_offset++;
				for (;line_offset < qu[i]->offset;line_offset++)
					printf("-");
				printf("%d", qu[i]->key);
				line_offset += getNumLen(qu[i]->key);
			}
		}
		else
		{
			for (;line_offset < qu[i]->offset;line_offset++)
				printf(" ");
			printf("%d", qu[i]->key);
		}

		if ((i < rear - 1) &&(qu[i]->level != qu[i+1]->level))
		{
			printf("\n");
			line_offset = 0;
		}
	}
	printf("\n\n");
}
//-------end of print functions-----------

Node * insertKeySet(int arr[], int n)
{
	Node * root = NULL;
	for (int i = 0; i < n; i++)
	{
		root = insert(root, createNode(arr[i]));
		printTreeH(root);
		// system("pause");
	}

	return root;
}

// ================ QUESTION 1 - A

int sumLeftBranches(Node *root) {
	if ( root == NULL) return 0;
	int leftSum = sumLeftBranches(root->left);
	int rightSum = sumLeftBranches(root->right);
	cout << root->key << " - the key " << endl;
	return leftSum + rightSum + root->key;
}

int sumBranchesByPositionNode(Node *root) {
	if ( root == NULL) return 0;
	int leftSum = sumLeftBranches(root->left);
	int rightSum = sumLeftBranches(root->right);
	cout << root->key << " - the key " << endl;
	return leftSum + rightSum + root->key;
}
int CountNodes(Node* root)
{
	if (root == nullptr) {
		return 0;
	}

	return 1 + CountNodes(root->left) + CountNodes(root->right);
}

void postOrder(Node *root) {
	if ( root == NULL )  return ;
	int count = 0;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->key << " --> ";

	count++;
	cout << " count : " << count  << endl;
}
// ================ QUESTION 1 - B
Node *calcAvgNode(Node *root, int key) {
	if ( root == NULL) return NULL;
	if ( root->key < key) {
		root->right = calcAvgNode(root->right, key);
	}else if ( root->key > key) {
		root->left = calcAvgNode(root->left, key);
	}else {
		postOrder(root);


		int sumRight = sumBranchesByPositionNode(root->right);
		int sumLeft = sumBranchesByPositionNode(root->left);
		int sum = sumRight + sumLeft;

		int countLeft = CountNodes(root->left);
		int countRight = CountNodes(root->right);
		int count = countLeft + countRight;

		cout << "SUm in branches: " << sum << endl;
		cout << "Count in branches: " << count << endl;

		float avg = sum / 2;

		cout << " The Avg of the node is : " << avg << endl;

	}
	return root;
}

// =================== QUESTION 2 - STACK

struct SNode {
	Node *data[100];
	int top;
};

void initStack(SNode *&s) {
	s->top = -1;
}

bool isEmptyStack(SNode *s) {
	return s->top == -1;
}

void pushNS(SNode *&s, Node* node) {
	s->data[++s->top] = node;
}

Node* popNS(SNode *&s) {
	if (isEmptyStack(s)) return NULL;
	return s->data[s->top--];
}
bool checkIsSymmetricalTree(Node *root) {
	if (root == NULL) return true;

	SNode *sLeft = new SNode;
	SNode *sRight = new SNode;
	initStack(sLeft);
	initStack(sRight);

	pushNS(sLeft,  root->left);
	pushNS(sRight, root->right);

	while (!isEmptyStack(sLeft) && !isEmptyStack(sRight)) {
		Node* l = popNS(sLeft);
		Node* r = popNS(sRight);

		if (l == NULL && r == NULL) continue;


		if (l == NULL || r == NULL) return false;

		pushNS(sLeft, l->right);
		pushNS(sLeft, l->left);

		pushNS(sRight, r->left);
		pushNS(sRight, r->right);
	}

	return isEmptyStack(sLeft) && isEmptyStack(sRight);
}

// ===== BST

Node *insertNode(Node *root, Node * newNode) {
	if (root == NULL) {
		return root = newNode;
	}
	if (root->key > newNode->key) {
		root->left = insertNode(root->left, newNode);
	}else if ( root->key < newNode->key) {
		root->right = insertNode(root->right , newNode);
	}
	return root;
}

Node* deleteNodeBST(Node* root, int key)
{
	if (root == NULL) return NULL;
	if ( root->key < key) {
		root->right = deleteNodeBST(root->right, key);
	}else if ( root->key > key) {
		root->left = deleteNodeBST(root->left , key);
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

		Node *successor = findMindBST(root->right);

		root->key = successor->key;

		root->right = deleteNodeBST(root->right, successor->key);
	}
	return root;
}


void printTreeHBST(Node * root)
{
	if (root == NULL) return;

	Node* qu[100];
	int front = 0;
	int rear = 1;
	qu[0] = root;
	qu[0]->offset = 0;
	qu[0]->level = 0;
	qu[0]->parent = NULL;
	updateOffset(root, 0);
	while (front != rear && qu[front]!=NULL)
	{
		// printf("checking front = %d at %d", qu[front]->key, qu[front]->offset);

		if (qu[front]->left != NULL)
		{

			qu[rear] = qu[front]->left;
			qu[rear]->parent = qu[front];
			qu[rear]->level = qu[front]->level + 1;
			rear++;
		}
		if (qu[front]->right != NULL)
		{
			qu[rear] = qu[front]->right;
			qu[rear]->parent = qu[front];
			qu[rear]->level = qu[front]->level + 1;
			rear++;
		}
		//		printf("\n");
		front++;
	}
	int line_offset = 0;
	for (int i = 0; i < rear; i++)
	{
		if (i > 0)
		{
			//left child
			if (qu[i]->offset < qu[i]->parent->offset)
			{
				for (;line_offset < qu[i]->offset; line_offset++)
					printf(" ");

				printf("%d", qu[i]->key);
				line_offset += getNumLen(qu[i]->key);
				for (;line_offset < qu[i]->parent->offset;line_offset++)
					printf("-");
				printf("+");
				line_offset++;
			}
			//right child
			if (qu[i]->offset > qu[i]->parent->offset)
			{
				for (;line_offset < qu[i]->parent->offset;line_offset++)
					printf(" ");
				if(qu[i]->parent->left != NULL)
					printf("-");
				else printf("+");

				line_offset++;
				for (;line_offset < qu[i]->offset;line_offset++)
					printf("-");
				printf("%d", qu[i]->key);
				line_offset += getNumLen(qu[i]->key);
			}
		}
		else
		{
			for (;line_offset < qu[i]->offset;line_offset++)
				printf(" ");
			printf("%d", qu[i]->key);
		}

		if ((i < rear - 1) &&(qu[i]->level != qu[i+1]->level))
		{
			printf("\n");
			line_offset = 0;
		}
	}
	printf("\n\n");
}
Node * insertKeySetBST(int arr[], int n)
{
	Node * root = NULL;
	for (int i = 0; i < n; i++)
	{
		root = insertNode(root, createNode(arr[i]));
		printTreeHBST(root);
		// system("pause");
	}

	return root;
}
int main()
{
	int keySet1[] = {7, 8, 9, 1, 2, 3, 6, 5, 4 };
	int keySet10[] = {7, 8, 9, 1, 2, 3, 6, 5, 4 };

	// int keySet2[] = {10, 5, 15, 4, 8, 13, 20, 11, 14, 7, 6 };
	// int keySet3[] = {20, 10, 35, 5, 15, 30, 40 };

	mainTree = insertKeySet(keySet1, sizeof(keySet1	)/sizeof(int));
	mainTree2 = insertKeySetBST(keySet1, sizeof(keySet1	)/sizeof(int));

	printTreeH(mainTree);
	cout << "================ " << endl;

	printTreeHBST(mainTree2);
	cout << "================ Tree indelete" << endl;
	mainTree = deleteNode(mainTree, 7);
	printTreeH(mainTree);

	cout << "\n================ QUESTION 1 - A" << endl;

	cout << "Result Sum of left branch tree : \n" << sumLeftBranches(mainTree->left);

	cout << "\n================ QUESTION 1 - B" << endl;

	calcAvgNode(mainTree, 5);


	cout << "\n\n================== QUESTION 2 - STACK " << endl;

	cout << "With Stack   : " << (checkIsSymmetricalTree(mainTree) ? "Symmetric" : "Not Symmetric") << endl;
	cout << "Without Stack: " << (checkIsSymmetricalTree(mainTree) ? "Symmetric" : "Not Symmetric") << endl;


	return 1;
}