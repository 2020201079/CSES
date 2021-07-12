#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,t;cin>>n>>t;
    vector<int> coins(n);
    for(int i=0;i<n;i++)
        cin>>coins[i];
    vector<vector<int>> dp(n+1,vector<int>(t+1,INT_MAX));
    for(int i=1;i<=n;i++){
        for(int j=0;j<=t;j++){
            if(j==0){
                dp[i][j] = 0;
            }
            else{
                if(j-coins[i-1]>=0){
                    int include;
                    if(dp[i][j-coins[i-1]] == INT_MAX)
                        include = INT_MAX;
                    else
                        include = 1+dp[i][j-coins[i-1]];
                    int exclude = dp[i-1][j];
                    dp[i][j] = min(include,exclude);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    if(dp[n][t] == INT_MAX){
        cout<<-1<<endl;
    }
    else{
        cout<<dp[n][t]<<endl;
    }
    
}