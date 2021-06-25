#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

set<pair<ll,ll>> min_heap;
set<pair<ll,ll>,greater<pair<ll,ll>>> max_heap;

void resize_heaps(){
    ll s_min = min_heap.size();
    ll s_max = max_heap.size();
    if(abs(s_min-s_max)<=1)
        return;
    if(s_min>s_max){
        max_heap.insert(*min_heap.begin());
        min_heap.erase(min_heap.begin());
    }
    else{
        min_heap.insert(*max_heap.begin());
        max_heap.erase(max_heap.begin());
    }
}
ll getMedian(ll k){
    if(k%2==0){
        return (min_heap.begin()->first + max_heap.begin()->first)/2;
    }
    else{
        if(min_heap.size()>max_heap.size())
            return min_heap.begin()->first;
        return max_heap.begin()->first;
    }

}
int main(){
    min_heap.clear();
    max_heap.clear();
    ll n,k;cin>>n>>k;
    vector<ll> v(n);
    for(ll i=0;i<n;i++)
        cin>>v[i];
    ll i=0;
    for(;i<k;i++){
        if(max_heap.empty()){
            min_heap.insert({v[i],i});
        }
        else{
            if(v[i]>=max_heap.begin()->first){
                min_heap.insert({v[i],i});
            }
            else{
                max_heap.insert({v[i],i});
            }
        }
        resize_heaps();
    }
    vector<ll> ans;
    ll median = getMedian(k);
    ll currAns = 0;    
    for(ll j=i-1;j>=i-k;j--){
        currAns += abs(median - v[j]);
    }
    ans.pb(currAns);

    for(;i<n;i++){
        max_heap.erase({v[i-k],i-k});
        min_heap.erase({v[i-k],i-k});
        resize_heaps();

        if(max_heap.empty()){
            min_heap.insert({v[i],i});
        }
        else{
            if(v[i]>=max_heap.begin()->first){
                min_heap.insert({v[i],i});
            }
            else{
                max_heap.insert({v[i],i});
            }
        }
        resize_heaps();

        ll median = getMedian(k);
        ll currAns = 0;    
        for(ll j=i;j>i-k;j--){
            currAns += abs(median - v[j]);
        }
        ans.pb(currAns);
    }
    for(ll x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
}