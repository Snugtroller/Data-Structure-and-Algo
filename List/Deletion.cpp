#include <bits/stdc++.h>
using namespace std;
struct Node{
    public:
    int data;
    Node*next;

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
Node*deleteHead(Node*head){
    Node*temp=head;
    if(head==nullptr){
        cout<<"chal nikal";
    }
    else{
        head=head->next;
        delete temp;
    }
    return head;
    
}
Node*deleteTail(Node*head){
    Node*temp=head;
    if(head==nullptr){
        cout<<"chall hatt";
    }
    else{
        while(temp->next->next!=nullptr){
            temp=temp->next;
        }
        delete temp->next;
        temp->next=nullptr;
    }
    return head;
}
Node*deleteAny(Node*head,int pos){
    Node*prev=nullptr;
    Node*temp=head;
    int counter=0;
    if(head==nullptr){
        return head;
    }
    else{
        while(temp->next!=nullptr){
            counter++;
            if(counter==pos){
                prev->next=prev->next->next;
                free (temp);
                break;
            }
            prev=temp;
            temp=temp->next;
        }
    }
    return head;
}
int main()
    {
        vector<int> arr = {2, 3, 4,5,6,7};
        Node*head=convertolist(arr);
        // head=deleteHead(head);
        // cout<<head->data;
        // Node*tail=deleteTail(head);
        // while(tail){
        //     cout<<tail->data<<' ';
        //     tail=tail->next;
        // }
        head=deleteAny(head,3);
        while(head){
            cout<<head->data;
            head=head->next;
        }
    }