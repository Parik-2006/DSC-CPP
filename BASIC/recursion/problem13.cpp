// Print the Fibonacci series using recursion.
#include <bits/stdc++.h>
using namespace std;

void printFib(int n, int a = 0, int b = 1, int idx = 0) {
    if (idx > n) 
        return;      // stop when we reach n
    cout << a << " ";         // print current Fibonacci number
    printFib(n, b, a + b, idx + 1);  // move to next
}


int main() {
    int n;
    cin >> n;
    printFib(n);
}

// 0 1 1 2 3 5 8 13 21 ....
// fib(4) = 3 
