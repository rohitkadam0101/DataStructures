// Given an array return true if we can split array into two parts such that sum of both subarrays is equal
// sum = array sum
// if sum is even this means we can divide it into 2 parts i.e. s+s=2s but we cannot divide odd sum into two equal parts
// We are not allowing float numbers in array so not possible to make equal partitions for 21 also
// find for sum/2 subset in array if it is present then other will also be present

// Try to draw dp matrix manually

#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

bool isSubsetSum(vector<int>a, int n, int sum){
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        dp[i][0] = true;
    }
    for(int i=1;i<=sum;i++){
        dp[0][i] = false;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){ // Start this with zero for below logic
            if(a[i-1]>sum){  // Try for a[i]>sum
                dp[i][j] = dp[i-1][j]; // dp[i][j] =  dp[i-1][j]
            }
            dp[i][j]  = dp[i-1][j-a[i-1]] || dp[i-1][j]; //dp[i][j]  = dp[i-1][j-a[i]] || dp[i-1][j]
        }
    }
    return dp[n][sum];
}

bool equalPartition(vector<int> a, int n){
    int sum1 =0 ;
    for(int i=0;i<n;i++){
        sum1+=a[i];
    }
    if(sum1%2!=0){
        return false;
    }
    else{
        return isSubsetSum(a,n,sum1/2); //Subset sum problem recursive approach can be used for this
    }
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
    cout<<equalPartition(a,n);
}
