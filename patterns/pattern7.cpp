#include<bits/stdc++.h>
using namespace std;

void pattern7(int n){
    for(int i = 0; i<n; i++){

        // SPACE
        for(int j = 0; j<i; j++){
            cout << " ";
        }

        // stars
        for(int j = 0; j< 2*n - (2*i+1); j++){
            cout << "*";
        }

        // // SPACE optional
        // for(int j = 0; j<n-i-1; j++){
        //     cout << " ";
        // }
        cout << endl;
    }
}

int main(void){
    int n; 
    cout << "Enter any Number: ";
    cin >> n;
    pattern7(n);
}

#if 0
Enter any Number: 5
*********
 *******
  *****
   ***
    *
#endif
