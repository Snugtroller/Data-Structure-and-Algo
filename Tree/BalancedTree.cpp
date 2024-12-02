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

int heightOfTree(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(heightOfTree(root->left), heightOfTree(root->right));
}
bool isBalanced(Node *root)
{
    if (root == NULL)
        return 1;
    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    bool diff = abs(heightOfTree(root->left) - heightOfTree(root->right)) <= 1;
    if (left && right && diff)
        return 1;
    else
        return false;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    bool balance=isBalanced(root);
    cout<<balance;
}
