// Binary Tree Inorder Traversal

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        helper(root, result);
        return result;
    }

    void helper(TreeNode* root, vector <int> &result){
        if(root == NULL)
            return;
        helper(root->left, result);
        result.push_back(root->val);
        helper(root->right, result);
    }
};

/*
    TEST CASE 1: Standard Tree
    Input: [1, null, 2, 3]
    - Inorder visits: 1 -> (Left of 2) 3 -> 2
    Expected Result: [1, 3, 2]

    TEST CASE 2: Empty Tree
    Input: []
    Expected Result: []

    TEST CASE 3: Single Node
    Input: [1]
    Expected Result: [1]

    TEST CASE 4: Balanced Tree
    Input: [1, 2, 3]
    - Visit 2, then 1, then 3.
    Expected Result: [2, 1, 3]
*/
