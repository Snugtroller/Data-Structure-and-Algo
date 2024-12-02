    #include <bits/stdc++.h>
    using namespace std;
    struct Node
    {
    public:
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
            next = nullptr;
        }
    };
    Node*convertolist(vector<int>&arr){
        Node*head=new Node(arr[0]);
        Node*mover=head;
        for(int i=1;i<arr.size();i++){
            Node*newnode=new Node(arr[i]);
            mover->next=newnode;
            mover=newnode;
        }
        return head;
    }
    int main()
    {
        vector<int> arr = {2, 3, 4};
        Node*head=convertolist(arr);
        Node*temp=head;
        while(temp!=nullptr){
            cout<<temp->data;
            temp=temp->next;
        }

    }
