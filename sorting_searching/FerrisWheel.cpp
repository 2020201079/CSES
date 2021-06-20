#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,x;cin>>n>>x;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int ans = 0;
    int l=0,r=n-1;
    while(l<r){
        if(v[l]+v[r] <= x){
            ans++;l++;r--;
        }
        else{
            ans++;
            r--;
        }
    }
    if(l==r)
        ans++;
    cout<<ans<<endl;
}