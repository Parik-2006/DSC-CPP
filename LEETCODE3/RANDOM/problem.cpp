// Majority Element => Boyer-Moore Voting Algorithm
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int el;
        for(int i = 0; i<nums.size(); i++){
            if(cnt == 0){
                cnt = 1;
                el = nums[i];
            } else if(nums[i] == el){
                cnt++;
            } else {
                cnt--;
            }
        }

        int cnt1 = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == el){
                cnt1++;
            }
        }
        
        if(cnt1 > (nums.size()/2)){
            return el;
        }
        return -1;
    }
};


// Example: nums = [2,2,1,1,1,2,2]
//
// In the first phase, we scan the array and maintain a candidate element (el)
// and a counter (cnt). Initially, cnt is 0, so we pick the first element (2)
// as the candidate and set cnt = 1. When we see the next 2, it matches the
// candidate, so we increase cnt. When we encounter a different element (1),
// we decrease cnt, which represents cancellation between different elements.
// As we continue, whenever cnt becomes 0, it means the previous candidate has
// been completely cancelled out, so we choose a new candidate.
//
// Throughout this process, elements keep cancelling each other, but since the
// majority element appears more than n/2 times, it cannot be fully cancelled.
// Therefore, it survives as the final candidate at the end of the loop.
//
// In this example, after all cancellations, the final candidate becomes 2.
//
// In the second phase, we simply count how many times this candidate appears
// in the array. Here, 2 appears 4 times out of 7 elements, which is greater
// than n/2 (3). Hence, 2 is confirmed as the majority element.
//
// Key idea: majority element always survives cancellation because it occurs
// more than all other elements combined.


// It is called the “Voting Algorithm” because every element in the array
// can be thought of as casting a vote for itself. When we scan the array,
// if the current element is the same as the candidate, it adds a vote
// (cnt increases). If it is different, it cancels out one vote
// (cnt decreases), just like two opposing votes neutralizing each other.
//
// This process is similar to an election where different candidates receive
// votes, and opposing votes cancel out. Since the majority element has more
// than n/2 votes, it will always have more votes than all other elements
// combined, so it can never be completely cancelled. In the end, it remains
// as the final candidate, just like a winner in a voting system.
//
// Hence, the algorithm mimics a voting and cancellation process, which is
// why it is called the Boyer–Moore Voting Algorithm.