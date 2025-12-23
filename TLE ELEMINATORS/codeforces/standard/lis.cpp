#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

vector<int>lis(vector<int>&arr){
    vector<int>ans;
    ans.push_back(arr[0]);
    for(int i=1;i<arr.size();i++){
        if(arr[i]>ans.back()){
            ans.push_back(arr[i]);
        }else{
            int low=lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin();
            ans[low]=arr[i];
        }
    }
    return ans;
}
vector<int>longest_non_decreasing(vector<int>&arr){
    vector<int>ans;
    ans.push_back(arr[0]);
    for(int i=1;i<arr.size();i++){
        if(arr[i]>=ans.back()){
            ans.push_back(arr[i]);
        }else{
            int low=upper_bound(ans.begin(),ans.end(),arr[i])-ans.begin();
            ans[low]=arr[i];
        }
    }
    return ans;
}

// just -x
vector<int>longest_non_increasing(vector<int>&arr){
    vector<int>ans;
    ans.push_back(-arr[0]);
    for(int i=1;i<arr.size();i++){
        int y=-arr[i];
        if(y>=ans.back()){
            ans.push_back(y);
        }else{
            int low=upper_bound(ans.begin(),ans.end(),y)-ans.begin();
            ans[low]=y;
        }
    }
    return ans;
}
void solve(){

}
signed main(){
    solve();
}