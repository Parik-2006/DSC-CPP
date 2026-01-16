// Reverse String
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
       int left = 0;
       int right = s.size() - 1;
       while(left < right){
        swap(s[left], s[right]);
        left++;
        right--;
       } 
    }
};

int main(){
    vector<char> s = {'H', 'E', 'L', 'L', 'O'};
    
    // 1. Create an object of the class
    Solution sol; 
    sol.reverseString(s);
    
    cout << "Reversed: ";
    
    // 2. Corrected Range-based for loop
    for(char c : s){
        cout << c << " ";
    }
    cout << endl;

    return 0;
}

/*
    TEST CASE 1: Odd Length String
    Input: s = ["h", "e", "l", "l", "o"]
    - Swap 'h' and 'o' -> ["o", "e", "l", "l", "h"]
    - Swap 'e' and 'l' -> ["o", "l", "l", "e", "h"]
    - Pointers meet at 'l'. Done.
    Expected: ["o", "l", "l", "e", "h"]

    TEST CASE 2: Even Length String
    Input: s = ["H", "a", "n", "n", "a", "h"]
    - Swap 'H' and 'h'
    - Swap 'a' and 'a'
    - Swap 'n' and 'n'
    Expected: ["h", "a", "n", "n", "a", "H"]

    TEST CASE 3: Single Character
    Input: s = ["A"]
    - left = 0, right = 0. Loop doesn't run.
    Expected: ["A"]
*/