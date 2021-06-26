#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

void josephus(vector<int> v,vector<int>& ans){
    if(v.size()==0)
        return;
    if(v.size() == 1){
        ans.pb(v[0]);
        return;
    }
    int n = v.size();
    if(n%2 == 0){
        vector<int> nextv;
        for(int i=1;i<n;i=i+2){
            ans.pb(v[i]);
        }
        for(int i=0;i<n;i=i+2)
            nextv.pb(v[i]);
        josephus(nextv,ans);
    }
    else{
        vector<int> nextv;
        for(int i=1;i<n;i=i+2){
            ans.pb(v[i]);
        }
        nextv.pb(v[n-1]);
        for(int i=0;i<n-1;i=i+2)
            nextv.pb(v[i]);
        josephus(nextv,ans);
    }
}
int main(){
    int n;cin>>n;
    vector<int> v;
    for(int i=1;i<=n;i++){
        v.pb(i);
    }
    vector<int> ans;
    josephus(v,ans);
    for(int x:ans)
        cout<<x<<" ";
    
}