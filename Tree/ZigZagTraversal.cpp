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

void zigZag(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> currentLvl;
    stack<Node *> NextLvl;
    bool LeftToRight = true;
    currentLvl.push(root);
    while (!currentLvl.empty())
    {
        Node *temp = currentLvl.top();
        currentLvl.pop();

        if (temp)
        {
            cout << temp->data;
            if (LeftToRight)
            {
                if (temp->left)
                {
                    NextLvl.push(temp->left);
                }
                if (temp->right)
                {
                    NextLvl.push(temp->right);
                }
            }
            else
            {
                if (temp->right)
                {
                    NextLvl.push(temp->right);
                }
                if (temp->left)
                {
                    NextLvl.push(temp->left);
                }
            }
        }
        if (currentLvl.empty())
        {
            LeftToRight = !LeftToRight;
            swap(currentLvl, NextLvl);
        }
    }
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(4);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->right->left = NULL;
    root->right->right->left = new Node(7);
    root->right->right->right = new Node(8);
    zigZag(root);
    cout << endl;
}