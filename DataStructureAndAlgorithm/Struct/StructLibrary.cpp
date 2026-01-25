//
// Created by acer on 1/21/2026.
//

#include "StructLibrary.h"
#include "iostream"
#include "vector"


using namespace std;

struct books{
    int id;
    string name;
    string author;
    int year;
    bool borrow;

    books(int id, string name, string author, int year) {
        id = id;
        name = name;
        author = author;
        year = year;
        borrow = false;
    }

    void display() {
        cout << "Ma: " << id << endl;
        cout << "Ten: " << name << endl;
        cout << "Tac gia: " << author << endl;
        cout << "Nam XB: " << year << endl;
        cout << "Trang thai: " << (borrow ? "Da muon" : "Con trong") << endl;
    };

    void muonSach(){
        if(!borrow) {
            borrow = true;
            cout << "Muon sach thanh cong!" << endl;
        } else {
            cout << "Sach da duoc muon!" << endl;
        }
    }
};


struct library {
    vector<books> listBooks;

    void addBook(books b) {
        listBooks.push_back(b);
    }

    void showAll() {
        for (auto i : listBooks){
            i.display();
            cout << "-------------------" << endl;
        }
    }

    books* findBook(int bookId) {
        for ( auto &i : listBooks){
            if (i.id == bookId) {
                return &i;
            }
        }
        return nullptr;
    }

};
int main(){

    library l;

    l.addBook(books(101, "Lap trinh C++", "Nguyen Van A", 2020));
    l.addBook(books(102, "Cau truc du lieu", "Tran Thi B", 2019));

    l.showAll();

    books *s = l.findBook(101);

    if ( s != nullptr) {
        s -> muonSach();
    }

    return 0;
}
