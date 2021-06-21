#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n;cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++)
        cin>>v[i];
    sort(v.begin(),v.end());
    ll median;
    if(n%2==0){
        median = (v[n/2]+v[(n-1)/2])/2;
    }
    else{
        median = v[n/2];
    }
    ll ans = 0;
    for(ll i=0;i<n;i++)
        ans += abs(median-v[i]);
    cout<<ans<<endl;
}