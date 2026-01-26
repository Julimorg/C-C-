//
// Created by acer on 1/26/2026.
//

#include "PracticePointer5.h"
#include "iostream"

using namespace std;

struct Student {
    int id;
    string name;
    int age;
    float gpa;
};

void inputStudent(Student *s, int index ) {
    int id = s->id = index;
    cout << "\nEnter information of student " << id << ":\n";
    cout << "Enter name: ";
    cin >> s->name;
    cout << "Enter age: ";
    cin >> s->age;
    cout << "Enter gpa: ";
    cin >> s->gpa;
}

void displayStudent(Student *s, int index){
    int id = s->id = index;

    cout << "\nDisplaying Information of student " << id << ":\n";
    cout << "Name: " << s->name << endl;
    cout << "Age Number: " << s->age << endl;
    cout << "GPA: " << s->gpa << endl;
}

int main(){

    int n;
    cout << "Input Number Student: " ;
    cin >> n;

    struct Student *sArr = new Student[n];

    for ( int i = 0 ; i <  n; i++) {
        inputStudent(&sArr[i],i);
    }

    for ( int i = 0 ; i < n; i++ ){
        displayStudent(&sArr[i],i);
    }
    delete[] sArr   ;

    return 0;
}