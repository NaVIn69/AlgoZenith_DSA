#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
     int n,m;
     cin>>n>>m;
     int arr[n],brr[m];
     for(int i=0;i<n;i++){
        cin>>arr[i];
     }
     for(int i=0;i<m;i++){
        cin>>brr[i];
     }
    /* first we finding the common element,we have been store the common element in vector and map */
    unordered_map<int,int>mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]=i;
    }
    vector<int>temp;
    for(int i=0;i<m;i++){
        if(mpp.find(brr[i])!=mpp.end()){
            temp.push_back(mpp[brr[i]]);
        }
    }
    vector<int>lcs;
    lcs.push_back(temp[0]);
    for(int i=1;i<temp.size();i++){
        if(temp[i]>lcs.back()){
            lcs.push_back(temp[i]);
        }else if(temp[i]<lcs[0]){
            lcs[0]=temp[i];
        }else{
            cout<<"k";
            auto it=lower_bound(lcs.begin(),lcs.end(),temp[i]);
            *it=temp[i];
        }
    }
    for(auto v:lcs){
        cout<<v<<" ";
        // cout<<arr[lcs-1]
    }
    cout<<lcs.size()<<" ";
}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}