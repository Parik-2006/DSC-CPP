// Find the product of digits of a number using recursion.
#include <bits/stdc++.h>
using namespace std;

int products_of_digits(int n){
    if(n<10)
        return n;
    return (n%10) * products_of_digits(n/10);

}

int main(void){
    // int n = 111;
    int n = 432;
    int result = products_of_digits(n);
    cout << result;
}

// 103 -> 3 * products_of_digits(10) - > 0 * products_of_digits(1) -> 1
// 1 * 0 -> 0 -> 3 * 0 -> 0

// 432 -> 2 * (43) -> 3 * (4) -> 4<10 -> return 4 -> 3*4 = 12 -> 2*12 = 24