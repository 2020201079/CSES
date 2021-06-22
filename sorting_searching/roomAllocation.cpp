#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

int main(){
    ll n;cin>>n;
    vector<pair<ll,pair<char,ll>>> v; // time , a or d , idx
    for(ll i=0;i<n;i++){
        ll a,d;cin>>a>>d;
        v.pb({a,{'a',i}});v.pb({d,{'d',i}});
    }
    sort(v.begin(),v.end());
    map<ll,ll> umap; //idx->roomno
    stack<int> stk;
    int room_nums = 0;
    for(int i=0;i<v.size();i++){
        if(v[i].second.first == 'a'){
            if(stk.empty()){
                room_nums++;
                umap[v[i].second.second] = room_nums;
            }
            else{
                int roomNo = stk.top();
                stk.pop();
                umap[v[i].second.second] = roomNo;
            }
        }
        else{
            int idx = v[i].second.second;
            stk.push(umap[idx]);
        }
    }
    cout<<room_nums<<endl;
    for(auto x:umap)
        cout<<x.second<<" ";
    cout<<endl;
}