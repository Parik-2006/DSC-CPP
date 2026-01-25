// Path Sum

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return false;
        if(root->left == NULL && root->right == NULL)
            return root->val == targetSum;
        int sum = targetSum - root->val;
        return hasPathSum(root->left, sum) ||
        hasPathSum(root->right, sum);
    }
};

/*
 * CONCEPT: THE DEPLETING BUDGET
 * ----------------------------
 * Think of 'targetSum' as a budget you MUST spend exactly by the 
 * time you reach the bottom of the tree.
 *
 * 1. SPENDING AT THE NODE:
 * Every time you visit a node, you "spend" its value from your budget.
 *
 * 2. THE LEAF REQUIREMENT:
 * You can only stop and check your wallet when you reach a LEAF 
 * (a node with no exits). If your budget is exactly 0 (or if the 
 * leaf's value matches your remaining budget), you win!
 *
 * 3. BRANCHING OUT:
 * If you have a left path and a right path, you try both. If 
 * either path leads to a "True" finish, the whole answer is True.
 *
 * EXAMPLE: targetSum = 22
 * 5       (Budget 22 - 5 = 17)
 * / \
 * 4   8     (Left budget 17-4=13 | Right budget 17-8=9)
 * /   / \
 * 11  13  4   (Leaf 11? 13 != 11. Fail. | Leaf 13? 9 != 13. Fail. | Node 4? 9-4=5)
 * /  \      \
 * 7   2      1 (Leaf 2? 2 == 2. SUCCESS!)
 */

 /*
 * PATH SUM TRACE: Target = 22
 * -------------------------------------------------------------------------
 * CALL 1: hasPathSum(Node 5, 22)
 * - Not NULL, Not a Leaf. 
 * - New Budget: 22 - 5 = 17.
 * - ACTION: Waiting for (Left || Right)...
 *
 * CALL 2: hasPathSum(Node 4, 17) [Left child of 5]
 * - Not NULL, Not a Leaf (has child 11).
 * - New Budget: 17 - 4 = 13.
 * - ACTION: Waiting for (Left || Right)...
 *
 * CALL 3: hasPathSum(Node 11, 13) [Left child of 4]
 * - Not NULL, Not a Leaf (has children 7 and 2).
 * - New Budget: 13 - 11 = 2.
 * - ACTION: Waiting for (Left || Right)...
 *
 * CALL 4: hasPathSum(Node 7, 2) [Left child of 11]
 * - IS A LEAF! 
 * - Check: Does value 7 == budget 2? 
 * - RESULT: RETURN FALSE.
 *
 * CALL 5: hasPathSum(Node 2, 2) [Right child of 11]
 * - IS A LEAF! 
 * - Check: Does value 2 == budget 2? 
 * - RESULT: RETURN TRUE.
 *
 * - CALL 3 (Node 11) receives (False || True). 
 * - RESULT: RETURN TRUE.
 *
 * - CALL 2 (Node 4) receives (True || Right-is-NULL-False).
 * - RESULT: RETURN TRUE.
 *
 * - CALL 1 (Root 5) receives (True || ...).
 * - Because of the || (OR), it doesn't even bother checking the Right side (8)!
 * - FINAL RESULT: TRUE.
 * -------------------------------------------------------------------------
 */