// rotate array

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverse(vector<int> &nums, int start, int end){
        while(start <= end){
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums,0,n-1);
        reverse(nums,0, k-1);
        reverse(nums,k, n-1);
    }
};

// --- TEST CASE 1: Standard rotation ---
// Input: nums = {1, 2, 3, 4, 5, 6, 7}, k = 3
// Logic: Each element moves 3 steps to the right. 
// {5, 6, 7} wrap around to the front.
// Expected Output: {5, 6, 7, 1, 2, 3, 4}

// --- TEST CASE 2: k is larger than array size ---
// Input: nums = {1, 2}, k = 3
// Logic: k % nums.size() -> 3 % 2 = 1. 
// Rotating by 3 is the same as rotating by 1.
// Expected Output: {2, 1}

// --- TEST CASE 3: k is a multiple of array size ---
// Input: nums = {1, 2, 3}, k = 3
// Logic: k % nums.size() -> 3 % 3 = 0.
// Rotating by the exact length results in the original array.
// Expected Output: {1, 2, 3}

// --- TEST CASE 4: Negative numbers and small k ---
// Input: nums = {-1, -100, 3, 99}, k = 2
// Logic: {3, 99} move to the front.
// Expected Output: {3, 99, -1, -100}

// --- TEST CASE 5: Single element array ---
// Input: nums = {1}, k = 100
// Logic: No matter how many times you rotate 1 element, it stays the same.
// Expected Output: {1}