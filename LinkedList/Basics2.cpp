// Playing with head pointer by passing it as pointer to pointer

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

void insertAtBeginning(node **head, int val){ // passing adress of head as we are modified the linked list(used **head)
    node * n = new node(val);
    n->next = (*head);
    (*head) = n;
}

void insertAtTail(node **head, int val){  
    node* n = new node(val);
    if(head==NULL){
        *head = n;
        return;
    }
    node *temp = *head;
    while(temp->next!=NULL){        //temp->next = *temp.next
        temp = temp->next;
    }
    temp->next = n;
    return;
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
    insertAtTail(&head,4); // passing &head instead of head directly
    insertAtTail(&head,5);
    insertAtTail(&head,6);
    printLL(head);
    insertAtBeginning(&head,3);
    printLL(head);
    cout<<search(head,6); // search in ll
    return 0;
}