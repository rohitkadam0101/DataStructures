// This is bottom up dynamic programming approach for 0-1 knapsack

#include<iostream>
#include<bits/stdc++.h>


using namespace std;

int knapsack(int W, int wt[],int v[],int n){
    int dp[n+1][W+1]; //n*W matrix
    for(int i=0;i<=n;i++){
        for(int w=0;w<=W;w++){
            if(i==0||w==0){
                dp[i][w] = 0;
            }
            else if(wt[i-1]<=W){ // either include or don't include
                dp[i][w] = max(v[i-1]+dp[i-1][w-wt[i-1]],dp[i-1][w]); //either include that element or include previously included element i.e. w-wt[i-1]
            }
            else{
                dp[i][w] = dp[i-1][w];
            }

        }
    }
    return dp[n][W]; // final val will be in n*W position of our matrix
}

int main(){
    int wt[] =  { 10, 20, 30 };
    int v[] = {60,100,120};
    int W = 50;
    int n = sizeof(wt)/sizeof(wt[0]);
    // DP matrix intial row and col will be null as at W=0 and N=0 we will have no solution
    // initialize first row and col to zero
    cout<<knapsack(W,wt,v,n);
}