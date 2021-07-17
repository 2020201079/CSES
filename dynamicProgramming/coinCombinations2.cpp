#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long

int main(){
    ll n,x;cin>>n>>x;
    ll m = 1e9+7;
    vector<ll> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    // vector<vector<ll>> dp(n+1,vector<ll>(x+1,0));// do this just using two rows mem allocation problem
    vector<ll> prev(x+1,0);
    prev[0] = 1;
    vector<ll> curr(x+1,0);
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<=x;j++){
            if(j==0)
                curr[j] = 1;
            else{
                if(coins[i-1]<=j){
                    curr[j] = (curr[j-coins[i-1]] + prev[j])%m;
                }
                else{
                    curr[j] = prev[j];
                }
            }
        }
        prev = curr;
    }
    cout<<curr[x]<<endl;
    return 0;
}