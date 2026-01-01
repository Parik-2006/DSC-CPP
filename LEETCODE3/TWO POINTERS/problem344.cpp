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