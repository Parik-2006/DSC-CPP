// Sort Colors
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++, mid++;
            } else if(nums[mid] == 1){
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
#if 0
Time Complexity : 0(n)
Space Complexity: 0(1)
#endif
// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

// Input: nums = [2,0,1]
// Output: [0,1,2]

// Input: nums = [0]
// Output: [0]

// Input: nums = [1,2,0,1,2,0,1]
// Output: [0,0,1,1,1,2,2]

// Input: nums = [2,2,2,1,1,0,0]
// Output: [0,0,1,1,2,2,2]