#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        typedef struct Node{
            int data;
            struct Node *left;
            struct Node *right;
        }NODE;

        NODE *newnode(int data){
            NODE *newnode = new NODE;
            newnode->data = data;
            newnode->left = NULL;
            newnode->right = NULL;
            return newnode;
        }

        NODE *insertnode(NODE *root, int data){
            if(root == NULL) 
                return newnode(data);
            NODE *ptr = root;
            while(true){
                if(ptr->data <= data){
                    if(ptr->right!=NULL)
                        ptr = ptr->right;
                    else {
                        ptr->right = newnode(data);
                        break;
                    }
                } else {
                    if(ptr->left!=NULL){
                        ptr = ptr->left;
                    } else {
                        ptr->left = newnode(data);
                        break;
                    }
                }
            }
            return root; 
            // time complexity = 0(log base 2 n) / 0(log2n)
        }

        void preorder(NODE *root){
            if(root == NULL)
                return;
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }

        void levelorder(NODE *root){
            if(root == NULL)
                return;
            queue <NODE*> q;
            q.push(root);
            q.push(NULL);

            while(!q.empty()){
                NODE *ptr = q.front();
                q.pop();

                if(ptr == NULL) {
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

        NODE *deletenode(NODE *root,int data){
            if(root == NULL)
                return NULL;
            if(root->data == data)
                return helper(root);
            NODE *ptr = root;
            while(root!=NULL) {
                if(root->data > data){
                    if(root->left != NULL && root->left->data  == data){
                        root->left = helper(root->left);
                        break;
                    } else {
                        root = root->left;
                    }
                } else {
                    if(root->right != NULL && root->right->data == data){
                        root->right = helper(root->right);
                        break;
                    } else {
                        root = root->right;
                    }
                }
            }
            return ptr;
        }

        NODE *helper(NODE *root){
            if(root->left == NULL)
                return root->right;
            else if(root->right == NULL)
                return root->left;
            NODE *rightchild = root->right;
            NODE *lastright = findlastright(root->left);
            lastright->right = rightchild;
            return root->left;
        }

        NODE *findlastright(NODE *root){
            if(root->right == NULL)
                return root;
            return findlastright(root->right);
        }
};

int main(){
    Solution obj;
    Solution :: NODE *root = NULL;
    root = obj.newnode(7);
    root->left = obj.newnode(2);
    root->left->left = obj.newnode(1);
    root->left->right = obj.newnode(3);
    root->right = obj.newnode(10);
    root->right->left = obj.newnode(8);
    root->right->right = obj.newnode(13);
    cout << "Original Tree: " << endl;
    obj.levelorder(root);
    cout << endl;
    cout << "Tree after Insertion: " << endl;
    root = obj.insertnode(root,11);
    root = obj.insertnode(root,12);
    root = obj.insertnode(root, 5);
    root = obj.insertnode(root, 6);
    obj.levelorder(root);
    cout << endl;
    cout << "Tree after Deletion: " << endl;
    root = obj.deletenode(root, 10);
    obj.levelorder(root);
    cout << endl;
    return 0;
}

#if 0
ORIGINAL TREE 
            7
          /   \
         2     10
        / \   /  \
       1   3 8    13

INSERT NODE
                7
              /   \
             2     10
            / \   /  \
           1   3 8    13
                \    /
                 5  11
                  \    \
                   6    12


DELETE NODE 
                7
              /   \
             2     8
            / \      \
           1   3      13
                \     /
                 5   11
                  \     \
                   6     12

#endif