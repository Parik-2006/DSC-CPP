// GCD or HCF and LCM
//Euclidean algorithm

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

int lcm(int a, int b){
    return (a*b)/ gcd(a,b);
}

int main(){
    int a = 3, b = 7;
    cout << "GCD of given two numbers are: " << gcd(a,b) << endl;
    cout << "LCM of given two numbers are: " << lcm(a,b) << endl;
}

#if 0
Time Complexity of GCD:
The GCD function uses the Euclidean algorithm.
In each recursive call, the value of the second parameter becomes a % b.
This value decreases rapidly and reduces the problem size.
Hence, the number of recursive calls grows logarithmically.
Therefore, the time complexity of GCD is O(log min(a, b)).

Space Complexity of GCD:
The GCD function is recursive.
Each recursive call uses stack memory.
The maximum depth of recursion is O(log min(a, b)).
Hence, the space complexity is O(log min(a, b)).

Time Complexity of LCM:
The LCM function performs constant time multiplication and division.
It calls the GCD function once.
Therefore, the time complexity of LCM is O(log min(a, b)).

Space Complexity of LCM:
The LCM function itself uses constant extra space.
However, it depends on the recursive GCD call.
Thus, the space complexity of LCM is O(log min(a, b)).
#endif

#if 0
The time complexity of the GCD algorithm depends on how fast the numbers reduce.
In the Euclidean algorithm, each step replaces the pair (a, b) with (b, a % b).
The value a % b is always smaller than b, so the problem size reduces.

The number of such reductions depends on the smaller of the two numbers.
Hence, the time complexity is expressed as O(log min(a, b)).

If we assume n represents the smaller input value, then O(log min(a, b))
can also be written as O(log n).

Therefore, O(log n) is not wrong, but O(log min(a, b)) is more precise
because the algorithm depends on the smaller input, not both numbers.
#endif
