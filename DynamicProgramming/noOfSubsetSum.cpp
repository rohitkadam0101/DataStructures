// Count number of subsets sum with given sum

#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int noSubSetSum(vector<int>a,int n,int sum){
    int dp[n+1][sum+1];
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        dp[i][0] = 1; // null subset is possible for zero sum
    }
    for(int i=1;i<=sum;i++){
        dp[0][i] = 0; // if array size is zero no such subset is possible   
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(a[i-1]>j){
                // Dont include
                dp[i][j] = dp[i-1][j];
            }
            // include or not
            dp[i][j]  = dp[i-1][j-a[i-1]] + dp[i-1][j];
        }
    }
    return dp[n][sum];

}
int main(){
    vector<int>a;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    int sum;
    cin>>sum;
    cout<<noSubSetSum(a,n,sum);


}