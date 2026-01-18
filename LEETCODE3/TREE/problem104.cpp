// Maximum Depth of Binary Tree

#include <bits/stdc++.h>
using namespace std;

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
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        return max(lh,rh)+1;
    }
};

/*
 * CONCEPT: THE DEPTH-FIRST SEARCH (RECURSION)
 * -------------------------------------------
 * Imagine you are standing at the ROOT of the tree.
 * 1. You send a scout to the left branch and a scout to the right branch.
 * 2. Each scout goes all the way to the "leaves" (the bottom).
 * 3. When a scout hits the floor (NULL), they report back "0".
 * 4. As scouts return to a parent node, the parent looks at both 
 * reports, picks the BIGGER number, and adds 1 (for themselves).
 * 5. This repeats until the final answer reaches you at the top.
 *
 * EXAMPLE:
 * 3
 * / \
 * 9  20
 * / \
 * 15  7
 *
 * - Depth of 15 is 1. Depth of 7 is 1.
 * - Node 20 sees (1, 1), picks 1, adds itself -> Depth 2.
 * - Node 9 sees (0, 0), picks 0, adds itself -> Depth 1.
 * - Root 3 sees (1, 2), picks 2, adds itself -> FINAL DEPTH 3.
 */