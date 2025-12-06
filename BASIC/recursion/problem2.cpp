// to check if an string is palindrome or not
#include <bits/stdc++.h>
using namespace std;

bool s_palind(int i, string &string1){
    if(i>=string1.size()/2) return true;
    if(string1[i] != string1[string1.size()-i-1]) return false;
    return s_palind(i+1, string1);   
}

int main(){
    string string1;
    cout << "Enter your STRING: ";
    cin >> string1;
    cout << string1 << endl;
    if(s_palind(0, string1))
        cout << "String is Palindrome..\n";
    else
        cout << "String is not Palindrome..\n";
    return 0;
}