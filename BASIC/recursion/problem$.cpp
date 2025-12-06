#include <bits/stdc++.h>
using namespace std;

void TOH(int n, char a, char b, char c) {
    if (n > 0) {
        TOH(n - 1, a, c, b);
        cout << "Move disk " << n << " from " << a << " to " << c << endl; 
        TOH(n - 1, b, a, c);
    }
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    TOH(n, 'S', 'H', 'D');
    return 0;
}