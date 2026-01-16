// Binary Search

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                low = mid + 1;
            else 
                high = mid - 1;
        }
        return -1;
    }
};

/*
    TEST CASE 1: Target exists
    Input: nums = [-1, 0, 3, 5, 9, 12], target = 9
    - Left=0, Right=5, Mid=2 (val 3). 3 < 9, so Left=3.
    - Left=3, Right=5, Mid=4 (val 9). 9 == 9. Match!
    Expected Result: 4

    TEST CASE 2: Target does not exist
    Input: nums = [-1, 0, 3, 5, 9, 12], target = 2
    - 3 is too big, move Right to index 1.
    - 0 is too small, move Left to index 1.
    - Search continues until left > right.
    Expected Result: -1
*/