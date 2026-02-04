#include <bits/stdc++.h>
using namespace std;

// recursive solution
int power(int x, int n){
    if(n == 0)
        return 1;
    int temp = power(x, n/2);
    temp *= temp;
    if(n%2==0)
        return temp;
    else    
        return temp*x;
}

//iterative solution
int power1(int x, int n){
    int res = 1;
    while(n > 0){
        if(n & 1)
            res *= x;
        x *= x;
        n = n >> 1;
    }
    return res;
}

int main(){
    int x = 3, n = 5;
    cout << x << " power " << n << " is: " << power(x,n) << endl; 
    cout << x << " power " << n << " is: " << power1(x,n) << endl; 
}

#if 0
power() function 
This function computes x raised to the power n using the
divide-and-conquer (fast exponentiation) technique.

If n is 0, the result is 1 because any number raised to the power 0 is 1.
This acts as the base case of the recursion.

The problem is divided into a smaller subproblem by calculating
x^(n/2) recursively.
This significantly reduces the number of multiplications.

The result of x^(n/2) is stored in a temporary variable and then squared.
If n is even, x^n is equal to (x^(n/2))^2.

If n is odd, x^n is equal to (x^(n/2))^2 multiplied by x once more.
This extra multiplication accounts for the odd power.

By repeatedly halving the exponent, the algorithm reduces the time
complexity from O(n) to O(log n).

The recursion depth grows logarithmically, so the space complexity
is O(log n) due to the recursive call stack.
#endif

#if 0
power1() function
This algorithm computes x raised to the power n using an
iterative fast exponentiation (binary exponentiation) method.

The idea is to reduce the number of multiplications by using
the binary representation of the exponent n.

A variable res is initialized to 1 to store the final result.

While n is greater than 0, the algorithm checks whether n is odd.
This is done using the bitwise AND operation (n & 1).
If n is odd, the current value of x contributes to the result,
so res is multiplied by x.

In each iteration, x is squared.
This represents moving to the next power of two in the exponent.

The exponent n is then right-shifted by 1 bit, which is equivalent
to dividing n by 2.
This reduces the problem size in every iteration.

The loop continues until n becomes 0, at which point res contains
the final value of x raised to the power n.

This approach reduces the time complexity from O(n) to O(log n).
The space complexity is O(1) because it uses only constant extra memory.
#endif

