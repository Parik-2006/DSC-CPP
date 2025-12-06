// Print all even numbers from N to 1 using recursion.
#include <bits/stdc++.h>
using namespace std;

void even(int n){
    if(1>n)
        return;
    if(n%2==0)
        cout << n << endl;
    even(n-1);
    
}

int main() {
    int n;
    cout << "Enter any number: ";
    cin >> n;
    even(n);      
    return 0;
}