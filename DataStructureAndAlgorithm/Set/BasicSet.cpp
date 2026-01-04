//
// Created by acer on 12/23/2025.
//

#include "BasicSet.h"
#include "bits/stdc++.h"

using namespace std;

int main(){

    // Set thông thường
    set<int> s1;                           // set rỗng
    set<int> s2 = {5, 2, 8, 1, 9};        // khởi tạo với giá trị
    set<int, greater<int>> s5;              // sắp xếp giảm dần
    set<int> s3(s2);                       // copy từ s2
    set<int> s4(s2.begin(), s2.end());    // copy từ iterator


    // thêm phần tử
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s1.insert(4);
    s1.insert(5);
    s1.insert(6);


    // Kiểm tra insert thành công
    auto[it, success] = s1.insert(1);
    if( success) {
        cout << "Them thanh cong: " << *it << endl;
    }

    // Xóa phần thử
    s1.erase(2);

    // TÌM KIẾM
    auto it = s1.find(2);
    if(it != s1.end()) {
        cout << "Tim thay: " << *it << endl;
    }

    // KIỂM TRA TỒN TẠI
    if(s1.count(5)) {    // count() trả về 0 hoặc 1
        cout << "5 ton tai" << endl;
    }

    // DUYỆT (đã được sắp xếp)
    for(int x : s1) {
        cout << x << " ";
    }

    return 0;
}