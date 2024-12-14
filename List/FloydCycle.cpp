// Floyd's Cycle Detection Algorithm is used to determine whether a linked list contains a cycle and, if it does, to locate the start of the cycle. The time complexity of this algorithm is O(n).

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
Node *startingNode(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *intersection = FloydCycle(head);
    Node *slow = head;
    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}
void RemoveLoop(Node *head)
{
    if (head == NULL)
        return;
    Node *StartNode = startingNode(head);
    Node *temp = StartNode;
    while (temp->next != StartNode)
    {
        temp = temp->next;
    }
    temp->next = NULL;
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
        cout << "loop h" << endl;
    }
    else
    {
        cout << "no cycle" << endl;
    }
    Node *loop = startingNode(head);
    cout << "loop starts from " << loop->data << endl;
    RemoveLoop(head);
    PrintList(head, 0);
}