// #include<bits/stdc++.h>
// using namespace std;

// void solve(){
//     int n,m,k,ta,tb;
//     cin>>n>>m>>ta>>tb>>k;
//     int arr[n],brr[m];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     for(int i=0;i<m;i++){
//         cin>>brr[i];
//     }
//     if(k>=n||k>=m){
//         cout<<"-1"<<endl;
//         return ;
//     }
//     sort(arr,arr+n);
//     sort(brr,brr+m);
//     int maxi=0;
//     for(int i=0;i<=k;i++){
//         int a_skip=i;
//         int b_skip=k-i;


//         // cout<<"order of delete "<<a_skip<<" "<<b_skip<<endl;
//         int departure_a=arr[a_skip]+ta;
//         // cout<<"departure_a "<<departure_a<<endl;
//         int arrive_b=lower_bound(brr,brr+m,departure_a)-brr; // here we get the flight in b which is just greater than deaprture of a
//         //  cout<<"arrive_b "<<arrive_b<<endl;
//         if(arrive_b==m){
//             cout<<"-1"<<endl;
//             return;
//         }
//         // cout<<"arrive_b +b_skip "<<arrive_b+b_skip<<endl;
//         if(arrive_b+b_skip>=m){
//             cout<<"-1"<<endl;
//             return ;
//         }
//         int departure_b=brr[arrive_b+b_skip]+tb;
//         // cout<<"departure_b "<<departure_b<<endl;
//         maxi=max(maxi,departure_b);
//         // cout<<"maxi "<<maxi<<endl;
//         // cout<<endl;
//         }
    
//     cout<<maxi<<endl;

// }
// signed main(){
//     solve();
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
 int a,b,c,d;
 cin>>a>>b>>c>>d;
 int maxi=max(a,b);
 int mini=min(a,b);
 if((((maxi+1)/2)-1)>mini){
    cout<<"NO"<<endl;
    return ;
 }
 maxi=max(c-a,d-b);
 mini=min(c-a,d-b);
 if((((maxi+1)/2)-1)>mini){
    cout<<"NO"<<endl;
    return ;
 }
 cout<<"YES"<<endl;
}
signed main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}