// Print all odd numbers from 1 to N using recursion.
#include <bits/stdc++.h>
using namespace std;

void odd(int n){
    if(n<1)
        return;
    odd(n-1);
    if(n%2!=0)
        cout << n << endl;
}

int main() {
    int n;
    cout << "Enter any number: ";
    cin >> n;
    odd(n);      
    return 0;
}