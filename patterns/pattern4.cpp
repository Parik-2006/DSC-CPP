#include<bits/stdc++.h>
using namespace std;

void pattern4(int n){
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n-i+1; j++){
            cout << "* ";
        }
        cout << endl;
    }
}

int main(void){
    int n; 
    cout << "Enter any Number: ";
    cin >> n;
    pattern4(n);
}

#if 0
Enter any Number: 5
* * * * * 
* * * * 
* * * 
* * 
* 
#endif
