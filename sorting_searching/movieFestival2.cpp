#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

bool comp(pair<ll,ll> p1,pair<ll,ll> p2){
    return p1.second<p2.second;
}
int main(){
    ll n,k;cin>>n>>k;
    vector<pair<ll,ll>> v(n);
    set<pair<ll,ll>> s; //to save end times,idx of the selected movie
    for(ll i=0;i<n;i++){
        ll a,b;cin>>a>>b;
        v[i] = {a,b};
    }
    sort(v.begin(),v.end(),comp); 


    ll ans = 0;
    ll currWorkers = 0;
    for(ll i=0;i<n;i++){
        //check if we can include ith movie
        ll st = v[i].first;
        if(s.empty()){
            currWorkers++;
            s.insert({v[i].second,i});
            ans++;
            continue;
        }
        auto lb = s.lower_bound(make_pair(st,LLONG_MIN));
        if(lb == s.begin()){
            if(lb->first == st){
                ans++;
                s.erase(lb);
                s.insert({v[i].second,i});
            }
            else if(currWorkers < k){
                currWorkers++;
                s.insert({v[i].second,i});
                ans++;
            }
            else
                continue; // the least ending time is greater than or eq to st
        }
        else{
            lb--;
            ans++;
            s.erase(lb);
            s.insert({v[i].second,i});
        }
    }
    cout<<ans<<endl;

}