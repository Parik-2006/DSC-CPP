// Print all even numbers from 1 to N using recursion.
#include <bits/stdc++.h>
using namespace std;

void even(int n){
    if(n<1)
        return;
    even(n-1);
    if(n%2==0)
        cout << n << endl;
}

int main() {
    int n;
    cout << "Enter any number: ";
    cin >> n;
    even(n);      
    return 0;
}