#include<bits/stdc++.h>
#define ll long long

using namespace std;
bool isValid(ll mid,vector<ll>& v,ll k){
    ll currAns = 0;
    ll currSum =0;
    for(ll i=0;i<v.size();i++){
        if(v[i]>mid)
            return false;
        if(currSum + v[i]>mid){
            currAns++;
            currSum=v[i];
        }
        else{
            currSum += v[i];
        }
        if(currAns>=k)
            return false;
    }
    return true;
}
int main(){
    ll n,k;cin>>n>>k;
    vector<ll> v(n);
    ll r=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        r += v[i];
    }
    ll l=0;
    ll ans = -1;
    while(r>=l){
        ll mid = l+(r-l)/2;
        if(isValid(mid,v,k)){
            // cout<<mid<<" is valid "<<endl;
            ans = mid;
            r=mid-1;
        }
        else{
            // cout<<mid<<" is not valid "<<endl;
            l=mid+1;
        }
    }
    cout<<ans<<endl;
}