#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

bool isValid(ll mid,ll t,vector<ll>& v){
    ll numProds = 0;
    for(int i=0;i<v.size();i++){
        int currProd = mid/v[i];
        if(currProd == 0)
            break;
        numProds += currProd;
        if(numProds >= t)
            return true;
    }
    return false;
}
int main(){
    ll n,t;cin>>n>>t;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    ll l=0,r=t*v[0];
    ll ans = -1;
    while(l<=r){
        ll mid = l +(r-l)/2;
        if(isValid(mid,t,v)){
            r=mid-1;
            ans = mid;
        }
        else{
            l=mid+1;
        }
    }
    cout<<ans<<endl;
}