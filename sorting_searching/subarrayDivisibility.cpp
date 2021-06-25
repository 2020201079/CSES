#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n;cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    vector<ll> pre(n);
    pre[0] = v[0];
    for(int i=1;i<n;i++)
        pre[i] = pre[i-1] + v[i];
    unordered_map<ll,ll> umap; //rem -> count
    umap[0]++; // initialize a zero remainder
    ll ans = 0;
    for(ll i=0;i<n;i++){
        ll currRem = pre[i]%n;
        if(currRem < 0)
            currRem += n;
        if(umap.find(currRem) != umap.end()){
            ans += umap[currRem];
        }
        umap[currRem]++;
    }
    cout<<ans<<endl;
}