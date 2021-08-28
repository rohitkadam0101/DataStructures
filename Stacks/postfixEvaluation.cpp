// left to right
// first take operand 2 then operand 1
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int postfixEvalution(string s){
    stack<char> st;
    for(int i=0;i<s.length();i++){ // L->R
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0'); // push ASCII valueS
        }
        else{ // opertor case
            int operand2 = st.top(); // for postfix take operand2 first
            st.pop();
            int operand1 = st.top();
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
    string s = "46+2/5*7+";
    cout<<postfixEvalution(s);
    return 0;
}