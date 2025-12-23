#include <bits/stdc++.h>
using namespace std;

class Node{

    public: 
        int data;
        Node *left;
        Node *right;

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree(Node *root){
    cout << "Enter Node's Data:" << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if(data == -1)
        return NULL;

    cout << "Enter Data for Inserting left of " << data << ":" << endl;
    root->left = buildTree(root->left);
    cout << "Enter Data for Inserting right of " << data << ":" << endl;
    root->right = buildTree(root->right);
}

Node *levelorder(Node *root){
    queue <Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node *ptr = q.front();
        q.pop();

        if(ptr == NULL){
            cout << endl;
            if(!q.empty())
                q.push(NULL);
        } else {
            cout << ptr->data << " ";
            if(ptr->left)
                q.push(ptr->left);
            if(ptr->right)
                q.push(ptr->right);
        }
    }
}

#if 0 
This function performs a **level-order (breadth-first) traversal** of a binary tree and prints 
the nodes **level by level** using a queue. It starts by pushing the root node into the queue, 
followed by a `NULL` marker, which is used to indicate the end of the current level. Inside the 
loop, the function repeatedly takes the front element of the queue and removes it; if the 
element is `NULL`, it means one level has finished, so a new line is printed and another `NULL` 
is pushed if more nodes remain. If the element is a valid node, its data is printed and its 
left and right children (if they exist) are pushed into the queue. This process continues until 
the queue becomes empty, ensuring that nodes are visited and printed in breadth-first order, 
with each level of the tree displayed on a separate line.
#endif

Node *reverseLevelOrder(Node *root){

}

int main(){
    Node *root = NULL;
    root = buildTree(root);
    cout << "Level Order Traversal: " << endl;
    root = levelorder(root);
    return 0;
}
