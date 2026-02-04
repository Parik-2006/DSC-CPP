// to print all prime numbers form 2 to given n 
//Sieve of Eratosthenes
#include <bits/stdc++.h>
using namespace std;

void seive(int n){
    vector <bool> array(n+1, true);
    for(int i = 2; i <=n; i++){
        if(array[i]){
            cout << i << " ";
            for(int j = i*i; j<=n; j+=i)
                array[j] = false;
        }
    }
}

int main(){
    int n = 20;
    cout << "All the Prime Numbers from 2 to " << n << " is: ";
    seive(n);
}

#if 0
This algorithm prints all prime numbers from 2 to n using the
Sieve of Eratosthenes technique.

A boolean array of size n + 1 is created where each index represents
a number and the value indicates whether the number is prime or not.
Initially, all entries are marked as true, assuming all numbers are prime.

The loop starts from 2 because 0 and 1 are not prime numbers.
For each number i, if array[i] is true, it means i is a prime number
and is printed.

After identifying i as prime, all multiples of i are marked as false
because multiples of a prime number cannot be prime.
The inner loop starts from i * i because any smaller multiple of i
would have already been marked by smaller prime numbers.

This process continues until all numbers up to n are processed.
At the end, only prime numbers remain marked as true and are printed.

The time complexity of the Sieve of Eratosthenes is O(n log log n),
and the space complexity is O(n).
#endif


#if 0
Dry Run of Sieve of Eratosthenes for n = 20

Initially, a boolean array of size n + 1 is created.
All values from index 2 to 20 are marked as true,
assuming all numbers are prime at the beginning.

Iteration i = 2:
Since array[2] is true, 2 is a prime number and is printed.
All multiples of 2 starting from 2 × 2 = 4 are marked as false.
Marked numbers: 4, 6, 8, 10, 12, 14, 16, 18, 20.

Iteration i = 3:
Since array[3] is true, 3 is a prime number and is printed.
All multiples of 3 starting from 3 × 3 = 9 are marked as false.
Marked numbers: 9, 12, 15, 18.

Iteration i = 4:
array[4] is false, so 4 is skipped because it is already known
to be a composite number.

Iteration i = 5:
array[5] is true, so 5 is a prime number and is printed.
Since 5 × 5 = 25 is greater than 20, no multiples are marked.

Iteration i = 6:
array[6] is false, so it is skipped.

Iteration i = 7:
array[7] is true, so 7 is a prime number and is printed.
Since 7 × 7 = 49 is greater than 20, no multiples are marked.

For values of i from 8 to 20:
All composite numbers are skipped.
Remaining values marked as true are prime numbers and are printed.

Final prime numbers from 2 to 20 are:
2, 3, 5, 7, 11, 13, 17, 19.
#endif
