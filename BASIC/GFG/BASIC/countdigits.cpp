#include <bits/stdc++.h>
using namespace std;

int countdigits(int n){
    int count = 0;
    while(n>0){
        n = n/10;
        count++;
    }
    return count;
}

bool palindrome(int n){
    int temp = n, rev = 0, ld;
    while(temp!=0){
        rev = rev * 10 + (temp % 10);
        temp = temp/10;
    }
    return (rev == n);
}

// For Both Functions TC - 0(log n) , SC - 0(n)

int main(){
    int num = 12221;
    cout << "Digits of the Given Number: " << countdigits(num) << endl;
    cout << "Palindrome Check: " << palindrome(num) << endl; // 0 for false and 1 for true
}

// The loop runs until the number becomes zero.
// In each iteration, the number is divided by 10.
// Dividing by 10 removes one digit from the number.
// Therefore, the loop executes once for each digit in the number.
// If the number has d digits, the loop runs d times.
// The number of digits d in a number n is proportional to log10(n).
// Hence, the time complexity of the function is O(log n).

// The loop does NOT run n times.
// The variable n is divided by 10 in every iteration, not decremented by 1.
// This means the value of n reduces exponentially, not linearly.
// Each iteration removes one digit from the number.
// The total number of digits in n is approximately log10(n).
// Therefore, the loop runs log(n) times, not n times.
// Hence, the time complexity is O(log n), not O(n).
