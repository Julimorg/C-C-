//
// Created by acer on 9/21/2025.
//

#include "Namespace.h"
#include <iostream>

namespace first{
    int x = 1;
}
namespace second{
    int y = 2;
}
int main(){

    std::cout << first::x;

    std::cout << second::y;


    return 0;
}