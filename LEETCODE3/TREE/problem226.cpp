// Invert Binary Tree

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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return nullptr;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

/*
 * CONCEPT: THE MIRROR EFFECT
 * --------------------------
 * Imagine you are standing at the top of the tree (the Root).
 * * 1. You take the entire left branch and the entire right branch 
 * and you physically swap their positions.
 * * 2. Now, you look at your new left child and say: 
 * "Okay, now you do the same thing to your own children."
 * * 3. Then you look at your new right child and say: 
 * "You do the same."
 * * This continues all the way down to the bottom. Once every 
 * single parent has swapped its two kids, the entire tree 
 * looks like a mirror image of what it used to be.
 *
 * EXAMPLE:
 * 4                 4
 * /   \             /   \
 * 2     7    ===>   7     2
 * / \   / \         / \   / \
 * 1   3 6   9       9   6 3   1
 */