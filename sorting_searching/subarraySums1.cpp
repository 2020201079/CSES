#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n;cin>>n;
    ll target;cin>>target;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    ll ans = 0;
    ll l = 0;
    ll r = 0;
    ll currSum = v[l];
    while(r<n){
        // cout<<"l : "<<l<<" r : "<<r<<" "<<currSum<<endl;
        if(currSum == target){
            ans++;
            currSum -= v[l];
            l++;
        }
        else if(currSum < target){
            r++;
            if(r==n)
                break;
            currSum += v[r];
        }
        else{
            //currSum > 7 case
            currSum -= v[l];
            l++;
        }
    }
    cout<<ans<<endl;
}