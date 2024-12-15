// The Time complexity for removing duplicates in sorted list is O(n)

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
    Node *temp = head;
    if (head == NULL)
        return;
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
Node *RemoveDuplicate(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *current = head;
    Node *currentNext = current->next;
    while (current != NULL && current->next != NULL)
    {
        if (current->data == current->next->data)
        {
            Node *duplicate = current->next;
            current->next = current->next->next;
            delete duplicate;
        }
        else
        {
            current = current->next;
        }
    }
    return head;
}
int main()
{
    vector<int> arr = {1, 2, 2, 3, 3, 3, 4, 5};
    Node *head = ToList(arr);
    PrintList(head);
    RemoveDuplicate(head);
    PrintList(head);
}