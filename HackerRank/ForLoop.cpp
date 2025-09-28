//
// Created by acer on 9/28/2025.
//

#include "ForLoop.h"
#include "iostream"
using namespace std;

int main(){

    int a;
    int b;
    cout<<"Input a"<<endl;
    cin>>a;
    cout<<"Input b"<<endl;
    cin>>b;

    for(int n = a; n <= b ; n++ ){
       if( n <= 9){
           if( n == 1){
               cout<<"one"<<endl;
           }
           if( n == 2){
               cout<<"two"<<endl;
           }
           if( n == 3){
               cout<<"three"<<endl;
           }
           if(n == 4){
               cout<<"four"<<endl;
           }
           if(n == 5){
               cout<<"five"<<endl;
           }
           if(n == 6){
               cout<<"six"<<endl;
           }
           if(n == 7){
               cout<<"seven"<<endl;
           }
           if(n == 8){
               cout<<"eight"<<endl;
           }
           if(n == 9){
               cout<<"nine"<<endl;
           }
       }else if(n % 2 == 0)
       {
           cout<<"even"<<endl;
       }else if( n % 2 != 0)
       {
           cout<<"odd"<<endl;
       }else {
           cout<<"Unknown"<<endl;
       }
    }

    return 0;
}