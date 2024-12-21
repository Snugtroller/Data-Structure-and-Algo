// 1. Given the head of a linked list, the task is to find the middle. For example, the middle of 1-> 2->3->4->5 is 3. If there are two middle nodes (even count), retum the second middle. For example, middle of 1->2->3->4->5->6 is 4.

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
Node *ToList(vector<int> arr)
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
void MiddleElement(Node *head)
{
    if (head == NULL)
        return;
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    int element = count / 2;
    Node *newTemp = head;
    for (int i = 0; i < element; i++)
    {
        newTemp = newTemp->next;
    }
    cout << newTemp->data;
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
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node *head = ToList(arr);
    PrintList(head);
    MiddleElement(head);
}