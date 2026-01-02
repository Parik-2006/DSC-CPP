// remove duplicated elements and return no of unique elements for non descending sorted arrays
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int removeDuplicates(vector <int> &nums){
            if(nums.empty()) return 0;
            int slow = 0;
            for(int fast = 1; fast < nums.size(); fast++){
                if(nums[fast] != nums[slow]){
                    nums[++slow] = nums[fast];
                }
            }
            return slow+1;
        }
};

int main(){
    Solution obj;
    vector <int> nums1 = {1,1,2,2,3,4,4};
    cout << "Elements before removing Duplicates: ";
    for(int i = 0; i<nums1.size(); i++)
        cout << nums1[i] << " ";
    cout << endl;
    int result = obj.removeDuplicates(nums1);
    cout << "Unique Elements: " << result << endl;
    cout << "Elements after removing Duplicates: ";
    for(int i = 0; i<nums1.size(); i++)
        cout << nums1[i] << " ";
    
    cout << endl;
    return 0;
}



// --- TEST CASE 1: Standard case with multiple duplicates ---
    // Input: {1, 1, 2, 2, 3, 4, 4}
    // Expected k = 4 (Unique: 1, 2, 3, 4)

// --- TEST CASE 2: No duplicates ---
    // Input: {1, 2, 3}
    // Expected k = 3 (Unique: 1, 2, 3)

// --- TEST CASE 3: All elements are the same ---
    // Input: {1, 1, 1, 1}
    // Expected k = 1 (Unique: 1)