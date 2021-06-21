#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    vector<ll> dp(n);
    dp[0] = v[0];
    for(int i=1;i<n;i++){
        dp[i] = max(v[i],dp[i-1]+v[i]);
    }
    ll ans = LLONG_MIN;
    for(int i=0;i<n;i++)
        ans = max(ans,dp[i]);
    cout<<ans<<endl;
}