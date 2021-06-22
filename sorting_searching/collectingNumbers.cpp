#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    unordered_map<int,int> umap;//value,idx
    for(int i=0;i<n;i++)
        umap[v[i]] = i;
    
    int ans = 0;
    for(int i=0;i<n;i++){
        int nextNum = v[i]+1;
        if(umap.find(nextNum)==umap.end())
            continue;
        if(umap[nextNum]<i)
            ans++;
    }
    cout<<ans+1<<endl;
}