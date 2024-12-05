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

void solve(Node *root, int sum, int &maxSum, int len, int &maxLen)
{
    if (root == NULL)
    {
        if (len > maxLen)
        {
            maxLen = len;
            maxSum = sum;
        }
        if (len == maxLen)
        {
            maxSum = max(sum, maxSum);
        }
        return;
    }
    sum = sum + root->data;
    solve(root->left, sum, maxSum, len + 1, maxLen);
    solve(root->right, sum, maxSum, len + 1, maxLen);
}

int BloodLine(Node *root)
{
    int sum = 0;
    int maxSum = INT_MIN;
    int len = 0;
    int maxLen = 0;
    solve(root, sum, maxSum, len, maxLen);
    return maxSum;
}
int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(7);
    root->left->right = new Node(1);
    root->left->right->left = new Node(6);
    root->right->left = new Node(2);
    root->right->right = new Node(3);
    int res = BloodLine(root);
    cout << res;
}