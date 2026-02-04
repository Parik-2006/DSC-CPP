#if 0
Given a positive integer n, count the number of ways to express n as a sum of 1, 3 and 4.
Note: The answer will always fit into a 32-bit integer.

Examples:

Input: n = 4
Output: 4
Explanation: There is 4 ways to represent 4 as sum of 1, 3 and 4: (1+1+1+1), (1+3), (3+1) and (4).
Input: n = 3
Output: 2
Explanation: There is 2 ways to represent 3 as sum of 1, 3 and 4: (1+1+1) and (3).
Constraints:
1 <= n <= 45

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(n)

#endif

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int padovanSequence(int n) {
        const int MOD = 1000000007;

        if(n <= 2)
            return 1;

        long long p0 = 1, p1 = 1, p2 = 1;
        long long curr;

        for(int i = 3; i <= n; i++){
            curr = (p0 + p1) % MOD;
            p0 = p1;
            p1 = p2;
            p2 = curr;
        }
        return p2;
    }
};

#if 0
This problem asks for the number of ways to form a number n using
only the values 1, 3, and 4, where the order of values matters.

An array is used to store the number of ways to form each value.
Let array[i] represent the number of ways to form the value i.

To form the value i, the last number added can be:
1  → remaining value is i - 1
3  → remaining value is i - 3
4  → remaining value is i - 4

So, the number of ways to form i is the sum of the ways to form
i - 1, i - 3, and i - 4.

This gives the relation:
array[i] = array[i - 1] + array[i - 3] + array[i - 4]

Base values are initialized as:
array[0] = 1  (one way to form 0, by choosing nothing)
array[1] = 1  (1)
array[2] = 1  (1 + 1)
array[3] = 2  (1 + 1 + 1, 3)

Using these base values, the array is filled iteratively from
index 4 up to n.
Each value is computed only once and reused when needed.

This approach avoids repeated computations of recursive solutions.

The time complexity is O(n) because the array is filled once.
The space complexity is O(n) because an array of size n + 1 is used.
#endif

#if 0
If the sum must be formed using only the values 2, 4, and 5,
the approach remains the same, but the recurrence relation changes.

An array is used where array[i] represents the number of ways
to form the value i using only 2, 4, and 5.

To form the value i, the last number added can be:
2  → remaining value is i - 2
4  → remaining value is i - 4
5  → remaining value is i - 5

Therefore, the number of ways to form i is the sum of the ways
to form i - 2, i - 4, and i - 5.

The recurrence relation becomes:
array[i] = array[i - 2] + array[i - 4] + array[i - 5]

Base cases must be initialized carefully:
array[0] = 1  (one way to form 0, by choosing nothing)
array[1] = 0  (cannot be formed using 2, 4, 5)
array[2] = 1  (2)
array[3] = 0  (cannot be formed)
array[4] = 1  (4)
array[5] = 2  (2+3 not allowed, but 5 and 2+? handled by recurrence)

Using these base values, the array is filled iteratively from
the smallest valid index up to n.

Each value is computed once, giving O(n) time complexity.
The array uses O(n) space.
#endif
