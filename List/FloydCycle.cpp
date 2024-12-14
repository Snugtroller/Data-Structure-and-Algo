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
void PrintList(Node *head, int limit)
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    int count = 0;
    while (temp != NULL && count < limit)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    if (temp == head)
    {
        cout << "circular";
    }
    else
    {
        cout << "Nothing";
    }
    cout << endl;
}
Node *FloydCycle(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *temp = head;
    Node *slow = head;
    Node *fast = head;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (slow == fast)
        {
            return slow;
        }
    }
    return NULL;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    Node *head = ToList(arr);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *tail = temp;
    tail->next = head->next;
    // PrintList(head, 10);
    if (FloydCycle(head) != NULL)
    {
        cout << "loop h";
    }
    else
    {
        cout << "no cycle";
    }
}