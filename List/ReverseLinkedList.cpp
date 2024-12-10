#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *next;
    int data;
    Node(int data1)
    {
        data = data1;
        next = NULL;
    }
};
Node *LinkedList(vector<int> &arr)
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
Node *reverseList(Node *head)
{
    if (head == NULL)
    {
        return {};
    }
    Node *prev = NULL;
    Node *current = head;
    while (current != NULL)
    {
        Node *forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
    }
    return prev;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4};
    Node *head = LinkedList(arr);
    head = reverseList(head);
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-";
        temp = temp->next;
    }
    return 0;
}