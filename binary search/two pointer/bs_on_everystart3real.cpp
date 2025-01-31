  // here we are finding the number of subarray where we can do the <=k flips to make all ones
  #include<bits/stdc++.h>
  using namespace std;
  #define int long long
  #define endl "\n"
  int mod=1e9+7;
  int n,k;
  int a[100100];
  int pre[100100];
  int numzero(int l,int r){
    return (r-l+1)-(pre[r]-(l>0?pre[l-1]:0));

  }

  bool check(int st,int mid){
    return numzero(st,mid)<=k;

  }
  void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        pre[i]=a[i];
        if(i) pre[i]+=pre[i-1];
    }
    int total_sub=0;
    for(int st=0;st<n;st++){
        int l=st;
        int h=n-1;
        int ans=st-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(check(st,mid)){
                ans=mid;
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        total_sub+=(ans-st+1);
    }
    cout<<total_sub<<endl;

  }
  signed main(){
    int t=1;
    while(t--){
    solve();
    }
  }