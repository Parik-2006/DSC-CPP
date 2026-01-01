// TwoSum Problem
// Finding Target for Sorted Array only
#include <bits/stdc++.h>
using namespace std;

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

int main(){
    vector <int> nums = {1,2,3,4,5,6};
    int target = 13;
    bool result = twosum(nums,target);
    if(result)
        cout << "Target Found.." << endl;
    else    
        cout << "Target Not Found!!" << endl;
    return 0;
}

#if 0
Time Complexity : 0(n)
Space Complexity: 0(1)
#endif