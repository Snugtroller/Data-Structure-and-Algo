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
Node *ConvertCircularList(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = newNode;
    }
    temp->next = head;
    return head;
}
Node *InsertHead(Node *head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return newNode;
}
Node *InsertTail(Node *head, int val)
{
    Node *temp = head;
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}
Node *InsertAtAny(Node *head, int val, int pos)
{
    Node *temp = head;
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }
    int count = 1;
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    Node *aageNode = temp->next;
    temp->next = newNode;
    newNode->next = aageNode->next;
    return head;
}
Node *deleteHead(Node *head)
{
    Node *temp = head;
    if (head == NULL)
    {
        free(head);
        return {};
    }
    while (temp->next != head)
    {
        temp = temp->next;
    }
    Node *newHead = head->next;
    temp->next = newHead;
    return newHead;
}
Node *deleteTail(Node *head)
{
    Node *temp = head;
    if (head == NULL)
    {
        free(head);
        return {};
    }
    while (temp->next->next != head)
    {
        temp = temp->next;
    }
    Node *tail = temp->next;
    temp->next = head;
    free(tail);
    return head;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = ConvertCircularList(arr);
    head = InsertHead(head, 6);
    head = InsertTail(head, 7);
    head = InsertAtAny(head, 8, 3);
    head = deleteHead(head);
    head = deleteTail(head);
    Node *temp = head;
    if (head != NULL)
    {
        do
        {
            cout << temp->data << "-";
            temp = temp->next;
        } while (temp != head);
    }
}
