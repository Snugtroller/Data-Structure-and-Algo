#include <bits/stdc++.h>
using namespace std;
#include <queue>

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void LeftTraversal(Node*root,vector<int>&ans){
    if(root==NULL)return;
    if(root->left==NULL && root->right==NULL)return;
    ans.push_back(root->data);
    if(root->left){
        LeftTraversal(root->left,ans);
    }
    if(root->right){
        LeftTraversal(root->right,ans);
    }
}
void LeafTraversal(Node*root,vector<int>&ans){
    if(root==NULL)return;
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
        return;
    }
    LeafTraversal(root->left,ans);
    LeafTraversal(root->right,ans);
}
void RightTraversal(Node*root,vector<int>&ans){
    if(root==NULL)return;
    if(root->left==NULL && root->right==NULL)return;
    if(root->left){
        RightTraversal(root->left,ans);
    }
    if(root->right){
        RightTraversal(root->right,ans);
    }
    ans.push_back(root->data);
}
vector<int> boundaryTraversal(Node *root) {
    vector<int>ans;
    if(root==NULL)return ans;
    ans.push_back(root->data);
    LeftTraversal(root->left,ans);
    LeafTraversal(root->left,ans);
    LeafTraversal(root->right,ans);
    RightTraversal(root->right,ans);
    return ans;
    
}
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(4);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->right->left = NULL;
    root->right->right->left = new Node(7);
    root->right->right->right = new Node(8);
    vector<int>res=boundaryTraversal(root);
    for(int val:res){
        cout<<val<<"";
    }
    cout<<endl;
}
