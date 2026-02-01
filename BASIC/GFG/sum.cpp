#include <bits/stdc++.h>
using namespace std;

int sum(int n){
    return n * (n+1)/2;
}

int sum1(int n){
    int sum = 0;
    for(int i = 1; i<=n; i++){
        sum = sum + i;
    }
    return sum;
}

int sum2(int n){
    int sum = 0;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=i; j++){
            sum++;
        }
    }
    return sum;
}

int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    cout << "O(1) Time: " << sum(n) << endl;
    cout << "O(n) Time: " << sum1(n) << endl;
    cout << "O(n^2) Time: " << sum2(n) << endl;
}