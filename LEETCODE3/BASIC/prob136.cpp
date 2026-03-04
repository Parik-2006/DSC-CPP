// Single Number

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xor1 = 0;
        for(int i = 0; i<nums.size(); i++){
            xor1 ^= nums[i];
        }
    return xor1;
    }
};

// --- TEST CASE 1: Standard case (Small) ---
// Input: {2, 2, 1}
// Explanation: The number 2 appears twice, while 1 appears only once.
// Expected Output: 1

// --- TEST CASE 2: Multiple pairs ---
// Input: {4, 1, 2, 1, 2}
// Explanation: 1 and 2 both appear twice. 4 is the unique element.
// Expected Output: 4

// --- TEST CASE 3: Single element array ---
// Input: {1}
// Explanation: Since there is only one element, it is by default the "single" number.
// Expected Output: 1

// --- TEST CASE 4: Negative numbers ---
// Input: {-1, -1, -2}
// Explanation: XOR logic works exactly the same way for negative integers.
// Expected Output: -2

// --- TEST CASE 5: Unsorted with larger values ---
// Input: {10, 25, 10, 3, 25}
// Explanation: The position doesn't matter; the duplicates will still cancel out.
// Expected Output: 3