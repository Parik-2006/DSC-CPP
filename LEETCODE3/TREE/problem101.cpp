// SYMETRIC TREE
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
    bool isMirror(TreeNode* root1, TreeNode* root2){
        if(root1 == NULL && root2 == NULL)
            return true;
        if(root1 == NULL || root2 == NULL || 
        root1->val != root2->val)
            return false;
        return isMirror(root1->left, root2->right) &&
        isMirror(root1->right, root2->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return isMirror(root->left, root->right);
    }
};

/*
    TEST CASE 1: Perfect Symmetry
    Input: [1, 2, 2, 3, 4, 4, 3]
    - Root: 1
    - Level 1: Left 2 matches Right 2.
    - Level 2: Far-Left 3 matches Far-Right 3.
    - Level 2: Inner-Left 4 matches Inner-Right 4.
    Expected Result: true

    TEST CASE 2: Value Mismatch
    Input: [1, 2, 2, null, 3, null, 3]
    - Level 1: Left 2 and Right 2 match.
    - Level 2: Left child of Left is NULL, but Right child of Right is 3.
    - (NULL vs 3) -> MISMATCH!
    Expected Result: false

    TEST CASE 3: Structural Asymmetry
    Input: [1, 2, 2, 2, null, 2]
    - Even though all values are '2', the shapes don't mirror.
    - The left side has a left-child '2', but the right side doesn't have a right-child '2'.
    Expected Result: false
*/