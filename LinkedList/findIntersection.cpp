// Find intersection of two linked list
// head = head1 and head2 =head2

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

int length(Node *head){
    Node *t  =head;
    int l = 0;
    while(t!=NULL){
        t = t->next;
        l++;
    }
    return l;
}

void makeIntersection(Node *&head,Node *&head2,int k){ // check again its wrong!!!!!
    Node *temp= head2;
    while(temp->next!=NULL){
        temp = temp->next; //last node of LL2
    }
    int c=0;
    Node *temp2  = head;
    while(temp2->next!=NULL && c<k){
        temp2 = temp2 ->next;
    }
    temp->next= temp2; //make intersection
    temp->next->next = NULL;
    
}

int detectIntersection(Node *&head, Node *&head2){
    int l1 = length(head);
    int l2 = length(head2);
    int d=0;
    Node *ptr1; // for larger LL
    Node *ptr2;
    if(l1>l2){
        d = l1-l2;
        ptr1 = head;
        ptr2 =head2;
    }
    else{
        d = l2 - l1;
        ptr1 =head2;
        ptr2 = head;
    }
    while(d){
        ptr1=ptr1->next;
        if(ptr1==NULL){
            return -1;
        }
        d--;// to make both pointers point at same node
    }
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1==ptr2){
            return ptr1->data;
        }
        ptr1 =ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;

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
    for(int i=1;i<=6;i++){
        insertAtTail(head,i);
    }
    printLL(head);
    cout<<endl;
    Node *head2 = NULL;
    for(int i=8;i<=9;i++){
        insertAtTail(head2,i);
    }
    printLL(head2);
    int k;
    cout<<"Enter position to make intersection:";
    cin>>k;
    makeIntersection(head,head2,k);
    cout<<detectIntersection(head,head2);
    return 0;
}

