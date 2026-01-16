//Two Sum 2 - Input array is sorted

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while(left < right){
            int sum = numbers[left] + numbers[right];
            if(sum == target){
                return {left+1, right+1};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {};
    }
};

/*
    TEST CASE 1: Basic match
    Input: numbers = [2, 7, 11, 15], target = 9
    - left(2) + right(15) = 17 (Too big, right--)
    - left(2) + right(11) = 13 (Too big, right--)
    - left(2) + right(7)  = 9  (Match!)
    Expected: [1, 2]

    TEST CASE 2: Using negative numbers
    Input: numbers = [-1, 0], target = -1
    - left(-1) + right(0) = -1 (Match!)
    Expected: [1, 2]

    TEST CASE 3: Large gap
    Input: numbers = [5, 25, 75], target = 100
    - left(5) + right(75) = 80 (Too small, left++)
    - left(25) + right(75) = 100 (Match!)
    Expected: [2, 3]
*/