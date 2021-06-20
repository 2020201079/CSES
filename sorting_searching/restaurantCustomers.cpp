#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;cin>>n;
    vector<int> arr(n);
    vector<int> lea(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];cin>>lea[i];
    }
    sort(arr.begin(),arr.end());
    sort(lea.begin(),lea.end());

    int i1=0,i2=0;
    int ans = INT_MIN;
    int currCust = 0;
    while(i1<n && i2<n){
        if(arr[i1]<lea[i2]){
            currCust++;
            i1++;
        }
        else{
            i2++;
            currCust--;
        }
        ans = max(ans,currCust);
    }
    cout<<ans<<endl;
}