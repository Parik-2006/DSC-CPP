#include<bits/stdc++.h>
using namespace std;

void pattern6(int n){
    for(int i = 0; i<n; i++){

        // SPACE
        for(int j = 0; j<n-i-1; j++){
            cout << " ";
        }

        // stars
        for(int j = 0; j<2*i+1; j++){
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
    pattern6(n);
}

#if 0
Enter any Number: 5
    *    
   ***   
  *****  
 ******* 
*********
#endif
