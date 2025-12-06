#include <bits/stdc++.h>
using namespace std;

int fact(int i){
    if(i == 1)
        return 1;
    return i *fact(i-1);
}
int main(){
int num;
    cout << "Enter any number: ";
    cin >> num;
    int result = fact(num);
    cout << "fact of " << num << " is " << result << endl;
    return 0;
}