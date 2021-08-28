// Reverse the sentence
// How, are you => you are How,

# include<bits/stdc++.h>
using namespace std;

void reverseWord(string s){
    stack <string> s1;
    for(int i=0;i<s.length();i++){
        string word = "";
        while(s[i]!=' ' && i<s.size()){
            word+=s[i];
            i++;
        }
        s1.push(word);
    }
    while(!s1.empty()){
        cout<<s1.top()<<" ";
        s1.pop();
    }
    cout<<endl;
}

int main(){
    string s= "How, are you";
    reverseWord(s);
    return 0;
    
}