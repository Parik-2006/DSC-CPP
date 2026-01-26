// Valid Anagram

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;

        int count[26] = {0};
        for(int i = 0; i<s.length(); i++){
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for(int i = 0; i<26 ; i++)
            if(count[i]!=0)
                return false;
        return true;
    }
};

/*
    TEST CASE 1: True Anagram
    Input: s = "anagram", t = "nagaram"
    - Frequency: a:3, n:1, g:1, r:1, m:1 in both.
    Expected Result: true

    TEST CASE 2: Different Lengths
    Input: s = "rat", t = "car"
    - s has 3 letters, t has 3 letters.
    - BUT: s has 't', t has 'c'. Counts won't match.
    Expected Result: false

    TEST CASE 3: One String is Shorter
    Input: s = "a", t = "ab"
    - Lengths are 1 and 2. Immediate fail.
    Expected Result: false

    TEST CASE 4: Same Letters, Different Counts
    Input: s = "aabbbb", t = "aaaabb"
    - Both use 'a' and 'b', but the "budget" is different.
    Expected Result: false
*/