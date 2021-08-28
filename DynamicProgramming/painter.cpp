#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool comp(pair<int,int>a,pair<int,int>b){
    if(a.second==b.second){
        return a.first>b.first;
    }
    return a.second<b.second;
}

int main(){
    int v;
    cin>>v;
    vector<pair<int,int>>p;
    for(int i=1;i<=9;i++){
        int k;
        cin>>k;
        p.push_back(make_pair(i,k));
    }
    // for(auto it:p){
    //     cout<<it.first<<" "<<it.second;
    //     cout<<endl;
    // }
     sort(p.begin(),p.end(),comp);
    // cout<<"After Sorting"<<endl;
    // for(auto it:p){
    //     cout<<it.first<<" "<<it.second;
    //     cout<<endl;
    // }
    vector<int> ans;
    int currV = v;
    for(int i=0;i<9;i++){
        while(p[i].second<=currV){
            currV -= p[i].second;
            ans.push_back(p[i].first);
        }
    }
    if(ans.empty()){
        cout<<-1<<endl;
    }
    else{
        for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    }
    
    return 0;
}