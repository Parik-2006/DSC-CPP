// Longest Repeating Character Replacement

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, maxfreq = 0, maxlen = 0;
        int count[26] = {0};
        for(int right = 0; right <s.size(); right++){
            count[s[right] - 'A']++;
            maxfreq = max(maxfreq, count[s[right] - 'A']);

            while((right-left+1) - maxfreq > k){
                count[s[left] - 'A']--;
                left++;
            }
        maxlen = max(maxlen, right - left + 1);
        }
    return maxlen;
    }
};
/*
    TEST CASE 1: Only one type of character
    Input: "AAAA", k = 2
    - max_freq is always equal to window size. Changes needed always 0.
    Expected Result: 4

    TEST CASE 2: k is 0
    Input: "AAABBC", k = 0
    - We can't change anything. It just finds the longest streak of same characters.
    Expected Result: 3

    TEST CASE 3: Alternating characters
    Input: "ABAB", k = 1
    - Window "ABA" or "BAB" works (Length 3).
    Expected Result: 3
*/