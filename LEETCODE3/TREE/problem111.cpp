// Minimum Depth of Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

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
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int lh = minDepth(root->left);
        int rh = minDepth(root->right);
        if(lh == 0 || rh == 0)
            return max(lh,rh)+1;
        return min(lh,rh)+1;
    }
};

/*
    TEST CASE 1: Balanced Tree
    Input: [3, 9, 20, null, null, 15, 7]
    - Path to 9 is length 2.
    - Path to 15 or 7 is length 3.
    Expected Result: 2

    TEST CASE 2: The "Skewed" Tree (The Trap)
    Input: [2, null, 3, null, 4, null, 5, null, 6]
    - This is just a long line to the right.
    - You must go all the way to 6 to find a leaf.
    Expected Result: 5
*/