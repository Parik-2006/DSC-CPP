#include <bits/stdc++.h>
using namespace std;

bool primeno(int n){
    if(n == 1)
        return false;
    if(n == 2 || n == 3)
        return true;
    if(n % 2 == 0 || n % 3 == 0)
        return false;
    for(int i = 5; i<= sqrt(n); i+=6){ // i*i <= n ... uu baribodu
        if(n % i == 0 || n % (i+2) == 0)
            return false;
    }
    return true;
}

int main(){
    int n = 5888;
    if(primeno(n))
        cout << "Your Given Number "<< n <<" is Prime Number.." << endl;
    else
        cout << "Your Given Number "<< n <<" is not a Prime Number.." << endl;

}

#if 0
This function checks whether a given number is prime.

First, special cases are handled:
1 is not a prime number, while 2 and 3 are prime numbers.
These checks avoid unnecessary computation later.

Next, the function removes all numbers divisible by 2 or 3.
Any number divisible by 2 is even and cannot be prime.
Any number divisible by 3 is also not prime.
This step filters out a large set of composite numbers early.

The loop runs only up to the square root of the number.
If a number is composite, it must have at least one factor
less than or equal to its square root.
Checking beyond this limit is unnecessary.

The loop increments by 6 because after removing multiples of
2 and 3, all remaining prime candidates are of the form
6k − 1 or 6k + 1.
Therefore, in each iteration, the function checks divisibility
by i (6k − 1) and i + 2 (6k + 1).

This filtering greatly reduces the number of checks while
maintaining correctness, making the algorithm more efficient
than a basic prime-checking approach.

The time complexity of this algorithm is O(sqrt(n)),
and the space complexity is O(1).

n = 251,
n == 1, n == 2, n == 3 ... no
n%2 == 0, n%3 == 0 .... no
for(5 <= 15, 5+6), 251%5 == 0, 251 % 7 == 0 .. no,
for(11 <= 15, 11+6), 251%11 == 0, 251%13 == 0 .. no, 
for(17 <= 15).. comes out of loop... return true ..
so 251 is a prime no
#endif


// #include <iostream>
// using namespace std;

// class Solution{
// public:
//     bool isPrime(int N){
//         if(N == 1)
//             return false;
//         if(N == 2 || N == 3)
//             return true;
//         if(N%2 == 0|| N%3 == 0)
//             return false;
//         for(int i = 5; i*i <=N; i+=6){
//             if(N%i ==0 || N%(i+2) == 0)
//                 return false;
//         }
//         return true;
//     }
// };

// int main(){
//     int N;
//     cin >> N;
//     Solution obj;
//     if(obj.isPrime(N))
//         cout << "True";
//     else
//         cout << "False";
// }
// main function idre terminal alli