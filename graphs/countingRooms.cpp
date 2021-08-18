#include<bits/stdc++.h>

using namespace std;

vector<vector<char>> graph;
vector<vector<bool>> visited;
vector<int> di ={0,0,1,-1};
vector<int> dj ={1,-1,0,0};

bool isValid(int r,int c){
    int n=graph.size();
    int m = graph[0].size();
    if(r<0 || r>= n || c<0 || c>= m)
        return false;
    if(graph[r][c] != '.' || visited[r][c] == true)
        return false;
    return true;
}
void dfs(int row,int col){
    visited[row][col] = true;
    for(int k=0;k<=3;k++){
        int n_row = row + di[k];
        int n_col = col + dj[k];
        if(isValid(n_row,n_col)){
            dfs(n_row,n_col);
        }
    }
}
int main(){
    int n,m;cin>>n>>m;
    graph.clear(),visited.clear();
    graph.resize(n,vector<char>(m));
    visited.resize(n,vector<bool>(m,false));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>graph[i][j];
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j] == '.' && visited[i][j] == false){
                ans++;
                dfs(i,j);
            }
        }
    }
    cout<<ans<<endl;

}