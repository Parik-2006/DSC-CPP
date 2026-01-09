// container with most water

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int lp = 0;
        int rp = height.size() - 1;
        int maxarea = 0;

        while(lp < rp){
            int width = rp - lp;
            int heights = min(height[lp], height[rp]);
            int currarea = width * heights;

            maxarea = max(currarea, maxarea);

            if(height[lp] < height[rp])
                lp++;
            else 
                rp--;
        }
        return maxarea;
    }
};

// Time: O(n) 
// Space: O(1)