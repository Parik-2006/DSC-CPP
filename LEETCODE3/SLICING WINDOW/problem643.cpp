// maximum average subarray 1
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        for(int i = 0; i<k ; i++)
            sum += nums[i];

        double max_sum = sum;
        for(int i = k; i<nums.size(); i++){
            sum += nums[i] - nums[i-k];
            max_sum = max(sum, max_sum);
        }
        return max_sum/k;
    }
};


/*
    TEST CASE 1: Standard positive/negative
    Input: nums = [1, 12, -5, -6, 50, 3], k = 4
    Expected: 12.75000 (Max sum was 51, 51/4 = 12.75)

    TEST CASE 2: Single element
    Input: nums = [5], k = 1
    Expected: 5.00000

    TEST CASE 3: Decreasing values
    Input: nums = [4, 3, 2, 1], k = 2
    Expected: 3.50000 (Window [4,3] is better than [3,2] or [2,1])
*/

/*
 * SLIDING WINDOW PATTERN: FIXED SIZE
 * ----------------------------------
 * The goal is to find the maximum average of any subarray with length 'k'.
 * * THE CORE IDEA:
 * Instead of re-calculating the sum from scratch every time we move the window,
 * we observe that the "new" window is almost identical to the "old" window.
 * To get the new sum, we only need to:
 * 1. ADD the next element entering from the right.
 * 2. SUBTRACT the element that is now exiting from the left.
 * This turns an O(N*K) problem into an O(N) problem because each element 
 * is added and subtracted exactly once.
 *
 * THE PARAGRAPH TRACE (Example: [1, 3, 2, 6, -1], k=3):
 * We start by grabbing the first three numbers (1, 3, 2) which sum to 6. This is 
 * our starting "max." Now, we slide the window one position to the right. To do 
 * this efficiently, we look at the next number (6) and add it to our sum, while 
 * simultaneously dropping the very first number (1) from the back. Our sum 
 * jumps from 6 to 11. We compare 11 to our previous max (6) and update it. 
 * Finally, we slide one more time: we add the next number (-1) and drop the 
 * oldest number (3). Our sum drops to 7. Since 11 is still the highest sum 
 * we've seen, we keep it and divide by 3 to get our final average.
 */