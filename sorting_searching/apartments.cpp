#include<bits/stdc++.h>

using namespace std;

bool isValid(int a,int b,int k){
    if(abs(a-b)<=k)
        return true;
    return false;
}
int main(){
    int n,m,k;cin>>n>>m>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    vector<int> b(m);
    for(int i=0;i<m;i++)
        cin>>b[i];
    
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int i_a=0,i_b=0;
    int ans = 0;
    while(i_a<n && i_b<m){
        if(isValid(a[i_a],b[i_b],k)){
            i_a++;
            i_b++;
            ans++;
        }
        else if(a[i_a]>b[i_b]){
            i_b++;
        }
        else
            i_a++;
    }
    cout<<ans<<endl;
}