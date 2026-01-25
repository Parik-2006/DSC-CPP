// Merge two Binary Trees

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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL)
            return NULL;
        if(root1 == NULL)
            return root2;
        if(root2 == NULL)
            return root1;

        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right= mergeTrees(root1->right, root2->right);
        return root1;
    }
};
/*
    TEST CASE:
    Tree 1: [1, 3, 2, 5]
    Tree 2: [2, 1, 3, null, 4, null, 7]

    Merging steps:
    - Roots: 1 + 2 = 3
    - Lefts: 3 + 1 = 4
    - Rights: 2 + 3 = 5
    - Left-Left: 5 + NULL = 5
    - Left-Right: NULL + 4 = 4
    - Right-Right: NULL + 7 = 7

    Result Tree: [3, 4, 5, 5, 4, null, 7]
*/

/*
    TREE 1: [1, 2, null, 3]  (A line going down-left)
    TREE 2: [1, null, 4, null, 5] (A line going down-right)

    MERGE PROCESS:
    - Root: 1 + 1 = 2
    - Left Child: 2 (from T1) + NULL (from T2) = 2
    - Right Child: NULL (from T1) + 4 (from T2) = 4
    - Left-Left: 3 (from T1) + NULL = 3
    - Right-Right: NULL + 5 (from T2) = 5

    RESULT: [2, 2, 4, 3, null, null, 5]
*/

/*
    TREE 1: [] (Empty)
    TREE 2: [1, 2, 3]

    MERGE PROCESS:
    - The code immediately sees Tree 1 is NULL.
    - It returns all of Tree 2 exactly as it is.

    RESULT: [1, 2, 3]
*/

/*
    TREE 1: [1, 5] (Just a root and a left child)
    TREE 2: [1, 2, 3, 4] (A fuller tree)

    MERGE PROCESS:
    - Root: 1 + 1 = 2
    - Left: 5 + 2 = 7
    - Right: NULL (from T1) + 3 (from T2) = 3
    - Left-Left: NULL (from T1) + 4 (from T2) = 4

    RESULT: [2, 7, 3, 4]
*/