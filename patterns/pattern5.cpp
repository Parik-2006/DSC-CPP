#include<bits/stdc++.h>
using namespace std;

void pattern5(int n){
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n-i+1; j++){
            cout << j << " ";
        }
        cout << endl;
    }
}

int main(void){
    int n; 
    cout << "Enter any Number: ";
    cin >> n;
    pattern5(n);
}

#if 0
Enter any Number: 5 
1 2 3 4 5 
1 2 3 4 
1 2 3 
1 2 
1 
#endif
