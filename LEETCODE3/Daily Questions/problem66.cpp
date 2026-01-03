// jan 1 2026
// plus one 
// array iratte .. ond number du individual element na array li store madirtare .. adke last alli +1 maadbeku .. carry bandre handle maadbeku


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i = digits.size() - 1; i>=0; i--){
            if(digits[i] + carry > 9){
                digits[i] = 0;
                carry = 1;
            } else {
                digits[i] += carry;
                carry = 0;
                break;
            }
        }

        if(carry == 1){
            vector<int> result(digits.size() + 1);
            result[0] = 1;
            for(int i = 1; i<result.size(); i++){
                result[i] = digits[i-1];
            }
            return result;
        }
        return digits;
    }
};

// time complexity = 0(n)

int main(){

}


// Test Case 1:
// Input: digits = [1,2,3]
// Output: [1,2,4]

// Test Case 2:
// Input: digits = [4,3,2,1]
// Output: [4,3,2,2]

// Test Case 3:
// Input: digits = [9]
// Output: [1,0]

// Test Case 4:
// Input: digits = [9,9]
// Output: [1,0,0]

// Test Case 5:
// Input: digits = [0]
// Output: [1]

// Test Case 6:
// Input: digits = [1,9,9]
// Output: [2,0,0]

// Test Case 7:
// Input: digits = [8,9,9,9]
// Output: [9,0,0,0]

// Test Case 8:
// Input: digits = [9,9,9,9,9]
// Output: [1,0,0,0,0,0]

// Test Case 9:
// Input: digits = [2,3,9,9]
// Output: [2,4,0,0]

// Test Case 10 (Edge case – large carry propagation):
// Input: digits = [9,9,9,9,9,9,9]
// Output: [1,0,0,0,0,0,0,0]
