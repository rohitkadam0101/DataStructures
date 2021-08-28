#include<iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main(){
    int n;cin>>n;
    int k;cin>>k;
    vector <int> a(n);
    for(auto &i:a){
        cin>>i;
    }
    
    bool found = false;
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){ //fixing i
        int low = i+1;
        int hi = n-1;
        while(low<hi){
            int curr = a[i]+a[low]+a[hi];
            if(curr==k){
                found = true;
                break;
            }
            else if(curr<k){
                low++;
            }
            else{
                hi--;
            }
        }
    }
    if(found){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;

}