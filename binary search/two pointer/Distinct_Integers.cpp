#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
int n;
int arr[1000005];
int freq[1000005];
int subaarray(int k){
 int head=-1,tail=0;

    // take data structure to maintain the window proprety
    unordered_map<int,int>mpp;
    int dist=0;

    // store to the ans
    int ans=0;
    while(tail<n){
        // eat as many as possible 
        while(head+1<n && (freq[arr[head+1]]!=0||dist<k)){
          
            if(freq[arr[head+1]]==0) dist++;
            freq[arr[head+1]]++;
            head++;
        }
        // store the ans for that tail
       int len=head-tail+1;
       ans+=len;
        // move the tail one step forward
        if(tail<=head){
            freq[arr[tail]]--;
            if(freq[arr[tail]]==0){
                  dist--;
               
            }
            tail++;
        }else{
            tail++;
            head=tail-1;
        }
    }
   return ans;
}
void solve(){
    int k;
    cin>>n>>k;
  //  int arr[n];
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   
  cout<<subaarray(k)-subaarray(k-1)<<endl;

  
  
  
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