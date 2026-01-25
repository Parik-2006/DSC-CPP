// Binary Tree Paths

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(root!=NULL)
            Path(root, "", result);
        return result;
    }

    void Path(TreeNode* root, string path,
    vector<string>& result){
        path += to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            result.push_back(path);
            return;
        }

        if(root->left)
            Path(root->left, path + "->", result);
        if(root->right)
            Path(root->right, path + "->", result);
           
    }
};

/*
 * PATH CONSTRUCTION TRACE
 * -----------------------
 * START: Root (1)
 * - Path becomes: "1"
 * - Not a leaf. Branching...
 *
 * LEFT TURN: Node (2)
 * - Path becomes: "1->2"
 * - Not a leaf. Branching...
 *
 * DEEPER LEFT: Node (5)
 * - Path becomes: "1->2->5"
 * - IS A LEAF!
 * - ACTION: Add "1->2->5" to our result list.
 *
 * BACK TO ROOT, RIGHT TURN: Node (3)
 * - Path becomes: "1->3"
 * - IS A LEAF!
 * - ACTION: Add "1->3" to our result list.
 *
 * FINAL LIST: ["1->2->5", "1->3"]
 */

 /*
    TEST CASE 1: Standard Tree
    Input: [1, 2, 3, null, 5]
    - Path A: Start at 1, go to 2, go to 5 (Leaf). Path: "1->2->5"
    - Path B: Start at 1, go to 3 (Leaf). Path: "1->3"
    Expected Result: ["1->2->5", "1->3"]

    TEST CASE 2: Single Node
    Input: [1]
    - Start at 1. It is already a leaf.
    - No arrows needed because there is no "next" node.
    Expected Result: ["1"]

    TEST CASE 3: A "Line" Tree (Skewed)
    Input: [1, 2, null, 3, null]
    - Only one possible path exists.
    - 1 -> 2 -> 3
    Expected Result: ["1->2->3"]

    TEST CASE 4: Tree with Negative Values
    Input: [1, -2, 3]
    - The to_string() function handles the minus sign automatically.
    Expected Result: ["1->-2", "1->3"]
*/