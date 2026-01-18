// substrings of size three with distinct characters

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countGoodSubstrings(string s) {
        int count = 0;
        for(int i = 0; i <= (int)s.size() - 3; i++){
            char a = s[i];
            char b = s[i+1];
            char c = s[i+2];

            if(a!=b && a!=c && b!=c)
                count++;
        }
    return count;
    }
};

/*
 * TRACE: s = "xyzzaz"
 * -------------------
 * Window 1: s[0,1,2] -> "xyz" 
 * 'x' != 'y', 'x' != 'z', 'y' != 'z' -> YES! (count = 1)
 *
 * Window 2: s[1,2,3] -> "yzz" 
 * 'y' != 'z', but 'z' == 'z' -> NO
 *
 * Window 3: s[2,3,4] -> "zza" 
 * 'z' == 'z' -> NO
 *
 * Window 4: s[3,4,5] -> "zaz" 
 * 'z' == 'z' -> NO
 *
 * FINAL RESULT: 1
 */

/*
Boundary conditions: You learn that for a window of size $K$, you must stop your loop at N - K 
so you don't run off the end of the string.
*/