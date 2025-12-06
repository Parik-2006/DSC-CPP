// a to the power n
#include <bits/stdc++.h>
using namespace std;

int a_pow_n(int a, int n) {
    if (n == 0)                        // (5,3) -> 5 * (5,2) -> 5 * (5,1) -> 5 * (5,0) = 1 = 5 = 25 = 125
        return 1;
    return a * a_pow_n(a, n - 1);
}

// int a_pow_n(int a, int n) {
//     int result = 1;          
//     for(int i = 0; i < n; i++) {  // result = 1 , result = 5, result = 25; result = 125
//         result *= a;         
//     }
//     return result;
// }

int main() {
    int a, n;
    cout << "Enter any number: ";
    cin >> a;
    cout << "Enter the power: ";
    cin >> n;

    int ans = a_pow_n(a, n);     
    cout << "Result = " << ans; 

    return 0;
}
