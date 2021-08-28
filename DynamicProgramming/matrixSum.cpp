// In the given matrix find the min sum of array to [o][o] to [n][m]
// Directions allowed to travel => right and down

#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;



int main(){
    int n;
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int dp[n][n];
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=a[0][i]; // first row
        dp[0][i] = sum;
    }
    sum = 0;
    for(int i=0;i<n;i++){ 
        sum+=a[i][0]; // first col
        dp[i][0] = sum;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            dp[i][j] = min(dp[i-1][j],dp[i][j-1])+a[i][j]; //Min of left and top + its own value
        }
    }
    cout<<dp[n-1][n-1];
}