// Binary Tree Maximum Path Sum

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxpathdown(root, maxi);
        return maxi;
    }

    int maxpathdown(TreeNode* root, int &maxi){
        if(root == NULL)    
            return 0;
        int lh = max(0, maxpathdown(root->left, maxi));
        int rh = max(0, maxpathdown(root->right, maxi));

        maxi = max(maxi, lh + rh + root->val);
        return max(lh, rh) + root->val;
    }
};

/*
In C++, the 0 at the start of max(0, lh, rh) (or more formally std::max({0, lh, rh})) acts as a 
lower bound or a floor value. 
It means the function will return the largest of the three values, ensuring that the result is 
never less than zero, even if both lh and rh are negative. 
*/

/*
    Let's use a simple but tricky example: Tree: [-10, 9, 20, null, null, 15, 7]
    WALKTHROUGH: Max Path Sum
    -------------------------
    INITIAL STATE: maxi = INT_MIN

    STEP 1: Leaf Node (9)
    - Left sum = 0, Right sum = 0.
    - Path THROUGH 9: 0 + 0 + 9 = 9.
    - Update maxi: max(INT_MIN, 9) -> maxi = 9.
    - RETURN to parent: 9 + max(0, 0) = 9.

    STEP 2: Right-side Leaf (15)
    - Left/Right = 0.
    - Path THROUGH 15: 15.
    - Update maxi: max(9, 15) -> maxi = 15.
    - RETURN to parent: 15.

    STEP 3: Right-side Leaf (7)
    - Left/Right = 0.
    - Path THROUGH 7: 7.
    - Update maxi: max(15, 7) -> maxi = 15.
    - RETURN to parent: 7.

    STEP 4: Node (20)
    - Recieved from Left (15): 15
    - Recieved from Right (7): 7
    - Path THROUGH 20 (The Curve): 15 + 7 + 20 = 42.
    - Update maxi: max(15, 42) -> maxi = 42.
    - RETURN to parent (The Line): 20 + max(15, 7) = 35.

    STEP 5: Root Node (-10)
    - Recieved from Left (9): 9
    - Recieved from Right (35): 35
    - Path THROUGH -10 (The Curve): 9 + 35 + (-10) = 34.
    - Update maxi: max(42, 34) -> maxi = 42.
    - RETURN: (Irrelevant now, but it would be 35 + (-10) = 25).

    FINAL RESULT: 42
*/

/*
    TEST CASE 1: The "Curved" Winner
    Input: [1, 2, 3]
    - Node 2 returns 2 to Root.
    - Node 3 returns 3 to Root.
    - Root (1) calculates curve: 2 + 3 + 1 = 6.
    Expected Result: 6

    TEST CASE 2: The "Negative Root" (Root is the Bridge)
    Input: [-10, 9, 20, null, null, 15, 7]
    - Node 9 returns 9.
    - Node 20 calculates its own curve: 15 + 7 + 20 = 42. (Maxi becomes 42)
    - Node 20 returns its best line: 20 + 15 = 35.
    - Root (-10) calculates curve: 9 + 35 + (-10) = 34.
    - 42 is still bigger than 34.
    Expected Result: 42

    TEST CASE 3: All Negative Nodes
    Input: [-3]
    - The code must return -3, not 0. 
    - This is why maxi starts at INT_MIN.
    Expected Result: -3

    TEST CASE 4: Ignoring a "Bad" Branch
    Input: [2, -1]
    - Node -1 returns max(0, -1) = 0.
    - Root (2) calculates curve: 0 (from left) + 0 (from right) + 2 = 2.
    - Basically, we "ignore" the -1 branch because it only makes things worse.
    Expected Result: 2

    TEST CASE 5: The Zig-Zag Path
    Input: [5, 4, 8, 11, null, 13, 4, 7, 2, null, null, null, 1]
    - Looks for the highest total along any connected sequence of nodes.
    - Can be a path like 7 -> 11 -> 4 -> 5 -> 8 -> 13.
    Expected Result: 48 
*/