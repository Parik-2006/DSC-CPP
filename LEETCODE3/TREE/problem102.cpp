// Binary TRree Level Order Traversal

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector<int>> result;
        if(root == NULL)
            return result;
        queue <TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> currentlevel;

        while(!q.empty()){
            TreeNode *ptr = q.front();
            q.pop();

            if(ptr == NULL){
                result.push_back(currentlevel);
                currentlevel.clear();
                if(!q.empty())
                    q.push(NULL);
            } else {
                currentlevel.push_back(ptr->val);
                if(ptr->left)
                    q.push(ptr->left);
                if(ptr->right)
                    q.push(ptr->right); 
            }
        }
        return result;
    }
};


/*
    INPUT: [3, 9, 20, null, null, 15, 7]
    
    1. Queue: [3] -> currentLevel: [3]
    2. Queue: [9, 20] -> currentLevel: [9, 20]
    3. Queue: [15, 7] -> currentLevel: [15, 7]
    
    RESULT: [[3], [9, 20], [15, 7]]
*/