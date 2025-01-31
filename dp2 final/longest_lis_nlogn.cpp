// here we are finding the lis in nlogn and also printing the solution
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int arr[100100];
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int insertedat[n];
    vector<int>lis;
    for(int i=0;i<n;i++){
        if(lis.empty()||lis.back()<arr[i]){
            lis.push_back(arr[i]);
            insertedat[i]=lis.size();
        }else{
            auto it=lower_bound(lis.begin(),lis.end(),arr[i]);
            *it=arr[i];
            insertedat[i]=it-lis.begin()+1;
        }
    }
    // here lis give me the last element ending at that length
    vector<int>final_lis;
    int cur_len=lis.size();
    for(int i=n-1;i>=0;i--){
        if(insertedat[i]==cur_len){
            final_lis.push_back(arr[i]);
            cur_len--;
        }
    }
    reverse(final_lis.begin(),final_lis.end());
    for(auto v:final_lis){
        cout<<v<<" ";
    }
    cout<<endl;

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}