// three sum
#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // Sorting makes it easy to skip duplicates and use pointers
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            // OPTIMIZATION: If current number > 0, sum can never be 0 (since it's sorted)
            if (nums[i] > 0) break;

            // DUPLICATE CHECK: Skip the same starting number
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // NOW: It's just a Two Sum problem for the rest of the array
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for the next 'left' and 'right'
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    left++;
                    right--;
                } 
                else if (sum < 0) {
                    left++; // Need a bigger number
                } 
                else {
                    right--; // Need a smaller number
                }
            }
        }
        return result;
    }
};

// tc - 0(n square)