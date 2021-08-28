#include <iostream>
using namespace std;

// Stack using array

#define n 100

class Stack{  // everything inside the class unlike LL array and top will be private
    int *a; // array
    int top;
    public:
    Stack(){ // constructor
        a = new int[n]; // dynamically creating stack
        top =-1;
    }

    void push(int val){
        if(top==n-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        cout<<val<<" pushed into stack "<<endl;
        top++;
        a[top] = val;
    }

    void pop(){
        if(top==-1){
            cout<<"Stack underflow"<<endl;
            return;
        }
        cout<<a[top]<<" popped from stack "<<endl;
        top--;
    }
    int topmost(){
        if(top==-1){
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        return a[top];
    }
    int isEmpty(){
        return top == -1;
    }
    void display(){
        while(!isEmpty()){
            cout<<a[top]<<" ";
            top--;
        }
    }

};
int main(){
    Stack s; // by default calls constructor and makes new array of size n and sets top=-1
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    // s.pop();
    // cout<<s.isEmpty()<<endl;
    // cout<<"top element: "<<s.topmost()<<" "<<endl;
    // s.pop();
    // s.pop();
    // s.pop();
    // cout<<s.isEmpty();
    s.display();
    return 0;

}