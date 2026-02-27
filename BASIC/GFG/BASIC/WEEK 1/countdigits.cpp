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

int countdigits1(int n){
    if(n>0)
        return floor(log10(n) + 1);
} // TC - O(1), SC - 0(1)

bool palindrome(int n){
    int temp = n, rev = 0, ld;
    while(temp!=0){
        rev = rev * 10 + (temp % 10);
        temp = temp/10;
    }
    return (rev == n);
}
// For Both Functions TC - 0(log n) , SC - 0(n)

int countdigits2(int n){
    return floor(log10(n) + 1);
}

// TC - 0(1) , SC - 0(1)

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


// The log₁₀ method is used to count the number of digits in a number because logarithms tell us 
// the power to which 10 must be raised to obtain that number. In the decimal number system, 
// digits increase whenever a number crosses a power of 10. For example, numbers from 1 to 9 have 
// 1 digit, from 10 to 99 have 2 digits, from 100 to 999 have 3 digits, and so on. This pattern 
// shows that the number of digits depends on how many times 10 fits into the number as a power. 
// When we take log base 10 of a number, it gives us the exponent of the nearest lower power of 10. 
// The integer part (floor value) of that logarithm tells us one less than the total number of 
// digits, so we simply add 1 to get the exact digit count. That is why the log₁₀ method works 
// efficiently, especially for very large numbers where counting digits directly is not practical.
