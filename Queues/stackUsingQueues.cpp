// Expensive pop operation method
// using two stacks
#include <bits/stdc++.h>
using namespace std;

class stack1{
    queue <int> q1;
    queue <int> q2;
    int N;
    public:
        stack1(){
            N = 0;
        }
        void push(int val){
            q1.push(val); // push every new element in q1
            N++;
        }
        void pop(){
            if(q1.empty()){
                cout<<"Stack is empty"<<endl;
                return;

            }
            // copy all elements from q1 to q2 except the last element
            // this last element will be the top of stack
            while(q1.size()!=1){
                q2.push(q1.front());
                q1.pop();
            }
            q1.pop();
            // then copy all elements from q2 to q2
            queue<int> temp = q1;
            q1 = q2;
            q2 = temp;
            N--;
            
            
        }
        int size(){
            return N;
        }

        int peek(){
            if(q1.empty()){
                cout<<"Stack is empty"<<endl;
                return -1;

            }
            // copy all elements from q1 to q2 except the last element
            // this last element will be the top of stack
            while(q1.size()!=1){
                q2.push(q1.front());
                q1.pop();
            }
            int topele = q1.front();
            q2.push(topele);// push rem front ele from q1 to q2
            // then copy all elements from q2 to q2
            queue<int> temp = q1;
            q1 = q2;
            q2 = temp;
            return topele; // insteading of popping return that element
        }
};

int main(){
    stack1 st;
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    cout<<st.size()<<endl;

    return 0;
}