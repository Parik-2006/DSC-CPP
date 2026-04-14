#include <iostream>
using namespace std;

// Recursive function
int fibonacci(int n) {
    
    // Base cases
    if (n == 0) return 0;
    if (n == 1) return 1;

    // Recursive relation
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cout << "Enter number of terms: ";
    cin >> n;

    cout << "Fibonacci Series: ";
    for (int i = 0; i < n; i++) {
        cout << fibonacci(i) << " ";
    }

    return 0;
}