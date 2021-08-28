// Queue using stack (Two Stack method)
// push in stack1
#include <bits/stdc++.h>
using namespace std;

class queue1{
    stack <int>s1;
    stack <int> s2;
    public:
        void push(int val){
            s1.push(val); // always push in stack1
        }
        int pop(){
            if(s1.empty() && s2.empty()){
                cout<<"Queue is Empty"<<endl;
                return -1;
            }
            if(s2.empty()){ // if s2 is empty transfer all elements from s1 to s2 i.e. they will become reverse and keep popping first element from s2
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            int topelement  = s2.top();
            s2.pop(); // pop topmost element of s2
            return topelement;
        }
        bool empty(){
            if(s1.empty() && s2.empty()){
                cout<<"Queue is full"<<endl;
                return 1;
            }
            return 0;
        }

};
int main(){
    queue1 q;
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.empty()<<endl;
}