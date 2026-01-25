// Same Tree

#include <bits/stdc++.h>
using namespace std;


/*
   Definition for a binary tree node.
   struct TreeNode {
       int val;
       TreeNode  left;
       TreeNode  right;
       TreeNode() : val(0), left(nullptr), right(nullptr) {}
       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
       TreeNode(int x, TreeNode  left, TreeNode  right) : val(x), left(left), right(right) {}
   };
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p == NULL &&  q == NULL)
            return true;
        if(p == NULL || q == NULL || p->val!=q->val)
            return false;
        return isSameTree(p->left, q->left) &&
        isSameTree(p->right, q->right);
    }
};


/*
    TEST CASE 1: Identical Trees
    Tree P: [1, 2, 3]  |  Tree Q: [1, 2, 3]
    - Roots match (1 == 1).
    - Left children match (2 == 2).
    - Right children match (3 == 3).
    Expected Result: true

    TEST CASE 2: Different Values
    Tree P: [1, 2, 1]  |  Tree Q: [1, 1, 2]
    - Roots match (1 == 1).
    - Left children: 2 vs 1 -> MISMATCH!
    Expected Result: false

    TEST CASE 3: Different Structure (The "Lopsided" Case)
    Tree P: [1, 2]     |  Tree Q: [1, null, 2]
    - Tree P has a left child '2'.
    - Tree Q has a right child '2'.
    - When checking P->left vs Q->left, one is '2' and one is NULL.
    Expected Result: false
*/

/* 
   CONCEPT: THE SYNCHRONIZED WALK
   ------------------------------
   Imagine you have two identical twins, and you want to see if they 
   are wearing the exact same outfit.
  
   1. THE NULL CHECK:
   If both twins are "not there" (NULL), that's a match.
  
   2. THE DEAL-BREAKER:
   If one twin is there but the other isn't, they don't match. 
   If both are there but one is wearing a red shirt (val=5) 
   and the other is wearing blue (val=3), they don't match.
  
   3. THE RECURSIVE STEP:
   If they match so far, you tell them:
   "Now both of you, raise your left hands." 
   You check if the left hands (left children) match. 
   Then you check if the right hands match. 
  
   If EVERYTHING matches, you return TRUE.
  */