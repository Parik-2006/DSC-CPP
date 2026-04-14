#include <iostream>
using namespace std;

// Recursive function
int factorial(int n) {
    
    // Base case
    if (n == 0 || n == 1) {
        return 1;
    }

    // Recursive case
    return n * factorial(n - 1);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int result = factorial(n);

    cout << "Factorial of " << n << " is: " << result << endl;

    return 0;
}