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

void solve(Node *root, vector<int> &ans, int level)
{
    if (root == NULL)
        return;
    if (level == ans.size())
    {
        ans.push_back(root->data);
    }
    solve(root->left, ans, level + 1);
    solve(root->right, ans, level + 1);
}

vector<int> LeftTree(Node *root)
{
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);
    root->right->left = new Node(6);
    root->right->right->right = new Node(8);
    vector<int> res = LeftTree(root);
    for (int val : res)
    {
        cout << val << "";
    }
    cout << endl;
}