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

bool isIdentical(Node *r1, Node *r2)
{
    if (r1 == NULL && r2 == NULL)
        return 1;
    if (r1 == NULL || r2 == NULL)
        return 0;
    return (r1->data == r2->data) && isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(5);
    bool balance = isBalanced(root);
    bool identical = isIdentical(root, root2);
    cout << balance << endl;
    cout << identical;
}
