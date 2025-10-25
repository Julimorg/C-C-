//
// Created by acer on 10/19/2025.
//

#include "Bai1.h"
#include <iostream>
#include <cstdio>

int main(){
    int n = 10;
    int a[10] = {3, 2, 1, 4, 5, 8, 9, 7, 6, 10};
    std::cout << "Duyet thuan : "<<std::endl;

//    for(int i = 0 ; i < n; i++)
//    {
//        std::cout << a[i] << " ";
//    }

    std::cout<<a[10]<<std::endl;

    std::cout<<"Duyet nguoc: "<<std::endl;
    for(int i = n ; i >= 0; i--)
    {
        std::cout<<a[i]<<" ";
    }



    return 0;
}