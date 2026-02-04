// Padovan Sequence

// Given a number n, find the nth number in the Padovan Sequence.

// A Padovan Sequence is a sequence which is represented by the following recurrence relation
// P(n) = P(n-2) + P(n-3)
// P(0) = P(1) = P(2) = 1
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int padovanSequence(int n) {
        if(n<=2)
            return 1;
        int p0, p1, p2, curr;
        p0 = p1 = p2 = 1;
        for(int i = 3; i<=n; i++){
            curr = p0 + p1;
            p0 = p1;
            p1 = p2;
            p2 = curr;
        }
        return p2;
    }
};

#if 0
6th = 4
3 4 5 6 iterations
3
curr = 2
p0 = 1
p1 = 1
p2 = 2

4
curr = 2
p0 = 1
p1 = 2
p2 = 2

5
curr = 3
p0 = 2
p1 = 2
p2 = 3

6 
curr = 4
p0 = 4
p1 = 3
p2 = 4


#endif

