#include <bits/stdc++.h>
using namespace std;

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
} NODE;

NODE (int data){ // constructor
    data = data;
    left = right = NULL;
}

main(){
    NODE *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->right = newnode(5);
}