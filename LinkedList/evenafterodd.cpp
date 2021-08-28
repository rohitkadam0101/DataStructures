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

void evenAfterOdd(Node *&head){
    Node *odd = head;
    Node *even = head->next;
    Node *evenstart = even;
    while(odd->next!=NULL && even->next!=NULL){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    if(odd->next!=NULL){
        even->next = NULL;
    }
    odd->next = evenstart;
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
    int a[] = {1,2,3,4,5,6,7,8,9};
    for(int i=0;i<9;i++){
        insertAtTail(head,a[i]);
    }
    printLL(head);
    cout<<endl;
    evenAfterOdd(head);
    printLL(head);
    return 0;
}