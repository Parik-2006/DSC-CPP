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

/*
The **Dutch National Flag algorithm** gets its name from the flag of the Netherlands, 
which has **three horizontal stripes**—red, white, and blue. Just like the flag neatly 
separates colors into three distinct bands, this algorithm organizes an array into three 
sections (0s, 1s, and 2s) in a single pass. Each value corresponds to a “color,” and the 
algorithm ensures all identical values are grouped together in order, mimicking how the flag 
is visually partitioned. The idea was popularized by Edsger W. Dijkstra, who designed it as 
an efficient way to solve this three-way partitioning problem using pointers.
*/

// Example:
// Input: nums = [2,0,1,2,0,1]
// Think of:
// 0 → Red stripe
// 1 → White stripe
// 2 → Blue stripe
//
// After applying Dutch National Flag algorithm:
// Output: [0,0,1,1,2,2]
//
// Just like the Netherlands flag:
// [Red | White | Blue]
// the array becomes:
// [0s   | 1s    | 2s]

