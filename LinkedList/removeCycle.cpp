// assume that cycle is present
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

void makeCycle(Node *&head,int pos){ // to make cycle
    Node *temp = head;
    int c=0;
    Node *toconnect = NULL;
    while(temp->next!=NULL){
        if(c==pos){
            toconnect = temp;
        }
        temp= temp->next;
        c++;
    }
    temp->next  = toconnect;
}

// int detectCycle(Node *&head){
//     //slow and fast pointer tortoise and hare method
//     Node *slow =head;
//     Node *fast  =head;
//     while(fast!=NULL && fast->next!=NULL){
//         slow = slow->next;
//         fast = fast->next->next;
//         if(slow==fast){
//             return 1;  // cycle is present
//         }
//     }
//     return 0; // No cycle
// }


void printLL(Node *head){
    Node *temp  = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
}

void removeCycle(Node *&head){ //Remove cycle and assume there is always a cycle
    Node *slow = head;
    Node *fast = head;
    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(slow->data!=fast->data); //once we get point where both are same keep fast as head distance between slow and fast will be same
    fast = head; 
    while(fast->next != slow->next){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next  = NULL; // i.e. tail of our original list where we made cycle
}

int main(){
    Node *head = NULL;
    for(int i=1;i<=5;i++){
        insertAtTail(head,i);
    }
    printLL(head);
    cout<<endl;
    cout<<"Enter position to make cycle: ";
    int pos;
    cin>>pos;
    makeCycle(head,pos);
    // printLL(head);
    // cout<<detectCycle(head);
    removeCycle(head);
    printLL(head);
    return 0;
}