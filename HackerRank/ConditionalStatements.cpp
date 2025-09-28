//
// Created by acer on 9/28/2025.
//

#include "ConditionalStatements.h"
#include "iostream"
using namespace std;

int main(){

    int n;

    cin>>n;

    if( n <= 9 && n>= 1){
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
    }else if ( n > 9 ){
        cout<<"Greater than 9"<<endl;
    }else{
        cout<<"Unknown"<<endl;
    }


    return 0;

}
