#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int main(){
    ll n,a,b;cin>>n>>a>>b;
    vector<ll> v(n);
    for(ll i=0;i<n;i++)
        cin>>v[i];
    vector<ll> pre(n);
    pre[0]=v[0];
    for(ll i=1;i<n;i++)
        pre[i] = pre[i-1] + v[i];
    set<pair<ll,ll>,greater<pair<ll,ll>>> s;
    
    for(ll i=a-1;i<b;i++)
        s.insert({pre[i],i});
    ll ans = s.begin()->first;
    
    for(ll i=1;i<n;i++){
        ll end = i+b-1;
        ll start = i+a-1;
        if(end<n && start <n){
            s.erase({pre[start-1],start-1});
            s.insert({pre[end],end});
            ans = max(ans,s.begin()->first-pre[i-1]);
        }
        else if(end>=n && start<n){
            s.erase({pre[start-1],start-1});
            ans = max(ans,s.begin()->first-pre[i-1]);
        }
        else{
            break;
        }
        
    }
    cout<<ans<<endl;
}