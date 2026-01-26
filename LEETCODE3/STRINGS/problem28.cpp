// Find Index of First Occurrence in a String

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
    int left = haystack.length();
    int right = needle.length();

    for(int i = 0; i <= left - right ; i++){
        if(haystack.substr(i, right) == needle)
            return i;
    } 
    return -1;  
    }
};



/*
    TEST CASE 1: Standard Match at Start
    Input: haystack = "sadbutsad", needle = "sad"
    - "sad" is found at index 0.
    - Even though "sad" appears again at index 6, we return 0.
    Expected Result: 0

    TEST CASE 2: Match in the Middle
    Input: haystack = "hello", needle = "ll"
    - index 0: "he" != "ll"
    - index 1: "el" != "ll"
    - index 2: "ll" == "ll" (MATCH!)
    Expected Result: 2

    TEST CASE 3: No Match
    Input: haystack = "leetcode", needle = "leeto"
    - "leeto" is almost there, but the last 'o' doesn't exist in "leetcode".
    Expected Result: -1

    TEST CASE 4: Needle is Larger than Haystack
    Input: haystack = "abc", needle = "abcd"
    - A 4-letter word cannot fit inside a 3-letter word.
    Expected Result: -1

    TEST CASE 5: Needle is Empty String (Corner Case)
    Input: haystack = "any", needle = ""
    - Usually, an empty needle is considered to be at index 0.
    Expected Result: 0
*/

/*
    WALKTHROUGH: Finding "ple" inside "apple"
    -----------------------------------------
    
    PRE-LOOP SETUP:
    - Haystack (The big string): "a p p l e" (Indices: 0, 1, 2, 3, 4)
    - Needle (The target): "p l e" (Length = 3)
    - Stop Point: 5 - 3 = Index 2. 
      (We stop at 2 because if we start at 3, there aren't 3 letters left!)

    STEP 1: Starting at Index 0
    - Window view: [a p p] l e
    - Comparison: Is "app" exactly the same as "ple"?
    - Result: NO. (Slide the window right...)

    STEP 2: Starting at Index 1
    - Window view: a [p p l] e
    - Comparison: Is "ppl" exactly the same as "ple"?
    - Result: NO. (Slide the window right...)

    STEP 3: Starting at Index 2 (THE FINAL STOP)
    - Window view: a p [p l e]
    - Comparison: Is "ple" exactly the same as "ple"?
    - Result: YES! MATCH FOUND.

    CONCLUSION:
    - The computer stops immediately.
    - It reports "2" because that is the starting index where the match began.
*/