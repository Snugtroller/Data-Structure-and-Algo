#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int data;
    Node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};
int sum(Node*root){
    if(root==NULL)return 0;
    return root->data+sum(root->left)+sum(root->right);
}
bool isSumTree(Node*root){
    if(root==NULL || (root->left==NULL && root->right==NULL))return 1;
    int left=sum(root->left);
    int right=sum(root->right);
    if(root->data!=left+right)return 0;
    return isSumTree(root->left) && isSumTree(root->right);
}
int main(){
    Node *root = new Node(3);
    root->left = new Node(2);
    root->right = new Node(1);
    bool check= isSumTree(root);
    cout<<check<<endl;
}