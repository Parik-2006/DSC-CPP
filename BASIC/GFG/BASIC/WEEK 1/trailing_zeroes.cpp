// Trailing Zeroes in Factorial

#include <bits/stdc++.h>
using namespace std;

int counttz(int n){
    int res = 0;
    for(int i = 5; i<=n; i*=5)
        res = res + n/i;
    return res;
}

int main(){
    int num = 251;
    cout << "Trailing Zeroes for the given number is: " << counttz(num) << endl;
}

#if 0
Trailing zeroes in a factorial are the number of zeroes that appear at the end
of the factorial value of a number.

A trailing zero is produced by a factor of 10, and 10 is equal to 2 multiplied by 5.
In the factorial of a number, there are always more factors of 2 than factors of 5.
Therefore, the number of trailing zeroes depends only on the number of times 5
appears as a factor.

To count the total number of factors of 5, we count how many numbers are divisible
by 5, then how many are divisible by 25 (which contribute an extra factor of 5),
then by 125, and so on.

The total number of trailing zeroes in n! is given by:
floor(n/5) + floor(n/25) + floor(n/125) + ...

This process continues until the divisor becomes greater than n.
#endif


#if 0
Time Complexity:
The loop runs by multiplying the divisor by 5 in each iteration (5, 25, 125, ...).
This means the number of iterations grows logarithmically with respect to n.
Therefore, the time complexity of the algorithm is O(log n).

Space Complexity:
The algorithm uses only a constant amount of extra memory for variables.
No additional space proportional to the input size is required.
Hence, the space complexity is O(1).
#endif
