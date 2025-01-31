#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
void solve(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int maxi[n];
    int ngi[n];
    int ans=INT_MIN;
    for(int i=n-1;i>=0;i--){
        if(i==n-1){
            maxi[i]=-1;  
        }
        ans=max(ans,a[i]);
        maxi[i]=ans;
      
    }


    // next greater element in the right side
    // in ngi we push element by one based index
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty()&&a[st.top()]<=a[i]){
            st.pop();
        }
        if(st.empty()){
            ngi[i]=n+1;
        }else{
            ngi[i]=st.top();
        }
        st.push(i);
       
         
    }
   
 
    int ans2=0;
    for(int i=0;i<n-1;i++){
        int index=ngi[i];
        int val=maxi[i];
        if(val!=-1&&index!=n+1){
            ans2=max(ans2,abs(val-a[index]));
        }

       
    }
    cout<<ans2<<endl;

    

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
  //  cin>>t;
    while(t--){
        solve();
    }
}