#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;cin>>n;
    int m = 1e9+7;
    vector<int> dp(n+1);
    for(int i=1;i<=n;i++){
        if(i<=6){
            dp[i] = 1;
        }
        for(int j=1;j<=6;j++){
            if(i-j>=1){
                dp[i] = (dp[i]+dp[i-j])%m;
            }
        }
    }
    cout<<dp[n]<<endl;
}