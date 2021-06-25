#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n;cin>>n;
    ll k;cin>>k;
    vector<ll> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    map<ll,ll> m; // value -> count
    ll j=0;
    ll ans = 0;
    for(ll i=0;i<n;i++){
        while(j<n && (m.size()<k || m.count(v[j]))){
            m[v[j]]++;
            j++;
        }
        // j is pointing to next of last included
        ans += j-i;
        m[v[i]]--;
        if(m[v[i]]==0)
            m.erase(v[i]);
    }
    cout<<ans<<endl;
}
