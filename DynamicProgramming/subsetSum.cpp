// Subset Sum Problem or subsequence
// Find the set of element from array whose sum equals k
// if there exist such pair return True else False
// Used bottom up DP approach
// This can be solved using recursion, dp, binary search and hashmap

#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

bool subsetSum(vector<int>a , int n, int sum){
    int dp[n+1][sum+1]; // i-> number of elements in array and j-> sum at that moment
    for(int i=0;i<=n;i++){
        dp[i][0] = true; // for sum zero we can take empty array
    }
    for(int i=1;i<=sum;i++){
        dp[0][i]  = false; // for array zero no solution is possible
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j<a[i-1]){ // if arr sum is greater than sum don't take it
                dp[i][j] = dp[i-1][j]; // take previous value
            }
            if(j>=a[i-1]){
                dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j]; //take or so include this or previous element that staties property
            }
        }
    }
    return dp[n][sum];
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