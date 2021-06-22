#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    if(v[0] != 1){
        cout<<1<<endl;
        return 0;
    }
    ll currAns = 1;
    for(int i=1;i<n;i++){
        if(v[i]<=currAns+1){
            currAns += v[i]; 
        }
        else{
            cout<<currAns+1<<endl;
            return 0;
        }
    }
    cout<<currAns+1<<endl;
    return 0;
}