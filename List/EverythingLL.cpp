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
Node *InsertAtFirst(Node *head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    return newNode;
}
Node *InsertEnd(Node *head, int val)
{
    Node *newNode = new Node(val);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}
Node *InsertAny(Node *head, int val, int pos)
{
    Node *temp = head;
    int counter = 1;
    while (counter < pos - 1)
    {
        temp = temp->next;
        counter++;
    }
    Node *newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}
Node *deleteFirst(Node *head)
{
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}
Node *deleteTail(Node *head)
{
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}
Node *deleteAtAny(Node *head, int pos)
{
    Node *temp = head;
    int counter = 0;
    while (counter < pos - 1)
    {
        temp = temp->next;
        counter++;
    }
    Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    return head;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4};
    Node *head = ToList(arr);
    head = InsertAtFirst(head, 5);
    head = InsertEnd(head, 6);
    head = InsertAny(head, 7, 3);
    head = deleteFirst(head);
    head = deleteTail(head);
    head = deleteAtAny(head, 1);
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-";
        temp = temp->next;
    }
}