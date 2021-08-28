#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

bool subsetSum(vector<int> a, int n,int sum){
    if(n==0){
        return false;
    }
    if(sum==0){
        return true;
    }
    if(a[n-1]>sum){
        return subsetSum(a,n-1,sum); // dont include
    }
    return  subsetSum(a,n-1,sum)|| subsetSum(a,n-1,sum-a[n-1]);

}

int main(){
    vector<int> a;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    int sum;
    cin>>sum;
    cout<<subsetSum(a,n,sum);
}