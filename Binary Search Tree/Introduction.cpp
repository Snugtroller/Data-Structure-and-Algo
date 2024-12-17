#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *right;
    Node *left;
    Node(int data1)
    {
        data = data1;
        right = NULL;
        left = NULL;
    }
};
void PrintTree(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << "/";
    if (root->left)
    {
        PrintTree(root->left);
    }
    if (root->right)
    {
        PrintTree(root->right);
    }
}
bool isBST(Node *root, int MinVal, int MaxVal)
{
    if (root == NULL)
        return true;
    if (root->data <= MinVal || root->data >= MaxVal)
    {
        return false;
    }
    return isBST(root->left, MinVal, MaxVal) && isBST(root->right, MinVal, MaxVal);
}
bool BST(Node *root)
{
    return isBST(root, INT_MIN, INT_MAX);
}
Node *InsertNode(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    if (val > root->data)
    {
        root->right = InsertNode(root->right, val);
    }
    if (val < root->data)
    {
        root->left = InsertNode(root->left, val);
    }
    return root;
}
int main()
{
    Node *root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
    InsertNode(root, 9);
    PrintTree(root);
    cout << endl;
    if (BST(root))
    {
        cout << "THIS IS BST";
    }
    else
    {
        cout << "NOT A BST";
    }
}