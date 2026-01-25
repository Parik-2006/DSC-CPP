// Binary Tree Tilt


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
class Solution {
public:
int total = 0;
    int findTilt(TreeNode* root) {
        sum(root);
        return total;
    }

    int sum(TreeNode* root){
        if(root == NULL)
            return 0;
        int lh = sum(root->left);
        int rh = sum(root->right);

        int current = abs(lh-rh);
        total += current;
        return root->val + lh +rh;
    }
};
/*
 * THE ACCOUNTING PATTERN
 * ----------------------
 * Imagine every node is a branch manager.
 * 1. THE REPORT:
 * Every manager must report their "Total Department Wealth" (Sum) 
 * to their boss above them.
 *
 * 2. THE PENALTY (Tilt):
 * The CEO (you) looks at every manager. If their Left Department has 
 * $100 and their Right Department has $20, the manager gets a 
 * "Tilt Penalty" of $80 (the difference).
 *
 * 3. THE FINAL COUNT:
 * We add up all the penalties from every manager in the whole building.
 *
 * EXAMPLE: [4, 2, 9, 3, 5, null, 7]
 * - Node 3 (Leaf): Sum = 3, Tilt = |0-0| = 0.
 * - Node 5 (Leaf): Sum = 5, Tilt = |0-0| = 0.
 * - Node 2: Sees LeftSum 3, RightSum 5. 
 * Tilt = |3-5| = 2. 
 * Reports Sum: 2 + 3 + 5 = 10.
 */

 /*
    TEST CASE 1: Simple Tree
    Input: [1, 2, 3]
    - Node 2 (Leaf): Tilt = 0, Sum = 2
    - Node 3 (Leaf): Tilt = 0, Sum = 3
    - Node 1: Tilt = |2 - 3| = 1, Sum = 1+2+3=6
    Expected Result: 1 (0 + 0 + 1)

    TEST CASE 2: Multi-level Tree
    Input: [4, 2, 9, 3, 5, null, 7]
    - Left subtree of 4 (Nodes 2, 3, 5) has sum = 10.
    - Right subtree of 4 (Nodes 9, 7) has sum = 16.
    - Tilt of root (4) = |10 - 16| = 6.
    - (Individual tilts of other nodes are added too!)
    Expected Result: 15

    TEST CASE 3: Empty Tree
    Input: []
    - No nodes, no tilt.
    Expected Result: 0
*/

#if 0
The "Accounting" BreakdownWhen the recursion reaches the Root Node (1), it asks its children for
their totals:Left Child (2) reports back: "My total sum is 2."Right Child (3) reports back: "My 
total sum is 3."Now, the Root Node (1) does two separate things:Task A: Calculate the "Tilt" 
(The Penalty)The tilt is the difference between the two reports it just received.Tilt = $|LeftSum - RightSum|$Tilt = $|2 - 3| = 1
We add this 1 to our totalTilt variable. This is what the problem asks for at the very end.Task 
B: Calculate the "Sum" (The Report to the Boss)The root node now needs to report its own total 
to whoever is above it. Its total is itself plus everything below it.Sum = $NodeValue + LeftSum + RightSum$Sum = $1 + 2 + 3 = 6$
The function returns 6. (If this was the top of the tree, this number is just discarded, but the 
totalTilt we collected in Task A stays!)
#endif