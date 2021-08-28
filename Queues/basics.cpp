// Implementation of queue using array FIFO
#include <iostream>
using namespace std;

#define n 20
class queue{
    int *a;
    int front;
    int rear;
    public:
    queue(){
        a = new int[n]; // Imlplementation with array so used array
        front = -1;
        rear = -1;
    }

    //push is done front
    void push(int val){
        if(rear ==n-1){
            cout<<"Queue is Full"<<endl;
            return;
        }
        rear++;
        a[rear] = val;
        if(front==-1){
            front++; //for first push
        }
    }
    void pop(){
        if(front==-1 || front>rear){
            cout<<"Queue is empty"<<endl;
            return;
        }
        front++;
    }
    int peek(){
        if(front==-1 || front>rear){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return a[front]; // peek is done on front element
    }
    bool empty(){
        if(front==-1 || front>rear){
            cout<<"Queue is empty"<<endl;
            return 1;
        }
        return 0;
    }
    void display(){
        int temp = front;
        while(temp!=rear+1){
            cout<<a[temp]<<" ";
            temp++;
        }
        cout<<endl;
    }
};
int main(){
    queue q;
    q.push(5);
    q.push(6);
    q.push(7);
    q.display();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.empty()<<endl;

    return 0;
}