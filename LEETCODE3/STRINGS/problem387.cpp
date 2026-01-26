// First Unique Character in a string

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int count[26] = {0};
        for(char c: s)
            count[c - 'a']++;

        for(int i = 0; i<s.length(); i++)
            if(count[s[i] - 'a'] == 1)
                return i;
        return -1;
    }
};


/*
    TEST CASE 1: Standard Case (Multiple Repeating, One Unique)
    Input: "leetcode"
    - Frequency Map: {l:1, e:3, t:1, c:1, o:1, d:1}
    - Scan string from left to right:
      1. 'l' -> check map -> count is 1! 
    - Output: 0 (index of 'l')
    Expected Result: 0

    TEST CASE 2: Multiple Unique Characters
    Input: "loveleetcode"
    - Frequency Map: {l:2, o:2, v:1, e:4, t:1, c:1, d:1}
    - Scan string from left to right:
      1. 'l' -> count 2 (skip)
      2. 'o' -> count 2 (skip)
      3. 'v' -> count 1 (MATCH!)
    - Output: 2 (index of 'v')
    Expected Result: 2

    TEST CASE 3: No Unique Characters
    Input: "aabb"
    - Frequency Map: {a:2, b:2}
    - Scan string: No character has a count of 1.
    Expected Result: -1

    TEST CASE 4: Unique Character at the very end
    Input: "abcabcx"
    - Frequency Map: {a:2, b:2, c:2, x:1}
    - Scan string: 'x' is the only one with count 1.
    Expected Result: 6

    TEST CASE 5: All characters are unique
    Input: "abc"
    - Frequency Map: {a:1, b:1, c:1}
    - Scan string: 'a' is the first one encountered with count 1.
    Expected Result: 0
*/