// maximum number of vowels in a substring of given length

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isvowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || 
        c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        int left = 0, count = 0, right = 0;
        for(right = 0; right < k; right++){
            if(isvowel(s[right]))
                count++;
        }

        int maxcount = count;
        for(right = k; right<s.size(); right++){
            if(isvowel(s[right]))
                count++;
            if(isvowel(s[right - k]))
                count--;
        if (maxcount == k) return k;
        maxcount = max(maxcount, count);
        }
    return maxcount;
    }
};

/*
 * TARGET: Maximize vowels in a window of size 3
 * * 1. Initial Window: "lee"
 * - 'l' (no), 'e' (yes), 'e' (yes) -> current_vowels = 2
 * - max_vowels = 2
 *
 * 2. Slide 1: Window becomes "eet" (Add 't', Remove 'l')
 * - 't' is not a vowel (+0)
 * - 'l' was not a vowel (-0)
 * - current_vowels stays 2.
 *
 * 3. Slide 2: Window becomes "etc" (Add 'c', Remove 'e')
 * - 'c' is not a vowel (+0)
 * - 'e' WAS a vowel (-1)
 * - current_vowels becomes 1.
 *
 * 4. Slide 3: Window becomes "tco" (Add 'o', Remove 'e')
 * - 'o' is a vowel (+1)
 * - 'e' WAS a vowel (-1)
 * - current_vowels stays 1.
 */

 /*
 * THE CONCEPT: THE VOWEL SCOPE
 * ----------------------------
 * Imagine you are looking at a long string of letters through a 
 * magnifying glass that only shows 'k' letters at a time. Your goal 
 * is to find the spot where you can see the most vowels (a, e, i, o, u).
 *
 * 1. THE STARTING VIEW:
 * We place our magnifying glass at the very beginning of the string. 
 * We count how many vowels are currently visible. This is our 
 * "starting score."
 *
 * 2. THE MOVEMENT (The Slide):
 * We move the magnifying glass one letter to the right. When we do 
 * this, two things happen:
 * - ONE NEW letter enters the glass from the right.
 * - ONE OLD letter exits the glass from the left.
 *
 * 3. UPDATING THE SCORE:
 * Instead of re-counting everything inside the glass, we just look 
 * at the two letters that changed:
 * - If the NEW letter is a vowel, we add 1 to our count.
 * - If the OLD letter (that just left) was a vowel, we subtract 1.
 *
 * 4. THE RECORD:
 * Every time we slide, we check if our current vowel count is higher 
 * than the best one we've seen so far. If it is, we update our record.
 *
 * 5. THE SHORTCUT:
 * If our record ever hits the same number as 'k' (the window size), 
 * we stop immediately. You can't have more vowels than the number of 
 * letters you can see!
 */