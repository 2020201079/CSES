#include<bits/stdc++.h>

using namespace std;
vector<vector<int>> graph;
vector<int> f;
vector<int> g;

void dfs(int root,int parent){
    for(int child: graph[root]){
        if(child == parent)
            continue;
        dfs(child,root);
        f[root] = max(f[child]+1,f[root]);
    }
}

void dfs1(int root,int parent){
    vector<int> child_f;
    for(int child: graph[root]){
        if(child == parent)
            continue;
        dfs1(child,root);
        child_f.push_back(f[child]);
    }
    if(child_f.size()>=2){
        sort(child_f.begin(),child_f.end(),greater<int>());
        g[root] = child_f[0]+child_f[1]+2;
    }
}

int main(){
    int n;cin>>n;
    graph.clear();graph.resize(n+1);
    f.clear();f.resize(n+1,0);
    g.clear();g.resize(n+1,0);
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1,-1);
    dfs1(1,-1);
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max({f[i],g[i],ans});
    }
    cout<<ans<<endl;
}