#include <bits/stdc++.h>
using namespace std;

int main(){
    string s = "Parikshith B Bilchode";
    cout << s[3] << "\n";
    int len = s.size();
    s[len-1] = 'u';
    cout << s << "\n";
    
    return 0;
} 