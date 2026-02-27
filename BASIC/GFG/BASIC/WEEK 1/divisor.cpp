// all divisor of a given number

#include <bits/stdc++.h>
using namespace std;

void divisor(int n){
    int i;
    for(i = 1; i<sqrt(n); i++){
        if(n % i == 0)
            cout << i << " ";
    }
    for( ; i>=1; i--){
        if(n % i == 0)
            cout << (n/i) << " ";
    }
}

int main(){
    int n = 60;
    cout << "All the Divisors of " << n << " is: ";
    divisor(n);
}

#if 0
This approach prints all divisors of a given number n efficiently.

Divisors of a number always come in pairs.
If i is a divisor of n, then (n / i) is also a divisor.

The algorithm uses the fact that these divisor pairs are centered around
the square root of the number.
For any divisor greater than sqrt(n), there exists a corresponding divisor
smaller than sqrt(n).

In the first loop, the algorithm checks all values of i from 1 up to sqrt(n).
Whenever i divides n, i is printed as a divisor.
This prints the smaller divisors in increasing order.

The loop stops before sqrt(n) to avoid duplicate printing when n is a
perfect square.

In the second loop, the algorithm iterates backward from the last value of i
down to 1.
For each i that divides n, the corresponding divisor (n / i) is printed.
This prints the larger divisors in increasing order.

By splitting the work into two loops, the algorithm avoids redundant checks
and prints all divisors in sorted order.

This approach reduces the time complexity from O(n) to O(sqrt(n)) and
uses constant extra space.
#endif
