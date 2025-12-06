// Fibonacci Series
#include <bits/stdc++.h>
using namespace std;

int fib(int i){
    if(i<=1)
        return i;
    return fib(i-1) + fib(i-2);
}

int main(){
    int num;
    cout << "Enter your number: ";
    cin >> num;
    cout << "Fibonacci of " << num << " is " << fib(num);
    return 0;
}