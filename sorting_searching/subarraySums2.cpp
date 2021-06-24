#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n,target;cin>>n>>target;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<ll> pre(n);
    pre[0] = v[0];
    for(ll i=1;i<n;i++){
        pre[i] = pre[i-1]+v[i];
    }

    map<ll,ll> m; // contains all the sums until now
    m[0]++; //initialize a zero sum
    ll ans = 0;
    for(ll i=0;i<n;i++){
        ll currSum = pre[i];
        ll prevNeeded = currSum-target;
        if(m.find(prevNeeded) != m.end()){
            ans += m[prevNeeded];
        }
        m[currSum]++;
    }
    cout<<ans<<endl;
}