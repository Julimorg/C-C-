#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    char  en[100];
    char  vi[100];
    Node* left;
    Node* right;
};

Node* createNode(char* en, char* vi) {
    Node* p  = new Node();
    // cai strcpy(A,B) la copy thang  B sang thang A
    strcpy(p->en, en);
    strcpy(p->vi, vi);
    p->left  = NULL;
    p->right = NULL;
    return p;
}


//findMinNode trong subtree ben phai
Node* findMin(Node* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}


void insertWord(Node*& node, char* en, char* vi) {
    if (node == NULL) {
        node = createNode(en, vi);
        cout << ">> Da them: " << en << " - " << vi << "\n";
        return;
    }
    int compateResult = strcmp(en, node->en);

    if (compateResult < 0) {

        insertWord(node->left,  en, vi);

    }else if (compateResult > 0) {

        insertWord(node->right, en, vi);

    }
    else {
        strcpy(node->vi, vi);
        cout << ">> Cap nhat: " << en << " - " << vi << "\n";
    }
}

void deleteWord(Node*& node, char* en) {
    if (node == NULL) {
        cout << ">> Khong tim thay: " << en << "\n";
        return;
    }
    int compateResult = strcmp(en, node->en);

    if (compateResult < 0) {

        deleteWord(node->left,  en);

    } else if (compateResult > 0) {

        deleteWord(node->right, en);

    } else {

        if (node->left == NULL && node->right == NULL) {
            delete node;
            node = NULL;
        }

        else if (node->left == NULL) {
            Node* tmp = node->right;
            delete node;
            node = tmp;
        }

        else if (node->right == NULL) {
            Node* tmp = node->left;
            delete node;
            node = tmp;
        }

        else {
            Node* successor = findMin(node->right);
            strcpy(node->en, successor->en);
            strcpy(node->vi, successor->vi);
            deleteWord(node->right, successor->en);
        }
        cout << ">> Da xoa: " << en << "\n";
    }
}

// search dic
char printVi(Node* node, char* en) {
    if (node == NULL) {
        cout << ">> Khong tim thay: " << en << "\n";
        return '\0';
    }
    int compateResult = strcmp(en, node->en);

    if (compateResult < 0) {

        return printVi(node->left,  en);

    }else if (compateResult > 0) {

        return printVi(node->right, en);

    }else {
        cout << ">> " << node->en << " : " << node->vi << "\n";
        return node->vi[0];
    }
}

// cai nay duyet theo inorder
void printDicAZ(Node* node) {
    if (node == NULL) return;
    printDicAZ(node->left);
    cout << node->en << " : " << node->vi << "\n";
    printDicAZ(node->right);
}


int main() {
    Node* root = NULL;

    cout << "===== THEM TU =====\n";
    char en1[] = "mango",  vi1[] = "xoai";
    char en2[] = "banana", vi2[] = "chuoi";
    char en3[] = "orange", vi3[] = "cam";
    char en4[] = "apple",  vi4[] = "tao";
    char en5[] = "cherry", vi5[] = "anh dao";
    char en6[] = "peach",  vi6[] = "dao";

    insertWord(root, en1, vi1);
    insertWord(root, en2, vi2);
    insertWord(root, en3, vi3);
    insertWord(root, en4, vi4);
    insertWord(root, en5, vi5);
    insertWord(root, en6, vi6);


    cout << "\n===== TU DIEN A-Z =====\n";
    printDicAZ(root);


    cout << "\n===== TRA CUU =====\n";
    char s1[] = "cherry";
    char s2[] = "grape";
    printVi(root, s1);
    printVi(root, s2);


    cout << "\n===== XOA TU =====\n";
    char d1[] = "banana";
    char d2[] = "peach";
    char d3[] = "grape";
    deleteWord(root, d1);
    deleteWord(root, d2);
    deleteWord(root, d3);


    cout << "\n===== TU DIEN SAU KHI XOA =====\n";
    printDicAZ(root);

    return 0;
}
