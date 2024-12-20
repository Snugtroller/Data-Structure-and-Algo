#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *next;
    Node *prev;
    int data;
    Node(int data1)
    {
        data = data1;
        next = NULL;
        prev = NULL;
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
        newNode->prev = temp;
        temp = newNode;
    }
    cout << "List: ";
    return head;
}
Node *InsertAtHead(Node *head, int val)
{
    if (head == NULL)
        return NULL;
    Node *newNode = new Node(val);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    cout << "Insert Head: ";
    return head;
}
Node *InsertAtTail(Node *head, int val)
{
    if (head == NULL)
        return NULL;
    Node *newNode = new Node(val);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    temp = newNode;
    cout << "Insert tail: ";
    return head;
}
Node *InsertAtAny(Node *head, int val, int pos)
{
    if (head == NULL)
        return NULL;
    Node *temp = head;
    int count = 0;
    while (temp != NULL && count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    Node *newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    temp = newNode;
    cout << "Insert At Any: ";
    return head;
}
Node *DeleteHead(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    delete (temp);
    cout << "Delete head: ";
    return head;
}
Node *DeleteTail(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *prevNode = temp->prev;
    if (prevNode)
        prevNode->next = NULL;
    delete (temp);
    cout << "Delete Tail: ";
    return head;
}
Node *DeleteAtAny(Node *head, int pos)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    int count = 0;
    Node *temp = head;
    while (temp != NULL && count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    Node *DeleteNode = temp->next;
    Node *AfterDeleteNode = temp->next->next;
    temp->next = AfterDeleteNode;
    AfterDeleteNode->prev = temp;
    cout << "Delete at Any: ";
    return head;
}
void PrintList(Node *head)
{
    Node *temp = head;
    if (head == NULL)
        return;
    while (temp != NULL)
    {
        cout << temp->data << "<->";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = ToList(arr);
    PrintList(head);
    Node *head1 = InsertAtHead(head, 6);
    PrintList(head1);
    Node *head2 = InsertAtTail(head1, 7);
    PrintList(head2);
    Node *head3 = InsertAtAny(head1, 8, 2);
    PrintList(head3);
    Node *head4 = DeleteHead(head1);
    PrintList(head4);
    Node *head5 = DeleteTail(head4);
    PrintList(head5);
    Node *head6 = DeleteAtAny(head4, 1);
    PrintList(head6);
}