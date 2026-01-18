// number of subarrays of size k and average greater than or equal to threshold

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold){
        int count = 0, sum = 0;
        int avg = k * threshold;
        for(int i = 0; i < k; i++)
            sum+=arr[i];
        if(sum >= avg)
            count++;
        for(int i = k; i < arr.size(); i++){
            sum+=arr[i] - arr[i - k];
            if(sum >= avg)
                count++;
        }
        return count;
    }
};


/*
Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
Output: 3
 * TARGET SUM: k * threshold = 3 * 4 = 12
 * * Window 1: [2, 2, 2] -> Sum = 6
 * Is 6 >= 12? NO.
 *
 * Window 2: [2, 2, 2] -> Sum = 6 (Added 2, Removed 2)
 * Is 6 >= 12? NO.
 *
 * Window 3: [2, 2, 5] -> Sum = 9 (Added 5, Removed 2)
 * Is 9 >= 12? NO.
 *
 * Window 4: [2, 5, 5] -> Sum = 12 (Added 5, Removed 2)
 * Is 12 >= 12? YES! (count = 1)
 *
 * Window 5: [5, 5, 5] -> Sum = 15 (Added 5, Removed 2)
 * Is 15 >= 12? YES! (count = 2)
 *
 * Window 6: [5, 5, 8] -> Sum = 18 (Added 8, Removed 5)
 * Is 18 >= 12? YES! (count = 3)
 *
 * FINAL RESULT: 3
 */

/*
 * OPTIMIZATION: SUM vs. AVERAGE
 * -----------------------------
 * Why do we use 'sum >= k * threshold' instead of 'sum / k >= threshold'?
 * * 1. AVOID FLOATING POINT MATH:
 * Dividing integers (sum / k) can cause "Truncation Error" in C++. 
 * For example, if sum is 11 and k is 3:
 * 11 / 3 = 3 (as an integer), but the real average is 3.66.
 * To fix this, you'd need to use 'double', which is slower and uses more memory.
 * * 2. SPEED (Performance):
 * Division is one of the most "expensive" operations for a CPU. 
 * Multiplication is much faster. By calculating 'k * threshold' once 
 * at the beginning, we save the CPU from performing a division 
 * operation every single time the window slides.
 * * 3. THE ALGEBRA:
 * Average = Sum / k
 * Condition: Average >= Threshold
 * Substitute: (Sum / k) >= Threshold
 * Multiply both sides by k: Sum >= (Threshold * k)
 * * EXAMPLE:
 * If k = 3 and threshold = 4, then k * threshold = 12.
 * Any window with a sum of 12 or more is "Good."
 */

 /*
 * THE STRATEGY: FIXED-SIZE SLIDING WINDOW
 * --------------------------------------
 * * 1. MATHEMATICAL OPTIMIZATION (The "Avg to Sum" trick):
 * Instead of calculating the average (sum / k) every single time, 
 * we pre-calculate a "Target Sum" (k * threshold). 
 * If our window's sum is greater than or equal to this Target Sum, 
 * then we know the average must be greater than or equal to the threshold. 
 * This keeps our math simple and avoids slow division.
 *
 * 2. THE INITIAL WINDOW:
 * We use a single loop to sum up the very first 'k' elements. 
 * This gives us the starting point for our window. We check if 
 * this first window meets our criteria; if it does, we start our 
 * count at 1.
 *
 * 3. THE "SLIDE" (Constant Time Update):
 * Now we move the window across the rest of the array. To do this 
 * efficiently, we don't re-calculate the sum. We simply:
 * - ADD the next number entering the window from the right.
 * - SUBTRACT the number that just left the window from the left.
 * This "addition-subtraction" pair keeps our sum accurate without 
 * having to loop through the window again.
 *
 * 4. THE CHECK:
 * Every time we slide and update the sum, we compare it against our 
 * pre-calculated 'avg' (which is actually our target sum). If it 
 * qualifies, we increment our counter.
 *
 * 5. RETURN:
 * After one single pass through the array, we have our final count.
 */