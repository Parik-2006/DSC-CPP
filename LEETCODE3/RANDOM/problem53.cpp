// MAXIMUM SUBARRAY

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxi = INT_MIN;
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
            if(sum > maxi)
                maxi = max(sum, maxi);
            if(sum < 0)
                sum = 0;
        }
        return maxi;
    }
};

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: [4,-1,2,1] gives max sum = 6

// Input: nums = [1]
// Output: 1

// Input: nums = [5,4,-1,7,8]
// Output: 23
// Explanation: entire array gives max sum

// Input: nums = [-1,-2,-3,-4]
// Output: -1
// Explanation: pick the largest (least negative) element

// Input: nums = [2,-1,2,3,4,-5]
// Output: 10
// Explanation: [2,-1,2,3,4] gives max sum = 10

#if 0
substring return madbekandre 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxi = INT_MIN, start = 0;
        int subarray_start = 0, subarray_end = 0;
        for(int i = 0; i<nums.size(); i++){
            if(sum == 0)
                start = i;
            sum += nums[i];
            if(sum > maxi)
                maxi = max(sum, maxi);
                subarray_start = start;
                subarray_end = i;
            if(sum < 0)
                sum = 0;
        }
        return vector<int>(nums.begin() + subarray_start,
                           nums.begin() + subarray_end + 1);
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)  [excluding output]
// Space Complexity: O(n)  [including output]
#endif