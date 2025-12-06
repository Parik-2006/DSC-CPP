// Multiply two numbers using only addition and recursion

#include <bits/stdc++.h>
using namespace std;

int multiply(int num1, int num2){
    if(num2<=1)
        return num1;
    return num1 + multiply(num1, num2-1);
}

int main(){
    int num1 = 6, num2 = 4;
    int result = multiply(num1,num2);
    cout << result;
    return 0;
}