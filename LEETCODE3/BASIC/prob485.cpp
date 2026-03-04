// Max Consecutive Ones
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0, cnt = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 1){
                cnt++;
                maxi = max(maxi,cnt);
            } else {
                cnt = 0;
            }
        }
    return maxi;
    }
};

// --- TEST CASE 1: Multiple groups of 1s ---
// Input: {1, 1, 0, 1, 1, 1}
// Logic: First group is size 2, second group is size 3. 
// Max(2, 3) = 3.
// Expected Output: 3

// --- TEST CASE 2: Single 1 at the end ---
// Input: {1, 0, 1, 1, 0, 1}
// Logic: Streaks are of size 1, 2, and 1.
// Expected Output: 2

// --- TEST CASE 3: No 1s in the array ---
// Input: {0, 0, 0}
// Logic: The counter never increments.
// Expected Output: 0

// --- TEST CASE 4: All 1s (Perfect Streak) ---
// Input: {1, 1, 1, 1}
// Logic: The streak never breaks, so the total length is the answer.
// Expected Output: 4

// --- TEST CASE 5: Single element (Zero) ---
// Input: {0}
// Logic: Minimal case with no ones.
// Expected Output: 0

// --- TEST CASE 6: Alternating bits ---
// Input: {1, 0, 1, 0, 1}
// Logic: Every streak is broken immediately. Max length is 1.
// Expected Output: 1