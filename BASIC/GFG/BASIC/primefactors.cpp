#include <bits/stdc++.h>
using namespace std;

void pf(int n){
    if(n<=1)
        return;
    while(n % 2 == 0){
        cout << 2 << " ";
        n = n/2;
    }
    while(n % 3 == 0){
        cout << 3 << " ";
        n = n/3;
    }
    for(int i = 5; i <= sqrt(n); i++){
        while(n % i == 0){
            cout << i << " ";
            n = n/i;
        }
        while(n % (i+2) == 0){
            cout << (i+2) << " ";
            n = n/(i+2);
        }
    }   
    if(n>3)
        cout << n << " ";
}

int main(){
    int n = 60;
    cout << "Prime Factors of " << n << " is: ";
    pf(n);
}

#if 0
This algorithm finds the prime factors of a given number n.

Prime factorization means expressing a number as a product of prime numbers.
For example, 60 = 2 × 2 × 3 × 5.

If n is less than or equal to 1, the function returns because such numbers
do not have any prime factors.

The algorithm first removes all factors of 2.
Since 2 is the only even prime number, extracting it first reduces the
number quickly and simplifies further checks.

Next, all factors of 3 are removed.
After removing factors of 2 and 3, the remaining number is not divisible
by either of them.

The loop then starts from 5 and checks factors only up to the square root of n.
If n is composite, it must have at least one prime factor less than or equal
to sqrt(n), so checking beyond this limit is unnecessary.

The loop increments by 6 and checks divisibility by i and i + 2.
After removing multiples of 2 and 3, all remaining prime candidates are of
the form 6k − 1 and 6k + 1.
This skips unnecessary composite numbers and improves efficiency.

Each time a prime factor is found, the number n is divided by that factor.
This reduces the problem size and prevents infinite loops.

After all smaller prime factors are removed, if the remaining value of n
is greater than 3, it must itself be a prime number and is printed once
as the final prime factor.

This approach efficiently computes prime factorization with a time
complexity of O(sqrt(n)) and constant space complexity O(1).
#endif
