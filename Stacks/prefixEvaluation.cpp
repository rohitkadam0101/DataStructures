// for infix traverse from right to left
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int prefixEvalution(string s){
    stack<char> st;
    for(int i=s.length()-1;i>=0;i--){ // R->L
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0'); // push ASCII valueS
        }
        else{ // opertor case
            int operand1 = st.top(); // for prefix take operand1 first
            st.pop();
            int operand2 = st.top();
            st.pop();
            switch(s[i]){
                case '+':
                st.push(operand1+operand2);
                break;
                case '-':
                st.push(operand1 - operand2);
                break;
                case '/':
                st.push(operand1 /operand2);
                break;
                case '*':
                st.push(operand1 * operand2);
                break;
                case '^':
                st.push(pow(operand1,operand2));
                break;

            }
        }
    }
    return st.top();
}
int main(){
    string s = "-+7*45+20";
    cout<<prefixEvalution(s);
    return 0;
}