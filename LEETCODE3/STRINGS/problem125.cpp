// Valid Palindrome

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while(left < right){
            if(!isalnum(s[left]))
                left++;
            else if(!isalnum(s[right]))
                right--;
            else{
                if(tolower(s[left]) != tolower(s[right]))
                    return false;
                left++;
                right--;
            }
        }
        return true;
    }
};

/*
    TEST CASE 1: Standard Palindrome (with mixed cases & symbols)
    Input: "A man, a plan, a canal: Panama"
    - Step 1 (Filtering): Only letters/numbers -> "amanaplanacanalpanama"
    - Step 2 (Lowercase): "amanaplanacanalpanama"
    - Step 3 (Checking): Left 'a' == Right 'a', Left 'm' == Right 'm'...
    Expected Result: true

    TEST CASE 2: Not a Palindrome
    Input: "race a car"
    - Step 1 (Filtering): "raceacar"
    - Step 2 (Checking): 'r' == 'r', 'a' == 'a', 'c' == 'c', BUT 'e' != 'a'
    Expected Result: false

    TEST CASE 3: Empty or Single Space
    Input: " "
    - Step 1 (Filtering): Becomes an empty string ""
    - Rule: An empty string is considered a valid palindrome.
    Expected Result: true

    TEST CASE 4: Only Symbols/Non-Alphanumeric
    Input: ".,;:"
    - Step 1 (Filtering): Becomes empty.
    Expected Result: true

    TEST CASE 5: Numbers Included
    Input: "0P"
    - Step 1: '0' and 'P' are both alphanumeric.
    - Step 2: Compare '0' and 'p'. They are different.
    Expected Result: false

    TEST CASE 6: Numeric Palindrome
    Input: "12321"
    - All match perfectly.
    Expected Result: true
*/