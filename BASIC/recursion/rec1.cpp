#include <bits/stdc++.h>
using namespace std;

int func(int i,int n){
    if(i>n){
        return 0;
    }
    cout << "Hello" << endl;
    func(i+1,n);
}

int main(){
    int n;
    cout << "Enter any number: ";
    cin >> n;
    func(1,n);
    return 0;
}