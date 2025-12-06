// Find the Nth Fibonacci number using recursion.
#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n){
    if(n<=1)
        return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    int result = fibonacci(6);
    cout << result;
}
// 0 1 1 2 3 5 8 13 21 ....
// fib(4) = 3 
