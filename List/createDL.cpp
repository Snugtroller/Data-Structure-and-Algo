    #include <bits/stdc++.h>
    using namespace std;
    struct Node
    {
    public:
        int data;
        Node *next;
        Node*back;

    public:
        Node(int data1, Node *next1,Node*back1)
        {
            data = data1;
            next = next1;
            back=back1;
        }

    public:
        Node(int data1)
        {
            data = data1;
            next = nullptr;
            back=nullptr;
        }
    };
    Node*convertolist(vector<int>&arr){
        Node*head=new Node(arr[0]);
        Node*mover=head;
        Node*prev=head;
        for(int i=1;i<arr.size();i++){
            Node*newnode=new Node(arr[i]);
            prev->next=newnode;
            prev=newnode;
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
