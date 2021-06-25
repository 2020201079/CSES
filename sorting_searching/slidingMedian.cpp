#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;


set<pair<ll,ll>> min_heap; // value -> idx
set<pair<ll,ll>,greater<pair<ll,ll>>> max_heap; // value ->idx

void resize_heaps(){
    ll size_min = min_heap.size();
    ll size_max = max_heap.size();
    if(abs(size_min-size_max)<=1)
        return;
    if(size_min > size_max){
        max_heap.insert(*min_heap.begin());
        min_heap.erase(min_heap.begin());
    }
    else{
        min_heap.insert(*max_heap.begin());
        max_heap.erase(max_heap.begin());
    }
}

int main(){
    ll n,k;cin>>n>>k;
    vector<ll> v(n);
    for(ll i=0;i<n;i++)
        cin>>v[i];


    for(int i=0;i<k;i++){
        if(max_heap.empty()){
            min_heap.insert({v[i],i});
        }
        else{
            if(v[i] >= max_heap.begin()->first){
                min_heap.insert({v[i],i});
            }
            else{
                max_heap.insert({v[i],i});
            }
        }
        resize_heaps();
    }

    vector<ll> ans;
    if(k%2==1){
        if(max_heap.size()>min_heap.size())
            ans.pb(max_heap.begin()->first);
        else{
            ans.pb(min_heap.begin()->first);
        }
    }
    else{
        ans.pb(max_heap.begin()->first);
    }

    for(int i=k;i<n;i++){
        //remove the i-k element
        min_heap.erase({v[i-k],i-k});
        max_heap.erase({v[i-k],i-k});
        resize_heaps();
        
        if(max_heap.empty()){
            min_heap.insert({v[i],i});
        }
        else{
            if(v[i] >= max_heap.begin()->first){
                min_heap.insert({v[i],i});
            }
            else{
                max_heap.insert({v[i],i});
            }
        }
        resize_heaps();
        if(k%2==1){
            if(max_heap.size()>min_heap.size())
                ans.pb(max_heap.begin()->first);
            else{
                ans.pb(min_heap.begin()->first);
            }
        }
        else{
            ans.pb(max_heap.begin()->first);
        }
    }
    for(auto x:ans)
        cout<<x<<" ";
    cout<<endl;
}