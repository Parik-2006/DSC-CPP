#include<bits/stdc++.h>
using namespace std;

void pattern1(int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout << "* ";
        }
        cout << endl;
    }
}

int main(void){
    int n; 
    cout << "Enter any Number: ";
    cin >> n;
    pattern1(n);
}

#if 0
Enter any Number: 5
* * * * * 
* * * * * 
* * * * * 
* * * * * 
* * * * * 
#endif