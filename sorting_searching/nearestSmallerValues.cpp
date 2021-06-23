#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n;cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    vector<ll> ans;
    stack<pair<ll,ll>> stk; // value,idx
    for(int i=0;i<n;i++){        
        while(!stk.empty() && stk.top().first>=v[i]){
            stk.pop();
        }
        if(stk.empty()){
            ans.push_back(0);
            stk.push({v[i],i+1});
        }
        else{
            ans.push_back(stk.top().second);
            stk.push({v[i],i+1});
        }
    }
    for(auto l:ans)
        cout<<l<<" ";
    cout<<endl;
}