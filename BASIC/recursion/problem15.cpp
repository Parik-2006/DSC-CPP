// Find the Least Common Multiple (LCM) using recursion.
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);   // recursive gcd
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);            // lcm formula
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << lcm(a, b);
}
