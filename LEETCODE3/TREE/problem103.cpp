// Binary Tree Zig Zag Levl Order Traversal

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector <vector <int>> result;
        if(root == NULL)
            return result;
        queue <TreeNode*> Elements;
        Elements.push(root);
        bool flag = true;

        while(!Elements.empty()){
            int size = Elements.size();
            vector <int> row (size);
            for(int i = 0; i<size; i++){
                TreeNode *ptr = Elements.front();
                Elements.pop();

                int index = (flag)? i : (size - 1 - i);
                row[index] = ptr->val;

                if(ptr->left)
                    Elements.push(ptr->left);
                if(ptr->right)
                    Elements.push(ptr->right);
            }
            flag = !flag;
            result.push_back(row);
        }
        return result;
    }
};


/*
    Let's trace this with Tree: [3, 9, 20, null, null, 15, 7]
    WALKTHROUGH: Zigzag Level Order
    -------------------------------
    Initial: q = [3], flag = true (L -> R)

    LEVEL 1 (Size = 1):
    - Pop 3. index = (true) ? 0 : 0 -> index 0.
    - row[0] = 3. 
    - Push children of 3: q = [9, 20].
    - Result: [[3]]
    - Flip flag: flag = false.

    LEVEL 2 (Size = 2):
    - Pop 9. index = (false) ? 0 : (2-1-0) -> index 1.
      row[1] = 9.
    - Pop 20. index = (false) ? 1 : (2-1-1) -> index 0.
      row[0] = 20.
    - Push children of 9: (none).
    - Push children of 20: q = [15, 7].
    - Result: [[3], [20, 9]]
    - Flip flag: flag = true.

    LEVEL 3 (Size = 2):
    - Pop 15. index = (true) ? 0 : 1 -> index 0.
      row[0] = 15.
    - Pop 7. index = (true) ? 1 : 0 -> index 1.
      row[1] = 7.
    - Result: [[3], [20, 9], [15, 7]]
    - Flip flag: flag = false.

    FINAL RESULT: [[3], [20, 9], [15, 7]]
*/

/*
    TEST CASE 1: Standard Zigzag (3 Levels)
    Input: [3, 9, 20, null, null, 15, 7]
    - Level 0 (L->R): [3]
    - Level 1 (R->L): [20, 9]  <- 9 and 20 are children, but order is swapped
    - Level 2 (L->R): [15, 7]
    Expected Result: [[3], [20, 9], [15, 7]]

    TEST CASE 2: The "Straight Line" Tree
    Input: [1, 2, 3, 4, 5]
    - Level 0: [1]
    - Level 1: [3, 2]
    - Level 2: [4, 5]
    Expected Result: [[1], [3, 2], [4, 5]]

    TEST CASE 3: Only Right Children (Skewed)
    Input: [1, null, 2, null, 3, null, 4]
    - Level 0: [1]
    - Level 1: [2] (R->L of one node is still just 2)
    - Level 2: [3]
    - Level 3: [4]
    Expected Result: [[1], [2], [3], [4]]

    TEST CASE 4: Complete Binary Tree (4 Levels)
    Input: [1, 2, 3, 4, 5, 6, 7]
    - Level 0: [1]
    - Level 1: [3, 2]
    - Level 2: [4, 5, 6, 7]
    Expected Result: [[1], [3, 2], [4, 5, 6, 7]]
*/