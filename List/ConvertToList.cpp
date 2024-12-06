#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = NULL;
    }
};
Node *ToList(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = newNode;
    }
    return head;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4};
    Node *head = ToList(arr);
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-";
        temp = temp->next;
    }
}