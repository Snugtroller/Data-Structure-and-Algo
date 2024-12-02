#include<bits/stdc++.h>
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
int HeightOfTree(Node*root,int &diameter){
    if(root==NULL)return 0;
    int lefth=HeightOfTree(root->left,diameter);
    int righth=HeightOfTree(root->right,diameter);
    diameter=max(diameter,lefth+righth);
    return 1+max(lefth,righth);
}

int diameterOfTree(Node*root){
    int diameter=0;
    HeightOfTree(root,diameter);
    return diameter;
}

int main(){
    Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    int diameter=diameterOfTree(root);
    cout<<diameter;
    return 0;
}