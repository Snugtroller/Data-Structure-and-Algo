#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
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
void PrintList(Node *head)
{
    if (head == NULL)
        return;
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
    if (temp == head)
    {
        cout << "circular";
    }
}
Node *RemoveDuplicates(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *temp = head;
    Node *prev = NULL;
    unordered_set<int> seen;
    while (temp != NULL)
    {
        if (seen.find(temp->data) != seen.end())
        {
            prev->next = temp->next;
            delete temp;
        }
        else
        {
            seen.insert(temp->data);
            prev = temp;
        }
        temp = prev->next;
    }
    return head;
}
int main()
{
    vector<int> arr = {3, 2, 2, 4, 5, 1, 1, 1};
    Node *head = ToList(arr);
    PrintList(head);
    Node *list = RemoveDuplicates(head);
    PrintList(list);
}