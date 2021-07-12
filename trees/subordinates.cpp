#include<bits/stdc++.h>
#define pb push_back

using namespace std;

unordered_map<int,int> dp;

int getSub(int i,unordered_map<int,vector<int>>& umap){
    if(dp.find(i) != dp.end())
        return dp[i];
    int currAns = umap[i].size();
    for(int s:umap[i]){
        currAns += getSub(s,umap);
    }
    return dp[i] = currAns;
}
int main(){
    int n;cin>>n;
    unordered_map<int,vector<int>> umap;
    for(int i=1;i<=n;i++){
        umap[i] = {};
    }
    for(int i=2;i<=n;i++){
        int a;cin>>a;
        umap[a].pb(i);
    }

    vector<int> ans;
    for(int i=1;i<=n;i++){
        ans.pb(getSub(i,umap));
    }
    for(int a:ans)
        cout<<a<<" ";
    cout<<endl;
}