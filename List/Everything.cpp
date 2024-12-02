#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = NULL;
    }
};
Node *createList(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 0; i < arr.size(); i++)
    {
        Node *newnode = new Node(arr[i]);
        temp->next = newnode;
        temp = newnode;
    }
    return head;
}

Node *InsertHead(Node *head, int val)
{
    if (head == NULL)
        return 0;
    Node *newnode = new Node(val);
    newnode->next = head;
    return newnode;
}

Node *InsertElementTail(Node *head, int value)
{
    if (head == NULL)
        return 0;
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *newnode = new Node(value);
    temp->next = newnode;
    temp = newnode;
    return head;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data;
        temp = temp->next;
    }
}
int main()
{
    vector<int> arr = {1, 2, 3, 4};
    Node *head = createList(arr);
    head = InsertElementTail(head, 5);
    head = InsertHead(head, 9);
    printList(head);
}
