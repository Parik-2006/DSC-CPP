// longest substring without repeating character

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count [128] = {0};
        int left = 0;
        int max_len = 0;
        
        for(int right = 0; right < s.size(); right++){
            char r = s[right];
            count[r]++;

            while(count[r] > 1){
                char l = s[left];
                count[l]--;
                left++;
            }

            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};

/*
    TEST CASE 1: All Unique
    Input: "abcde"
    - Window keeps expanding, never shrinks.
    Expected Result: 5

    TEST CASE 2: All Same
    Input: "bbbbb"
    - Every time 'right' moves, it finds a duplicate and 'left' has to catch up.
    Expected Result: 1

    TEST CASE 3: The "Sandwich"
    Input: "dvdf"
    - Right hits 'd' (index 2). Window is "dvd".
    - Left must move past the first 'd' to make "vd".
    - Then 'right' adds 'f' to get "vdf".
    Expected Result: 3
*/

/*
 * CONCEPT: THE "UNIQUE SEARCHLIGHT" (SLIDING WINDOW)
 * -------------------------------------------------
 * We want to find the longest stretch of characters where NO character 
 * appears more than once.
 *
 * 1. THE TRACKER (Frequency Array):
 * We use an array of size 128 (ASCII limit) to keep track of how many 
 * times each character appears in our current window. 
 * count['a'] = 0 means 'a' is not in our window.
 * count['a'] = 1 means 'a' is in our window once.
 *
 * 2. THE EXPLORER (Right Pointer):
 * We move the 'right' pointer forward one by one, adding the new 
 * character to our tracker (count[char]++).
 *
 * 3. THE CONFLICT (While Loop):
 * If the count of the character we just added becomes 2, we have a DUPLICATE.
 * The window is now "invalid." To fix it, we must move the 'left' pointer.
 *
 * 4. THE CLEANUP (Shrinking):
 * We move the 'left' pointer forward, removing characters from the 
 * tracker (count[char]--) as we go. We keep doing this until the 
 * duplicate character's count drops back down to 1.
 *
 * 5. THE RECORD (Max Length):
 * Once the conflict is resolved, the window is "valid" (all unique).
 * We calculate the current width (right - left + 1) and compare it 
 * to our record (max_len).
 */