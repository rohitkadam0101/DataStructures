// Memoisation technique to keep in memory about previous recursive calls

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int knapsack(int W,int wt[],int v[],int n,int **dp){ // coming from right to left of array
// changing variables are w and n
    if(n==0 || W==0){
        return 0;
    }
    if(dp[n][W]!=-1){
        return dp[n][W]; // if already we have ans
    }
    if(wt[n]<=W){ // include it or dont include it
        dp[n][W] = max(v[n]+knapsack(W-wt[n],wt,v,n-1,dp),knapsack(W,wt,v,n-1,dp));
        return dp[n][W];
    }
    else{ // dont include
        return dp[n][W] = knapsack(W,wt,v,n-1,dp);
    }
}
int main(){
    int wt[] =  { 10, 20, 30 };
    int v[] = {60,100,120};
    int W = 50;
    int n = sizeof(wt)/sizeof(wt[0]);
    int **dp = new int*[n]; // dp matrix of size[n][w];
    for(int i=0;i<n;i++){
        dp[i] = new int[W+1];
    }
    // initializing dp matrix to -1
    for(int i=0;i<n;i++){
        for(int j=0;j<W+1;j++){
            dp[i][j] = -1;
        }
    }
    
    cout<<knapsack(W,wt,v,n-1,dp)<<endl;
    return 0;
}