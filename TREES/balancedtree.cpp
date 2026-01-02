#include <bits/stdc++.h>
using namespace std;

typedef struct NODE{
    int data;
    struct NODE *left;
    struct NODE *right;

    NODE(int data){ // Constructor
        this->data = data;
        left = NULL;
        right= NULL;
    }
}NODE;

// 
class Solution{
    public:
    // Finding Balanced Tree
    bool isbalanced(NODE* root){
        return dfsHeight(root) != -1;
    }
    int dfsHeight (NODE *root){
        if (root == NULL) return 0;
        int lh = dfsHeight(root->left);
        if(lh == -1) return -1;
        int rh = dfsHeight(root->right);
        if(rh == -1) return -1;

        if(abs(lh-rh)>1) return -1;
        return max(lh,rh) + 1;
    }

    void preorder(NODE *root){
        if(root == NULL) return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(NODE *root){
        if(root == NULL) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void postorder(NODE *root){
        if(root == NULL) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    void levelorder(NODE *root){
        if(root == NULL) return;
        queue <NODE*> q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            NODE *ptr = q.front();
            q.pop();

            if(ptr == NULL){
                cout << endl;
                if(!q.empty())
                    q.push(NULL);
            } else {
                cout << ptr->data << " ";
                if(ptr->left) q.push(ptr->left);
                if(ptr->right) q.push(ptr->right);
            }
        }
    }
};

NODE *buildTree(NODE *root){

}

int main(){
    struct NODE *root = new NODE(1);
    root->left = new NODE(2);
    root->right = new NODE(3);
    root->left->left = new NODE(4);
    root->left->right = new NODE(5);
    root->right->left = new NODE(6);
    root->right->right = new NODE(7);

    Solution obj;
    cout << "Preorder Traversal: " << endl;
    obj.preorder(root);
    cout << endl;
    cout << "Inorder Traversal: " << endl;
    obj.inorder(root);
    cout << endl;
    cout << "Postorder Traversal: " << endl;
    obj.postorder(root);
    cout  << endl;
    if(obj.isbalanced(root)){
        cout << "Tree is a Balanced Tree" << endl;
    } else {
        cout << "Tree is Not a Balanced Tree" << endl;
    }
    cout << endl;
}