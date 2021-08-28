// three pointer current,prev and fast
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

Node *reverseLL(Node *&head){
    Node *curr = head;
    Node *prevptr = NULL;
    Node *nextptr =  NULL;
    while(curr!=NULL){
        nextptr = curr->next;
        curr->next = prevptr;
        prevptr = curr;
        curr = nextptr;
    }
    return prevptr;
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
    for(int i=1;i<=5;i++){
        insertAtTail(head,i);
    }
    printLL(head);
    cout<<endl;
    Node *newhead = reverseLL(head);
    printLL(newhead);
    return 0;
}