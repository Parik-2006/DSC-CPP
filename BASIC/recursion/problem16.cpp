// Generate the sum of digits until a single digit (digital root) using recursion.

// ex => 478 -> 4 + 7 + 8 => 19 -> 1 + 9 => 10 -> 1 + 0 => 1

#include <bits/stdc++.h>
using namespace std;

int sum_of_digits(int num){
    if (num == 0)
        return 0;
    num = num%10 + sum_of_digits(num/10);
    if(num>9)
        return sum_of_digits(num);
}

int main(){
    // int num = 478;  // -> 1
    // int num = 470; // -> 2
    int num = 4567;
    int result = sum_of_digits(num);
    cout << result;
    return 0;
}
