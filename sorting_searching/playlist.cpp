#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    set<int> s;
    int i=0;
    int currAns = 0;
    int ans = INT_MIN;
    int l=0;
    while(i<n && s.find(v[i]) == s.end()){
        s.insert(v[i]);
        currAns++;i++;
        ans = max(ans,currAns);
    }
    if(i==n){
        cout<<ans<<endl;
        return 0;
    }
    //now i is pointing to the element which is already found
    while(i<n){
        while(l<i && s.find(v[i])!=s.end()){
            s.erase(v[l]);
            l++;
        }
        while(i<n && s.find(v[i]) == s.end()){
            s.insert(v[i]);
            currAns = i-l+1;
            i++;
            ans = max(ans,currAns);
        }
    }
    cout<<ans<<endl;
}