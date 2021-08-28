// Queue implementation using linked list
// Insertion at end
// deletion and access at head
#include <iostream>
using namespace std;
#define N 20 // for size we can keep n variable
class node{
    public:
        int data;
        node *next;
        node(int val){
            data = val;
            next = NULL;
        }
};
class queue{
    node *front;
    node *rear;
    public:
        queue(){
        front =NULL;
        rear = NULL;
        }
        void push(int val){
            node *n = new node(val);
            if(front ==NULL){  //Intially when queue is empty
                front = n;
                rear = n;
                return;
            }
            rear->next = n;
            rear = n;
            
        }
        void pop(){
            if(front==NULL){
                cout<<"Queue is empty "<<endl;
                return;
            }
            node *todelete = front;
            front = front->next;
            delete todelete;
        }

        int peek(){
            if(front==NULL){
                cout<<"Queue is empty "<<endl;
                return -1;
            }
            return front->data;
        }
        bool empty(){
            if(front==NULL){
                return 1;
            }
            else{
                return 0;
            }
        }
        void display(){
            node *temp = front;
            while(temp!=rear->next){
                cout<<temp->data<<" "<<endl;
                temp = temp->next;
            }
            cout<<endl;
        }
};
int main(){
    queue q;
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.display();
    q.pop();
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.empty();

    return 0;
}