// 0-1 knapsack with the help of recursion

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int knapsack(int W,int wt[],int v[],int n){ // coming from right to left of array
// changing variables are w and n
    if(n==0 || W==0){
        return 0;
    }
    if(wt[n-1]<=W){ // include it or dont include it
        return max(v[n-1]+knapsack(W-wt[n-1],wt,v,n-1),knapsack(W,wt,v,n-1));
    }
    else{ // dont include
        return knapsack(W,wt,v,n-1);
    }
}
int main(){
    int wt[] =  { 10, 20, 30 };
    int v[] = {60,100,120};
    int W = 50;
    int n = sizeof(wt)/sizeof(wt[0]);
    cout<<knapsack(W,wt,v,n)<<endl;
    return 0;
}
