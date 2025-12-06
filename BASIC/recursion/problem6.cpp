// Find the sum of digits of a number using recursion.

#include <bits/stdc++.h>
using namespace std;

int sum_of_digits(int n) {
    if (n == 0)
        return 0;
    return (n % 10) + sum_of_digits(n / 10);
}

int main(){
    // int n = 103;
    int n = 326;
    int result = sum_of_digits(n);
    cout << result;
    return 0;
}

// sum_of_digits(103) -> 3 + sum_of_digits(10) -> 0 + sum_of digits(1) -> 1 + sum_of_digits(0)
// 1 + 0 -> 1 -> 0 + 1 -> 1 -> 3 + 1 -> 4
