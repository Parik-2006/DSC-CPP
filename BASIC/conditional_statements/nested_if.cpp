#include <bits/stdc++.h>
using namespace std;

int main(){
    int age;
    cin >> age;
    if(age<=18){
        cout << "You are not eligible to work";
    } else if (age <=57){
        cout << "You are eligible to work";
        if(age >= 50 ){
            cout << ", but retirement soon!!";
        } 
    } else {
        cout << "Retirement Time";
    }
}