// move zeroes

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        for(int fast = 0; fast < nums.size(); fast++){
            if(nums[fast] != 0){
                swap(nums[slow], nums[fast]);
                slow++;
            }
        }
    }
};

// --- TEST CASE 1: Standard Mixed Array ---
// Input: {0, 1, 0, 3, 12}
// Explanation: The 1, 3, and 12 must stay in that order. 
// The two zeros are pushed to the back.
// Expected Output: {1, 3, 12, 0, 0}

// --- TEST CASE 2: No Zeroes Present ---
// Input: {1, 2, 3, 4, 5}
// Explanation: Since there are no zeros, the array remains exactly the same.
// Expected Output: {1, 2, 3, 4, 5}

// --- TEST CASE 3: All Zeroes ---
// Input: {0, 0, 0}
// Explanation: Moving zeros to the end of a pile of zeros changes nothing.
// Expected Output: {0, 0, 0}

// --- TEST CASE 4: Zeroes Already at the End ---
// Input: {4, 5, 0, 0}
// Explanation: The array is already in the desired state.
// Expected Output: {4, 5, 0, 0}

// --- TEST CASE 5: Single Element (Zero) ---
// Input: {0}
// Explanation: Minimal case. A single zero is already at the "end."
// Expected Output: {0}

// --- TEST CASE 6: Zero at the Beginning ---
// Input: {0, 7}
// Explanation: The zero must swap or shift so the 7 comes first.
// Expected Output: {7, 0}