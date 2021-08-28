#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int value){
        data = value;
        next = NULL;
    }
};

void insertAtBeginning(node* &head, int val){ // passing adress of head as we are modified the linked list
    node * n = new node(val);
    n->next = head;
    head = n;
}

void insertAtTail(node* &head, int val){  
    node* n = new node(val);
    if(head==NULL){
        head = n;
        return;
    }
    node *temp = head;
    while(temp->next!=NULL){        //temp->next = *temp.next
        temp = temp->next;
    }
    temp->next = n;
}

void insertAtPos(node* &head,int pos,int val){
    node *n =new node(val);
    node* temp = head;
    // first pos
    if(pos==0){
        n->next = head;
        head = n;
        return;
    }
    for(int i=0;i<pos-1;i++){
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
    
}

void deleteAtBegin(node* &head){
    node *t = head;
    head= head->next;
    delete t;
}
void deleteValue(node* &head,int val){
    if(head==NULL){
        return;  // for empty list
    }
    if(head->next == NULL){
        deleteAtBegin(head);
        return;
    }
    node *temp = head;
    while(temp->next->data != val){
        temp  = temp->next;
    }
    node *t = temp->next;
    temp->next  = temp->next->next;
    delete t;
}
void printLL(node *head){ // no adress beacuse we are only modifying the list
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;

}


int main(){
    node *head =NULL; // initially head is NULL
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    printLL(head);
    insertAtBeginning(head,3);
    printLL(head);
    insertAtPos(head,1,10); // 3->4->5->6 becomes 3->10->4->5->->6
    printLL(head);
    deleteAtBegin(head);
    cout<<"Deleting head"<<endl;
    printLL(head);
    deleteValue(head,6);
    cout<<"Deleting val: "<<6<<endl;
    printLL(head);
    return 0;
}