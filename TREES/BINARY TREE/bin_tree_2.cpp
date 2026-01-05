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

void levelorder(Node *root){
    if(root == NULL)
        return;
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

void reverseLevelOrder(Node *root){
    if(root == NULL)
        return;
    queue <Node*> q;
    stack <Node*> s;

    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node *ptr = q.front();
        q.pop();

        if(ptr == NULL){
            s.push(NULL);
        if(!q.empty())
            q.push(NULL);
        } else {
            s.push(ptr);

            if(ptr->right)
                q.push(ptr->right);
            if(ptr->left)
                q.push(ptr->left);
        }

    }

    while(!s.empty()){
        Node *ptr = s.top();
        s.pop();

        if(ptr == NULL)
            cout << endl;
        else
            cout << ptr->data << " ";
    }
}

void buildFromLevelOrder(Node* &root){
    queue <Node*> q;
    cout << "Enter Data for Root Node: ";
    int rootData;
    cin >> rootData;
    root = new Node(rootData);
    q.push(root);
    while(!q.empty()){
        Node *ptr = q.front();
        q.pop();

        // Left Node
        cout << "Enter Left Node for " << ptr->data <<": ";
        int leftData;
        cin >> leftData;

        if(leftData!= -1){
            ptr->left = new Node(leftData);
            q.push(ptr->left);
        }

        // Right Node
        cout << "Enter Right Node for " << ptr->data <<": ";
        int rightData;
        cin >> rightData;

        if(rightData!= -1){
            ptr->right = new Node(rightData);
            q.push(ptr->right);
        }
    }
}

#if 0
In C++, when you pass `root` to a function like `buildFromLevelOrder(Node *root)`, the function receives **only a copy of the 
pointer**, not the original pointer from `main()`. So when the function creates a new node and assigns it to `root`, it changes 
**only that local copy**, and the original `root` in `main()` stays `NULL`. By adding the ampersand (`Node* &root`), you are telling 
C++ to pass the **actual pointer itself**, not a copy of it. This means any change made to `root` inside the function (like assigning 
`new Node`) directly updates `root` in `main()`, allowing the tree to exist outside the function and be printed correctly by 
`levelorder()`.
#endif

int main(){
    Node *root = NULL;
    // root = buildTree(root);
    buildFromLevelOrder(root);
    cout << "Level Order Traversal: " << endl;
    levelorder(root);
    return 0;
}
