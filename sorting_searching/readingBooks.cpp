#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n;cin>>n;
    ll sum = 0;
    ll m = LLONG_MIN;
    for(ll i=0;i<n;i++){
        ll a;cin>>a;
        sum += a;
        m = max(a,m);
    }
    cout<<max(sum,2*m)<<endl;
    return 0;
}