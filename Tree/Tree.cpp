#include <bits/stdc++.h>
#include <queue>
using namespace std;

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
void printTree(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data;
    if (root->left)
    {
        printTree(root->left);
    }
    if (root->right)
    {
        printTree(root->right);
    }
}

void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        cout << temp->data;
        q.pop();
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data;
    inOrder(root->right);
}

void PostOrder(Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    inOrder(root->right);
    cout << root->data;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    printTree(root);
    cout << endl;
    levelOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    PostOrder(root);
}
