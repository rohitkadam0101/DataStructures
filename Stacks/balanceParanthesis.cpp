// To check for all types of parenthesis are balanced or not

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool balancedParanthesis(string s){
    stack<char> st;
    bool ans = false;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
            st.push(s[i]);
        }
        else{
            if(s[i]==')'){
                if(!st.empty() &&st.top()=='('){
                    st.pop();
                }
                else{
                    ans =false;
                    break;
                }
            }
            if(s[i]=='}'){
                if(!st.empty() && st.top()=='{'){
                    st.pop();
                }
                else{
                    ans =false;
                    break;
                }
            }
            if(s[i]==']'){
                if(!st.empty() && st.top()=='['){
                    st.pop();
                }
                else{
                    ans =false;
                    break;
                }
            }
        }
    }
    if(!st.empty()){
        return ans; // if still some opening brackets are present in stack it means parenthesis are not balanced
    }
    else{
        ans =true;
        return ans;
    }
}


int main(){
    string s = "[()]{}{[()()]()}";
    cout<<balancedParanthesis(s);
    return 0;
}