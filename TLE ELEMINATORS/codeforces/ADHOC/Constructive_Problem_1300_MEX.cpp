#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n;
int arr[200200];
int mex(){
    set<int>st;
    for(int i=0;i<=n;i++){
        st.insert(i);
    }
    for(int i=0;i<n;i++){
        if(st.find(arr[i])!=st.end()){
            st.erase(arr[i]);
        }
    }
    return *st.begin();
}
void solve(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  } 
  int f_mex=mex();
  int s_mex=f_mex+1;
  int f_idx=n+1;
  int l_idx=0;
  for(int i=0;i<n;i++){
     if(arr[i]>f_mex){
        f_idx=min(f_idx,i);
        l_idx=max(l_idx,i);
     }
  }

 if (f_idx == n+1) {
    // There is no a[i] > f_mex — 
    // see if any 0 ≤ x < f_mex occurs at least twice:
    // koi bhi ek duplicate mila then we put on that elment to f_mex 
    vector<int> cnt(f_mex,0);
    for(int i=0;i<n;i++){
      if (arr[i] < f_mex) 
        cnt[arr[i]]++;
    }
    bool has_dup = false;
    for(int x=0;x<f_mex;x++){
      if (cnt[x] >= 2){ 
        has_dup = true;
         break; 
    }

    }
     if(has_dup){
        cout<<"Yes"<<endl;
      
     }else{
        cout<<"No"<<endl;
     }
     return ;
}

   for(int i=f_idx;i<=l_idx;i++){
        arr[i]=f_mex;
   }
  int ans= mex();
  if(ans==s_mex){
    cout<<"Yes"<<endl;
  
  }else{
     cout<<"No"<<endl;
  }
  


}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}