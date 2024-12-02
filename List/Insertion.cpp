#include <bits/stdc++.h>
using namespace std;
struct Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};
Node *convertolist(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newnode = new Node(arr[i]);
        mover->next = newnode;
        mover = newnode;
    }
    return head;
}
Node *insertHead(Node *head, int val)
{
    Node *newnode = new Node(val, head);
    return newnode;
}
Node *insertTail(Node *head, int val)
{
    Node *newnode = new Node(val);
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    // temp = newnode;
    return head;
}
Node *insertAny(Node *head, int pos, int val)
{
    Node *newnode = new Node(val);
    Node *temp = head;
    int counter = 0;
    while (temp != nullptr)
    {
        counter++;
        if ((counter-1) == pos)
        {
            newnode->next = temp->next;
            temp->next = newnode;
            // temp=newnode;
        }
        temp=temp->next;
    }
    return head;
}
int main()
{
    vector<int> arr = {2, 3, 4, 5, 6, 7};
    Node *head = convertolist(arr);
    // head=insertHead(head,10);
    head=insertTail(head,20);
    // head = insertAny(head, 3, 20);
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
