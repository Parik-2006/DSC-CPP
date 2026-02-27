#include <bits/stdc++.h>
using namespace std;

bool palindrome(int n){
    int reverse = 0;
    int temp = abs(n);
    while(temp!=0){
        reverse = (reverse*10) + (temp%10);
        temp /= 10;
    }
    return (reverse == abs(n));
}

bool palindrome1(int n){
    string temp = to_string(abs(n));
    int len = temp.length();
    for(int i = 0; i<len/2; i++){
        if(temp[i] != temp[len - i - 1])
            return false;
    }
    return true;
}

int main(){
    int n = 1331;
    if(palindrome(n))
        cout << "The number " << n << " is a Palindrome Number";
    else 
        cout << "The number " << n << " is not a Palindrome Number";
    return 0;
}

#if 0
palindrome
n = 1331, reverse = 0, temp = 1331;
reverse = (0*10) + (1331%10), reverse = 0 + 1 = 1, temp = 1331/10, temp = 133;
reverse = (1*10) + (133%10), reverse = 10 + 3 = 13, temp = 133/10, temp = 13;
reverse = (13*10) + (13%10), reverse = 130 + 3 = 133, temp = 13/10, temp = 1;
reverse = (133*10) + (1%10), reverse = 1330 + 1 = 1331, temp = 1/10, temp = 0;
1331 == 1331? Yes ... So PALINDROME

The time complexity of this function is O(log n) because the while loop processes one digit of 
the number in each iteration. In every step, the number is divided by 10, which removes the last
digit. So the loop runs as many times as there are digits in the number. The number of digits 
in a number n is approximately log base 10 of n plus 1, which is why the time complexity is 
O(log n). The space complexity is O(1) because the function only uses a few integer variables 
like reverse and temp, and it does not use any extra memory that depends on the size of the 
input. Therefore, the space used remains constant regardless of how large the number is.

The Loop runs 4 time for 1331 so log n time complexity ..... not O(n)...
#endif

#if 0 
palindrome2
n = 1332, temp = '1','3','3','2', len = 4;
for(0<2), if(s[0] != s[4-0-1]), if(s[0] != s[3]), if(1 != 2), return false;
so is not a palindrome number...

The time complexity of this function depends on the number of digits in the input number. First, 
the number is converted into a string, which takes time proportional to the number of digits. 
Then the loop runs from the beginning of the string to the middle, meaning it runs approximately 
half the number of digits. If the number has d digits, the loop runs about d/2 times. In Big-O 
notation, we ignore constants like 1/2, so the time complexity becomes O(d). Since the number of 
digits d in a number n is approximately log n, the time complexity can also be written as 
O(log n).

The space complexity is determined by the extra memory used. In this function, we create a 
string to store all the digits of the number. If the number has d digits, the string stores d 
characters. Therefore, the extra space used grows with the number of digits, making the space 
complexity O(d). And since d is approximately log n, the space complexity is also O(log n).

#endif