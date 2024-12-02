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
    Node*InsertHead(Node*head,int value){
        if(head==nullptr){
            return nullptr;
        }
        else{
            Node*newnode=new Node(value);
            newnode->next=head;
            head->back=newnode;
            return newnode;
        }
    }
    Node*InsertTail(Node*head,int value){
        if(head==NULL){
            return NULL;
        }
        else{
            Node*temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            Node*newnode=new Node(value);
            temp->next=newnode;
            newnode->back=temp;
        }
        return head;
    }
    Node* InsertKth(Node* head, int value, int pos) {
    if (pos < 0) {
        return head;
    }
    if (pos == 0) {
        Node* newnode = new Node(value);
        if (head != nullptr) {
            newnode->next = head;
            head->back = newnode;
        }
        return newnode;
    }
    
    Node* temp = head;
    int count = 0;
    
    while (temp != nullptr && count < pos - 1) {
        temp = temp->next;
        count++;
    }
    
    if (temp == nullptr) {
        return head; 
    }
    
    Node* newnode = new Node(value);
    newnode->next = temp->next;
    newnode->back = temp;
    if (temp->next != nullptr) {
        temp->next->back = newnode;
    }
    temp->next = newnode;
    
    return head;
}

    void print(Node*head){
        Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    }
    int main()
    {
        vector<int> arr = {2, 3, 4};
        Node*head=convertolist(arr);
        // head=InsertHead(head,20);
        // head=InsertTail(head,20);
        head=InsertKth(head,20,1);
        print(head);

    }
