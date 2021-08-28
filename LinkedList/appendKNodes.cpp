// Append last K nodes of LL to start of LL
// Three pointers newstart newtail and tail
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

Node *appendKNodes(Node *&head,int k){
    int l = length(head);
    k = k%l; // to handle k greater than length
    Node *newhead = NULL; // l-k+1
    Node *newtail = NULL; //l-k
    Node *tail=head;
    int c=1;
    while(tail->next!=NULL){
        if(c==l-k){
            newtail = tail; //newtail = l-k
        }
        if(c==(l-k)+1){  //imp newhead = l-k+1
            newhead = tail;
        }
        tail = tail->next;
        c++;
    }
    tail->next = head;
    newtail->next = NULL;
    return newhead;

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
    cout<<"Enter number of nodes to append at begining: ";
    int k;
    cin>>k;
    Node *newhead = appendKNodes(head,k);
    printLL(newhead);
    return 0;
}