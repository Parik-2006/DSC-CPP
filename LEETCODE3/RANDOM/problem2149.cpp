// 2149. Rearrange Array Elements by Sign
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans(n,0);
        int posindex = 0, negindex = 1;
        for(int i = 0; i<n; i++){
            if(nums[i] < 0){
                ans[negindex] = nums[i];
                negindex += 2;
            } else {
                ans[posindex] =  nums[i];
                posindex += 2;
            }
        }
        return ans;
    }
};
#if 0 
// Input: nums = [3,1,-2,-5,2,-4]
// Output: [3,-2,1,-5,2,-4]

// Input: nums = [-1,1]
// Output: [1,-1]

// Input: nums = [1,-1,2,-2,3,-3]
// Output: [1,-1,2,-2,3,-3]

// Input: nums = [5,-3,7,-2,8,-1]
// Output: [5,-3,7,-2,8,-1]

// Input: nums = [10,-10,20,-20,30,-30]
// Output: [10,-10,20,-20,30,-30]

// Time Complexity: O(n)
// Space Complexity: O(n)
#endif


#if 0
// if elements are not equally distributed then we can put the extra elements at the end of the array
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector <int> pos, neg;
        for(int i = 0; i<n; i++){
            if(nums[i] < 0)
                neg.push_back(nums[i]);
            else
                pos.push_back(nums[i]);
        }

    if(pos.size() > neg.size()){
        for(int i = 0; i<neg.size(); i++){
            nums[2*i] = pos[i];
            nums[2*i+1] = neg[i];
        }
        int index = neg.size() * 2;
        for(int i = neg.size(); i<pos.size(); i++){
            nums[index] = pos[i];
            index++;
        }
    } else {
        for(int i = 0; i<pos.size(); i++){
            nums[2*i] = pos[i];
            nums[2*i+1] = neg[i];
        }
        int index = pos.size() * 2;
        for(int i = pos.size(); i<neg.size(); i++){
            nums[index] = neg[i];
            index++;
        }
    return nums;
    }
    }
};
#endif