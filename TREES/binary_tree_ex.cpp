#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int x) {
        val = x;
        left = right = NULL;
    }
};

// Build tree from level order input
// Use -1 to represent NULL input
Node* buildTreeLevelOrder() {
    int rootVal;
    cin >> rootVal;

    if (rootVal == -1)
        return NULL;

    Node* root = new Node(rootVal);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        int leftVal, rightVal;
        cin >> leftVal >> rightVal;

        if (leftVal != -1) {
            curr->left = new Node(leftVal);
            q.push(curr->left);
        }

        if (rightVal != -1) {
            curr->right = new Node(rightVal);
            q.push(curr->right);
        }
    }
    return root;
}

// Print tree like LeetCode: [1,null,2,3]
void printLikeLeetCode(Node* root) {
    if (!root) {
        cout << "[]";
        return;
    }

    vector<string> result;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr) {
            result.push_back(to_string(curr->val));
            q.push(curr->left);
            q.push(curr->right);
        } else {
            result.push_back("null");
        }
    }

    // Remove trailing "null"
    while (!result.empty() && result.back() == "null")
        result.pop_back();

    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1)
            cout << ",";
    }
    cout << "]";
}

int main() {
    /*
    Example input (level order, -1 = null):
    1 -1 2 3 -1 -1 -1

    Tree:
        1
         \
          2
         /
        3
    */

    Node* root = buildTreeLevelOrder();

    printLikeLeetCode(root);

    return 0;
}
