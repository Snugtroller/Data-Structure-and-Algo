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
bool LoopList(Node *head)
{
    if (head == NULL)
    {
        return false;
    }
    Node *temp = head;
    map<Node *, bool> visited;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            cout << "loop h";
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    cout << "No LOOP";
    return false;
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
    LoopList(head);
}