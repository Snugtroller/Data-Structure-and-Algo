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
void solve(Node *root, vector<int> &path, int &count, int k)
{
    if (root == NULL)
        return;
    path.push_back(root->data);
    solve(root->left, path, count, k);
    solve(root->right, path, count, k);
    int size = path.size();
    int sum = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        sum = sum + path[i];
        if (sum == k)
        {
            count++;
        }
    }
    path.pop_back();
}
int sumK(Node *root, int k)
{
    vector<int> path;
    int count = 0;
    solve(root, path, count, k);
    return count;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(-1);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(6);
    int res = sumK(root, 5);
    cout << res;
}