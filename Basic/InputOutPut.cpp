//
// Created by acer on 9/28/2025.
//

#include "InputOutPut.h"
#include "iostream"
using namespace std;

int main(){
    string name;
    int age;

    cout << "Hello! What is your name? ";
    getline(cin, name);

    cout << "How old are you? ";
    cin >> age;

    cout << "My name is " << name << endl;
    cout << "My age is " << age << endl;

    return 0;
}