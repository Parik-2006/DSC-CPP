// TwoSum Problem
// Finding Target for Sorted Array only
#include <bits/stdc++.h>
using namespace std;


// boolean variant
bool twosum(vector<int> &nums, int target){
    int left = 0;
    int right = nums.size() - 1;

    while(left<right){
        int sum = nums[left] + nums[right];
        if(sum == target){
            return true;
        } else if(sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return false;
}

#if 0
Time Complexity : 0(n)
Space Complexity: 0(1)
#endif


// hashmap variant
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int, int> mpp;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            int num = nums[i];
            int needed = target - num;
            if(mpp.find(needed) != mpp.end())
                return {mpp[needed], i};
            mpp[num] = i;
        }
        return {-1, -1};
    }
};

#if 0
Time Complexity : 0(n logn)
Space Complexity: 0(n)
-> unordered_map is used then time complexity will be 0(n)
#endif

// two pointer variant
class Solution {
public:
    string twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        sort(nums.begin(), nums.end());
        while(left < right){
            int sum = nums[left] + nums[right];
            if(sum == target)
                return "YES";
            else if(sum < target)
                left++;
            else
                right--;
        }
        return "NO";
    }
};