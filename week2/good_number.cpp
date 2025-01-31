#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000001];
int sum_l_r(int l,int r){
    if(l==0) return a[r];
    else return a[r]-a[l-1];
}
signed main(){
    int n,k,q;
    cin>>n>>k>>q;
    for(int i=0;i<1000001;i++){
        a[i]=0;
    }
    // using  the partial sum for range contribution technique
    while(n--){
        int l,r;
        cin>>l>>r;
        a[l]++;
        a[r+1]--;
    } 
    // making the prifix sum
    for(int i=1;i<1000001;i++){
        a[i]+=a[i-1];
    }
    // check number of student greater than k
    for(int i=0;i<1000001;i++){
        if(a[i]>=k){
            a[i]=1;
        }else{
            a[i]=0;
        }
        
            }
            // building the prefix sum for counting the number of student
       for(int i=1;i<1000001;i++){
         a[i]+=a[i-1];
       } 
       while(q--){
        int l,r;
        cin>>l>>r;
        cout<<sum_l_r(l,r)<<endl;
       }


}


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
int arr[1000002]={0};
int pre[1000002]={0};
void solve(){
    int n,k,q;
    cin>>n>>k>>q;
    while(n--){
        int l,r;
        cin>>l>>r;
        // frome here we finding the contribution by each range ofstudent 
        arr[l]++;
        arr[r+1]--;
    }
    for(int i=1;i<1000002;i++){
        pre[i]=arr[i]+pre[i-1];
    }
    for(int i=1;i<1000002;i++){
        if(pre[i]>=k){
            pre[i]=1;

        }else{
            pre[i]=0;        }
    }
    for(int i=1;i<1000002;i++){
           pre[i]=pre[i]+pre[i-1];
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        int ans=pre[r]-pre[l-1];
        cout<<ans<<endl;

    }



}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
  ///  cin>>t;
    while(t--){
        solve();
    }
}

