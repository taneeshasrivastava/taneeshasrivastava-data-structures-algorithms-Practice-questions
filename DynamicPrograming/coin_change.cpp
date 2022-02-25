#include<iostream>
#include<vector>
#include<climits>
#include<bits/stdc++.h>
#define ll long long
using namespace std;


int  MinBottomDownNumberCoinChange(int m ,vector<int>  coins){
    vector<int> dp(m+1,0);
    dp[0]=0;
    for(int i=1 ;i<=m;i++){
        dp[i]=INT_MAX;
        for(int c: coins){
            if(i-c>=0 and dp[i-c]!=INT_MAX){
                dp[i]=min(dp[i],dp[i-c] +1);
            }
        }
    }
    return dp[m]==INT_MAX? -1 : dp[m];
}
ll minNumberTopDownofcoinsForchange( ll m, vector< int> denoms, vector< ll> &dp) {
    //base case
    if(m==0){
        return 0;
    }

    if(dp[m]!=0){
        return dp[m];
    }

    dp[m]=INT_MAX;
    for(int c:denoms){
        if(m-c>=0){
            dp[m]=min(dp[m],minNumberTopDownofcoinsForchange(m-c,denoms,dp));
        }
    }
    
    if(dp[m]!=INT_MAX){
        dp[m]=dp[m]+1;
    }
    
    return dp[m];
}


int main(){
    vector<int> coins={1,5,7,10};
    int m =8;
    cout<< MinBottomDownNumberCoinChange(m,coins)<<endl;

    int n=12;
    vector<int> v={1,2,5};
    vector<ll> dp(n+1,0);
    ll ans=minNumberTopDownofcoinsForchange(n,v,dp);
    if(ans==INT_MAX){
        cout<<"-1";
    }
    else{
        cout<<ans;
    }
    return 0;
}


