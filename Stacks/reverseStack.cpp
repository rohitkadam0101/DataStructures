// Reverse stack 1)By using 2 stacks 2) by using recursive calls

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void pushBottom(stack <int> &s,int topele){
    if(s.empty()){
        s.push(topele); // push the element from reverse function to top
        return;
    }
    int top1 = s.top();
    s.pop();
    pushBottom(s,topele);
    s.push(top1);
}
void reverse(stack <int> &s){
    if(s.empty()){
        return;
    }
    int topele = s.top();
    s.pop();
    reverse(s); // move further till stack is empty
    pushBottom(s,topele); // push topelem returned from bottom 6,5,4,3,1 case 1 will go to bottom fuction first
}
void display(stack <int> &s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
int main(){
    stack <int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    reverse(s);
     display(s);
    return 0;
}