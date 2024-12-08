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
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = ConvertCircularList(arr);
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
