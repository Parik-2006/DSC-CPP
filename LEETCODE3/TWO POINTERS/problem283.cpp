// Move Zeroes to end
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        for(int fast = 0; fast < nums.size(); fast++){
            if(nums[fast] != 0){
                swap(nums[slow], nums[fast]);
                slow++;
            }
        }
    }
};

int main(){
    vector <int> name = {1,2,0,4,5,6};
    Solution obj;
    obj.moveZeroes(name);

    for(int num: name)
        cout << num << " ";
    cout << endl;
    return 0;
}

// --- TEST CASE 1: Multiple Zeros scattered ---
    // Input: {0, 1, 0, 3, 12}
    // Expected Output: 1 3 12 0 0

// --- TEST CASE 2: No Zeros present ---
    // Input: {1, 2, 3, 4}
    // Expected Output: 1 2 3 4