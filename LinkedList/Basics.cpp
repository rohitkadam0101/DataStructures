// Class Structure , Insert at beginning and insert at end

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

void printLL(node *head){ // no adress beacuse we are only modifying the list
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;

}

bool search(node *head,int val){
    node* temp = head;
    while(temp!= NULL){
        if(temp->data == val){
            return true;
        }
        temp=temp->next;
    }
    return false;
}
int main(){
    node *head =NULL; // initially head is NULL
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    printLL(head);
    insertAtBeginning(head,3);
    printLL(head);
    cout<<search(head,6)<<endl; // search in ll
    insertAtPos(head,1,10); // 3->4->5->6 becomes 3->4->10->5->->6
    printLL(head);
    return 0;
}