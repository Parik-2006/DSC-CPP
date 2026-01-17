// minimum size subarray sum

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int sum = 0;

        int min_length = INT_MAX;

        for(int right = 0; right < n; right++){
            sum += nums[right];
            while(sum >= target){
                int cws = right - left + 1;
                min_length = min(min_length, cws);

                sum -= nums[left];
                left++;
            }
        }
        return (min_length == INT_MAX)? 0 : min_length;
    }
};

/*
    TEST CASE 1: Standard Case (The sum hits target and shrinks)
    Input: target = 7, nums = [2, 3, 1, 2, 4, 3]
    - Window [2, 3, 1, 2] hits sum 8 (Len 4)
    - Window [3, 1, 2, 4] hits sum 10 -> shrinks to [1, 2, 4] sum 7 (Len 3)
    - Window [2, 4, 3] hits sum 9 -> shrinks to [4, 3] sum 7 (Len 2)
    Expected Result: 2

    TEST CASE 2: No Possible Solution (Triggers the INT_MAX -> 0 check)
    Input: target = 100, nums = [1, 2, 3, 4, 5]
    - Even adding all numbers only gives 15.
    - current_sum never hits 100, so min_length stays INT_MAX.
    Expected Result: 0

    TEST CASE 3: Single Element satisfies target
    Input: target = 4, nums = [1, 4, 4]
    - Window [1, 4] hits sum 5 -> shrinks to [4] sum 4 (Len 1)
    - The code should immediately find that a single element works.
    Expected Result: 1

    TEST CASE 4: Entire Array is the target
    Input: target = 15, nums = [1, 2, 3, 4, 5]
    - Only hits the target when the right pointer reaches the very end.
    - Cannot shrink at all.
    Expected Result: 5
*/

/*
 * CONCEPT: THE VARIABLE-SIZE SLIDING WINDOW (ACCORDION)
 * ----------------------------------------------------
 * The goal is to find the SHORTEST "slice" of the array that sums 
 * up to at least the 'target' value.
 *
 * 1. THE "EXPLORER" (Right Pointer):
 * We start walking through the array from left to right. This pointer 
 * expands our window, adding numbers to a 'current_sum' as it goes.
 *
 * 2. THE "CONDITION":
 * As soon as our 'current_sum' hits or exceeds the target, we stop 
 * expanding and look at the window we've made.
 *
 * 3. THE "OPTIMIZER" (Left Pointer):
 * Once the sum is large enough, we try to make the window SHORTER. 
 * We do this by removing numbers from the back (left side). 
 * We keep removing numbers as long as the sum stays above the target.
 * This is how we find the "minimum" size.
 *
 * 4. THE MEANING OF 'INT_MAX':
 * In programming, when we look for a MINIMUM, we need a starting 
 * comparison point. If we started at 0, every window would be 
 * "larger" than 0, and we'd never find the answer.
 *
 * Think of 'INT_MAX' as "Positive Infinity." It represents a 
 * value so large (2,147,483,647) that the very first valid window 
 * we find (no matter how long it is) will definitely be smaller 
 * than it. 
 *
 * 5. THE FINAL CHECK:
 * At the end, we look at our best result. If it is STILL 'INT_MAX', 
 * it means we never found a window that hit the target sum. 
 * In that case, we return 0.
 */