#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n;cin>>n;
    vector<pair<ll,ll>> v(n);
    for(ll i=0;i<n;i++){
        ll a,b;cin>>a>>b;
        v[i] = {a,b};
    }
    sort(v.begin(),v.end());
    ll reward = 0;
    ll penalty = 0;
    for(ll i=0;i<n;i++){
        reward += v[i].second;
        penalty += v[i].first*(n-i);
    }
    cout<<reward-penalty<<endl;
}