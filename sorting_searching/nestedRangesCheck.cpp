#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

bool comp(pair<pair<ll,ll>,ll> a1,pair<pair<ll,ll>,ll> b1){
    auto a = a1.first;
    auto b = b1.first;
    if(a.first == b.first){
        return a.second>b.second;
    }
    else{
        return a.first<b.first;
    }
}
int main(){
    ll n;cin>>n;
    vector<pair<pair<ll,ll>,ll>> v(n);
    vector<bool> contained(n,false);
    vector<bool> contains(n,false);
    for(ll i=0;i<n;i++){
        ll a,b;cin>>a>>b;
        v[i] = {{a,b},i};
    }
    sort(v.begin(),v.end(),comp); // sort inc start if equ dec end

    //figure out contained 
    ll maxRight = LLONG_MIN;
    for(auto interval:v){
        ll start = interval.first.first;
        ll end = interval.first.second;
        ll idx = interval.second;
        if(end<=maxRight){
            contained[idx] = true;
        }
        maxRight = max(maxRight,end);
    }

    //figure out contains
    ll minRight = LLONG_MAX;
    for(int i=v.size()-1;i>=0;i--){
        ll start = v[i].first.first;
        ll end = v[i].first.second;
        ll idx = v[i].second;
        if(end>=minRight){
            contains[idx] = true;
        }
        minRight = min(minRight,end);
    }
    for(auto b:contains)
        cout<<b<<" ";
    cout<<endl;
    for(auto b:contained)
        cout<<b<<" ";
    cout<<endl;
}