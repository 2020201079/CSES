#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,t;cin>>n>>t;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        int a;cin>>a;
        v[i] = {a,i};
    }
    sort(v.begin(),v.end());
    int l=0,r=n-1;
    while(l<r){
        int currSum = v[l].first+v[r].first;
        if(currSum == t){
            cout<<v[l].second+1<<" "<<v[r].second+1<<endl;
            return 0;
        }
        else if(currSum>t){
            r--;
        }
        else{
            l++;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}