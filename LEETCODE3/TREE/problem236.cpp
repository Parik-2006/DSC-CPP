// Lowest Common Ancestor of Binary Tree

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q)
            return root;
        TreeNode* lh = 
        lowestCommonAncestor(root->left, p, q);
        TreeNode* rh = 
        lowestCommonAncestor(root->right, p, q);

        if(lh == NULL)
            return rh;
        else if(rh == NULL)
            return lh;
        else 
            return root;
    }
};


/*
    TEST CASE 1: Standard Split
    Input: root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4], p = 5, q = 1
    - Path to 5: 3 -> 5
    - Path to 1: 3 -> 1
    - The paths split immediately at node 3.
    Expected Result: Node 3

    TEST CASE 2: One Node is the Ancestor of the Other
    Input: root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4], p = 5, q = 4
    - Path to 5: 3 -> 5
    - Path to 4: 3 -> 5 -> 2 -> 4
    - Node 5 is actually on the path to 4. 
    - A node can be a descendant of itself!
    Expected Result: Node 5

    TEST CASE 3: Both Nodes on the Same Side (Deep Split)
    Input: root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4], p = 6, q = 4
    - Both 6 and 4 are in the left subtree of root (3).
    - Path to 6: 3 -> 5 -> 6
    - Path to 4: 3 -> 5 -> 2 -> 4
    - The "last" shared node before they split is 5.
    Expected Result: Node 5

    TEST CASE 4: Simple Tree
    Input: root = [1, 2], p = 1, q = 2
    - 1 is the parent of 2.
    Expected Result: Node 1
*/