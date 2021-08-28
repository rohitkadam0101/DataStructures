#include <bits/stdc++.h>
using namespace std;
int main(){
    stack <int> s;
    s.push(5);
    s.push(6);
    cout<<s.size()<<endl;
    s.pop();
    s.pop();
    cout<<s.empty()<<endl;
    return 0;
    
}