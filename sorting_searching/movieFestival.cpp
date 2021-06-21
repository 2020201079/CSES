#include<bits/stdc++.h>

using namespace std;

bool comp(pair<int,int>p1,pair<int,int> p2){
    return p1.second<p2.second;
}
int main(){
    int n;cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        int s,e;cin>>s>>e;
        v[i] = {s,e}; //need to sort based on e,s 
    }
    sort(v.begin(),v.end(),comp);
    vector<int> dp(n,0);
    dp[0] = 1;
    for(int i=1;i<n;i++){
        int prev = 0;//should do a binary search here.
        int l=0,r=i-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(v[mid].second <= v[i].first){
                prev = dp[mid];
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        dp[i] = max(prev+1,dp[i-1]);
    }
    cout<<dp[n-1]<<endl;
}