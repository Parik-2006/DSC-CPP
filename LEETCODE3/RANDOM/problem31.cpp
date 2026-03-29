// next permutation of a given array of integers
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        int n = nums.size();

        for(int i = n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }

        if(index == -1){
            reverse(nums.begin(), nums.end());
            return;   // ✅ only return
        }

        for(int i = n-1; i>=0; i--){
            if(nums[i] > nums[index]){
                swap(nums[i], nums[index]);
                break;
            }
        }

        reverse(nums.begin() + index + 1, nums.end());
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)

// Input: nums = [1,2,3]
// Output: [1,3,2]

// Input: nums = [3,2,1]
// Output: [1,2,3]

// Input: nums = [1,1,5]
// Output: [1,5,1]

// Input: nums = [1,3,2]
// Output: [2,1,3]

// Input: nums = [2,3,1]
// Output: [3,1,2]