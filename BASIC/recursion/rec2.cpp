#include <bits/stdc++.h>
using namespace std;

void func(int i, int n){
    if (i>n)
        return;
    cout << i << endl;
    func(i+1,n);
}

int main(){
    int num;
    cout << "Enter any number: " << endl;
    cin >> num;
    func(1,num);
    return 0;
}