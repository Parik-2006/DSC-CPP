// trailing zeroesin a factorial

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        for(int i = 5; i<=n; i*=5){
            res += n/i;
        }
        return res;
    }
};

#if 0
Example 1:
Input: 5
5! = 5 × 4 × 3 × 2 × 1 = 120
There is one factor of 5 in 5.
Number of trailing zeros = 1

Example 2:
Input: 10
10! = 3628800
Multiples of 5: 5 and 10
So there are 2 factors of 5.
Number of trailing zeros = 2

Example 3:
Input: 15
Multiples of 5: 5, 10, 15
So there are 3 factors of 5.
Number of trailing zeros = 3

Example 4:
Input: 25
Multiples of 5: 5, 10, 15, 20, 25
That gives 5 factors of 5.
But 25 = 5 × 5, so it contributes one extra 5.
Total factors of 5 = 6
Number of trailing zeros = 6

Example 5:
Input: 100
Count multiples of 5: 100 ÷ 5 = 20
Count extra from multiples of 25: 100 ÷ 25 = 4
Count extra from multiples of 125: 100 ÷ 125 = 0
Total trailing zeros = 20 + 4 = 24

So 100! has 24 trailing zeros.

#endif