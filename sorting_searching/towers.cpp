#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int h;cin>>h;
        if(v.size()==0)
            v.pb(h);
        else{
            auto lb = upper_bound(v.begin(),v.end(),h);
            if(lb == v.end()){
                v.pb(h);
            }
            else{
                int idx = lb-v.begin();
                v[idx] = h;
            }
        }
    }
    cout<<v.size()<<endl;
}