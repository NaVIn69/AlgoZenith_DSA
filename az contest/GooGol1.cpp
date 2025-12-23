#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int mod=1e9+7; 
int n,s,m;
int arr[100100];

struct monotone_deque{
  deque<int>dq;
  void insert(int x){
     while(!dq.empty()&&dq.back()>x){
        dq.pop_back();
     }
     dq.push_back(x);
  }
// erase
void erase(int x){
   if(dq.front()==x){
    dq.pop_front();
   }
}

// getmin value from deque
int getmin(){
  return dq.front();
}

};
vector<int> mini_ele(){
    vector<int>v;
    monotone_deque dq;
  for(int i=0;i<s;i++){
    dq.insert(arr[i]);
  }
  v.push_back(dq.getmin());

  // for any n-k subbarray
  for(int i=0;i<n-s;i++){
    dq.insert(arr[i+s]);
    dq.erase(arr[i]);
    v.push_back(dq.getmin());
  }
  return v;
  
}

bool check(vector<int>ans1,int mid){
// check(x) => can we make mini element of x by applying m opeartion of size of subarray s
// working on the first window
int cnt=0;
for(int i=0;i<ans1.size();i=i+s){
    if(ans1[i]<mid){
        int diff=mid-ans1[i];
        cnt+=diff;
    }
    
    if(cnt>m) return 0;

}
return cnt<=m;


}


int binary_expontiation(int a,int b,int mod){

  int ans=1;

  while(b>0){
  
  if(b%2){
    ans=((a%mod)*(ans%mod)) %mod;
  }
  a= ((a%mod)*(a%mod))%mod;
  b/=2;

  }
  return ans;
}
void solve(){
    cin>>n>>s>>m;
    int mini=INT_MAX;
    int maxi=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mini=min(mini,arr[i]);
        maxi=max(maxi,arr[i]);
    }
    if(m==0){
        cout<<mini<<endl;
        return;
    }
    vector<int>ans1=mini_ele();
    int s=mini;
    int e=maxi+m;
    int ans=mini;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(check(ans1,mid)){
            ans=mid;
            s=mid+1;
        }else{
            e=mid-1;
        }
    }
    cout<<ans<<endl;
    

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