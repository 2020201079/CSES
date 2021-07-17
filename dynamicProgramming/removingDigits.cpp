#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long

vector<int> dp;

vector<int> getDigits(int n){
    vector<int> ans;
    while(n){
        ans.pb(n%10);
        n = n/10;
    }
    return ans;
}
int  f(int n){
    // cout<<n<<endl;
    if(n<=9)
        return 1;
    if(dp[n] != -1)
        return dp[n];
    vector<int> digits = getDigits(n);
    int ans = INT_MAX;
    for(int d:digits){
        if(d==0)
            continue;
        ans = min(ans,1+f(n-d));
    }
    return dp[n]=ans;
}
int main(){
    int n;cin>>n;
    dp.clear();
    dp.resize(n+1,-1);
    cout<<f(n)<<endl;
}