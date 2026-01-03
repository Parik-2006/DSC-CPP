// jan 2 2026
// n repeated element in size 2n array
// array olage yavdo ondu number du duplicate element iratte .. adna kanhiddu duplicate value yaavdu annadu return madbeku

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n  = nums.size();
        for(int i = 0; i < n - 1; i++){
            if(nums[i] == nums[i+1] || 
            (i+2 < n && nums[i] == nums[i+2])){
                return nums[i];
            }
        }
        return nums[0];
    }
};
// time complexity = 0(1)

int main(){
    return 0;
}

// Example 1:
// Input: nums = [1, 2, 3, 3]
// Output: 3

// Example 2:
// Input: nums = [2, 1, 2, 5, 3, 2]
// Output: 2

// Example 3:
// Input: nums = [5, 1, 5, 2, 5, 3, 5, 4]
// Output: 5

// Example 4:
// Input: nums = [9, 9, 1, 2]
// Output: 9

// Example 5:
// Input: nums = [7, 3, 7, 4, 7, 5]
// Output: 7
