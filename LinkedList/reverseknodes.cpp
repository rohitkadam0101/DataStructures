// reverse k nodes
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtTail(Node *&head, int val){
    Node *n = new Node(val);
    if(head==NULL){
        head=n;
        return;
    }
    Node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
}
Node *reverseKNodes(Node *&head,int k){
    if(!head){
        return NULL; // base case
    }
    Node *curr = head;
    Node *nextptr = NULL;
    Node *prevptr = NULL;
    int c = 0; // to reverse k nodes 
    while(curr!=NULL && c<k){
        nextptr = curr->next;
        curr->next = prevptr;
        prevptr = curr;
        curr = nextptr;
        c++;
    }
    if(nextptr!=NULL){
        head->next = reverseKNodes(nextptr,k);  // head->next= prev
    }
    return prevptr; // prev =>head i.e smallest will be head and largest will be prev 
}

void printLL(Node *head){
    Node *temp  = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
}

int main(){
    Node *head = NULL;
    for(int i=1;i<=8;i++){
        insertAtTail(head,i);
    }
    printLL(head);
    cout<<endl;
    cout<<"Enter K: ";
    int k;
    cin>>k;
    Node *newhead = reverseKNodes(head,k);
    printLL(newhead);
    
    return 0;
}