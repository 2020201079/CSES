#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll x,n;cin>>x>>n;
    map<ll,ll> m; //interval - count
    set<ll> pos; // positions of street lights
    pos.insert(0);
    pos.insert(x);
    m[x]++;
    for(ll i=0;i<n;i++){
        ll a;cin>>a;
        auto lb = pos.lower_bound(a); // iterator to just next light 
        ll nextLight = *lb;
        ll prevLight = *(--lb);
        // cout<<"Insert at : "<<a<<" next l : "<<nextLight<<" prev l : "<<prevLight<<endl;
        ll dist = nextLight-prevLight;
        m[dist]--;
        if(m[dist]<=0)
            m.erase(dist);
        pos.insert(a);
        ll dist1 = a-prevLight;
        ll dist2 = nextLight-a;
        m[dist1]++;m[dist2]++;
        cout<<(m.rbegin())->first<<endl;
    }
}