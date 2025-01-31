#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
    int n;
    cin>>n;
    int arr[n];
    int min_index=0;
    int min_val=INT_MAX;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        min_val=min(min_val,arr[i]);
        if(min_val==arr[i]){
            min_index=i;
        }
    }
    int left_side_time=1;
    int left_index=min_index;
    int right_index=min_index;
    int right_side_time=1;
    while(left_index+1<n){
        if(arr[left_index+1]>arr[left_index]){
            left_side_time+=(left_side_time+1);
        }else if(arr[left_index+1]<arr[left_index]){
            left_side_time+=(left_side_time-1);
        }else{
            left_side_time+=left_side_time;
        }
        left_index++;
    }
    while(right_index-1>=0){
        if(arr[right_index-1]>arr[right_index]){
             right_side_time+=(right_side_time+1);
        }else if(arr[right_index-1]<arr[right_index]){
             right_side_time+=(right_side_time-1);
        }else{
            right_side_time+=right_side_time;
        }
        right_index--;
    }
    cout<<(right_side_time+left_side_time-1)<<endl;
     


}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    
}