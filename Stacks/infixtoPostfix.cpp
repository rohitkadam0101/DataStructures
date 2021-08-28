// Infix to postfix

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int prec(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else{
        return -1; // for brackets
    }
}

string infixToPostfix(string s){
    stack <char>st;
    string res;
    for(int i=0;i<s.length();i++){
        char c = s[i];
        if((c>='a' && c<='z')|| (c>='A' && c<='Z')){
            res+=c; // 1.append operands into result
        }
        else if(c=='('){
            st.push('('); // 2.push opening bracket
        }
        else if(c==')'){
            while(!st.empty() && st.top()!='('){ // 3.pop until closing bracket is found
                char temp = st.top();
                st.pop();
                res += temp;
                

            }
            st.pop(); //empty bracket at last
        }
        else{
            while(!st.empty() && prec(s[i]) <= prec(st.top())){ //4.pop and add if we encounter precence of s[i]<st.top()
                char temp = st.top();
                st.pop();
                res += temp;
            }
            st.push(c); // push the s[i] operator
        }
    }
    while(!st.empty()){
                char temp = st.top();
                st.pop();
                res += temp;
        }
    return res;

}

int main(){
    string s = "x+y*z/w+u";
    cout<<infixToPostfix(s)<<endl;
    return 0;
}