#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
int arr[300300];

bool check(int mid){
    // can we make the array non decreasing int mid operation at most on one element 
    int left_min=1e9;
    int left_max=0;
    int right_mini=1e9;
    int right_max=0;

    int prev=0;

    for(int i=0;i<n;i++){
        if(arr[i]+mid>=m){
            left_min=0;
            left_max=(arr[i]+mid)%m;
            right_mini=arr[i];
            right_max=m-1;
        }else{
            left_min=-1;
            left_max=-1;
            right_mini=arr[i];
            right_max=arr[i]+mid;

        }
        // cout<<i<<" "<<left_min<<" "<<left_max<<" "<<right_mini<<" "<<right_max<<" ";
        if(left_min==-1&&left_max==-1){
            if(i==0){
                prev=right_mini;
             
            }else 
                 if(prev<=right_mini){
                prev=right_mini;
            }else if(prev>right_max){
                return false;
            }else{
                // same previous value we put
                
            }
           
        }else{
            if(i==0){
                prev=left_min;
            }else 
            if(prev>=left_min&&prev<=left_max){
                // same previous value we have to put
                
            }else if(prev>=right_mini&&prev<=right_max){
                // same previous value
                
            }else if(prev>right_max){
                // cout<<"false "<<prev<<" "<<right_max<<endl;
                return false;
            }else if(prev>left_max&&prev<right_mini){
                 prev=right_mini;
            }else if(prev<left_min){
                  prev=left_min;
            }

        }
        // cout<<prev<<endl;


    }
    //  cout<<endl;
    return true;
}
void solve(){

    cin>>n>>m;
 
    int tot=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
       
    }
    int l=0;
    int h=m;
    int ans=0;
    while(l<=h){
        int mid=l+(h-l)/2;
        // cout<<"mid"<<" "<<mid<<endl;
        if(check(mid)){
             ans=mid;
             h=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans<<endl;

}
signed main(){
    solve();
}