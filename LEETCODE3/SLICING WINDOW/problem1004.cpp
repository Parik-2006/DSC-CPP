// max consecutive ones 111

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, max_length = 0, zero = 0;
        for(int right = 0; right < nums.size(); right++){
            if(nums[right] == 0) 
                zero++;
            while(zero > k){
                if(nums[left] == 0)
                    zero--;
                left++;
            }
        max_length = max(max_length, right - left + 1);
        }
    return max_length; 
    }
};

#if 0 
Got the same question in my interview. Instead of 0 1, it was W and H (working day and holidays)
and I had to tell longest consecutive holidays that I can take if I can take at most 2 leaves.
The follow question was, what if the same calendar was being followed for the next year as well,
how would tell the longest consecutive holidays now.

/*
    TEST CASE 1: k is larger than number of zeros
    Input: [1, 0, 1], k = 2
    - We can flip all zeros. 
    Expected Result: 3

    TEST CASE 2: k is 0
    Input: [1, 0, 1, 1, 0], k = 0
    - We cannot flip any zeros. We just find the longest existing streak of 1s.
    Expected Result: 2

    TEST CASE 3: Array of all zeros
    Input: [0, 0, 0], k = 1
    - Window can only ever be size 1.
    Expected Result: 1
*/
#endif