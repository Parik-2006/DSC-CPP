// Sum of Left Leaves 

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
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root, false);
    }

    int helper(TreeNode* root, bool isLeft){
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return isLeft? root->val: 0;
        return helper(root->left, true) + 
        helper(root->right, false);
    }
};

/*
 * CONCEPT: THE COLOR-CODED SCOUTS
 * -------------------------------
 * Imagine you are sending scouts into a cave system (the tree).
 * * 1. THE INSTRUCTION:
 * When you send a scout to a LEFT tunnel, you give them a BLUE flag.
 * When you send a scout to a RIGHT tunnel, you give them a RED flag.
 *
 * 2. THE COLLECTOR:
 * Scouts only collect gold if they reach a DEAD END (a leaf) 
 * AND they are holding a BLUE flag (isLeft = true).
 *
 * 3. THE TOTAL:
 * Every scout returns to their parent and reports how much gold 
 * was found in their entire branch. The parent adds the two 
 * reports together and tells the boss.
 *
 * EXAMPLE:
 * 3
 * / \
 * 9   20
 * /  \
 * 15   7
 *
 * - Call 9: It's a leaf and it's LEFT. Return 9.
 * - Call 20: Not a leaf. Ask children.
 * - Call 15: It's a leaf and it's LEFT. Return 15.
 * - Call 7: It's a leaf, but it's RIGHT. Return 0.
 * - Total: 9 + 15 = 24.
 */

 /*
    TEST CASE 1: Standard Tree
    Input: [3, 9, 20, null, null, 15, 7]
    - 9 is a left leaf. (Add 9)
    - 15 is a left leaf. (Add 15)
    - 7 is a right leaf. (Don't add)
    Expected Result: 24

    TEST CASE 2: Single Node
    Input: [1]
    - 1 is a leaf, but it's the Root (not a left child of anyone).
    Expected Result: 0

    TEST CASE 3: Only Right Branches
    Input: [1, null, 2, null, 3]
    - All leaves are right children.
    Expected Result: 0
*/