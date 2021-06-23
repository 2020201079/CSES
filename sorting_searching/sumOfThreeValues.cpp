#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n;cin>>n;
    ll target;cin>>target;
    vector<pair<ll,ll>> v(n); //value,idx
    for(ll i=0;i<n;i++){
        ll a;cin>>a;
        v[i] = {a,i};
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        ll num1 = v[i].first;
        ll currTarget = target-num1;
        ll l=i+1;
        ll r=n-1;
        while(l<r && l<n && r>=0){
            ll currSum = v[l].first+v[r].first;
            if(currSum == currTarget){
                cout<<v[i].second+1<<" "<<v[l].second+1<<" "<<v[r].second+1<<endl;
                return 0;
            }
            else if(currSum > currTarget)
                r--;
            else
                l++;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}