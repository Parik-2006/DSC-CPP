// check if array is sorted and rotated

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int drops = 0;
        for(int i = 0; i<n; i++)
            if(nums[i] > nums[(i+1) % n])
                drops++;
    return drops <=1;
    }
};

// --- TEST CASE 1: Standard Rotated Sorted Array ---
// Input: {3, 4, 5, 1, 2}
// Explanation: 5 -> 1 is the only drop. Wrap-around 2 -> 3 is fine.
// Expected: true (Drops = 1)

// --- TEST CASE 2: Already Sorted (Zero Rotations) ---
// Input: {1, 2, 3}
// Explanation: No drops in the middle. Wrap-around 3 -> 1 is the only drop.
// Expected: true (Drops = 1)

// --- TEST CASE 3: Multiple "Drop" Points (Broken) ---
// Input: {2, 1, 3, 4}
// Explanation: 2 -> 1 is a drop, and wrap-around 4 -> 2 is a second drop.
// Expected: false (Drops = 2)

// --- TEST CASE 4: Sorted with Duplicates ---
// Input: {1, 1, 1, 2, 2}
// Explanation: No drops in the middle. Wrap-around 2 -> 1 is the only drop.
// Expected: true (Drops = 1)

// --- TEST CASE 5: Rotated with Duplicates ---
// Input: {2, 2, 3, 1, 1}
// Explanation: 3 -> 1 is the only drop. Wrap-around 1 -> 2 is fine.
// Expected: true (Drops = 1)